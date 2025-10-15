#include "tinyusb_cdc.h"

app_message_t g_msg_recv;

static const char *TAG = "tinyusb_cdc";
static bool s_initialized = false;
static uint8_t rx_buf[CONFIG_TINYUSB_CDC_RX_BUFSIZE + 1];

/**
 * @brief Application Queue
 */
static QueueHandle_t app_queue;

/**
 * @brief CDC device RX callback
 *
 * CDC device signals, that new data were received
 *
 * @param[in] itf   CDC device index
 * @param[in] event CDC event type
 */
void tinyusb_cdc_rx_callback(int itf, cdcacm_event_t *event)
{
    /* initialization */
    size_t rx_size = 0;

    /* read */
    esp_err_t ret = tinyusb_cdcacm_read(itf, rx_buf, CONFIG_TINYUSB_CDC_RX_BUFSIZE, &rx_size);
    if (ret == ESP_OK) {

        app_message_t tx_msg = {
            .buf_len = rx_size,
            .itf = itf,
        };

        memcpy(tx_msg.buf, rx_buf, rx_size);
        xQueueSend(app_queue, &tx_msg, 0);
    } else {
        ESP_LOGE(TAG, "Read Error");
    }
}

/**
 * @brief CDC device line change callback
 *
 * CDC device signals, that the DTR, RTS states changed
 *
 * @param[in] itf   CDC device index
 * @param[in] event CDC event type
 */
void tinyusb_cdc_line_state_changed_callback(int itf, cdcacm_event_t *event)
{
    int dtr = event->line_state_changed_data.dtr;
    int rts = event->line_state_changed_data.rts;
    ESP_LOGI(TAG, "Line state changed on channel %d: DTR:%d, RTS:%d", itf, dtr, rts);
}

esp_err_t tinyusb_cdc_driver_init(void){
    if(s_initialized)
    {
        return ESP_OK;
    }

    const tinyusb_config_t tusb_cfg = {
        .device_descriptor = NULL,
        .string_descriptor = NULL,
        .external_phy = false,
#if (TUD_OPT_HIGH_SPEED)
        .fs_configuration_descriptor = NULL,
        .hs_configuration_descriptor = NULL,
        .qualifier_descriptor = NULL,
#else
        .configuration_descriptor = NULL,
#endif // TUD_OPT_HIGH_SPEED
    };

    ESP_ERROR_CHECK(tinyusb_driver_install(&tusb_cfg));

    tinyusb_config_cdcacm_t acm_cfg = {
        .usb_dev = TINYUSB_USBDEV_0,
        .cdc_port = TINYUSB_CDC_ACM_0,
        .rx_unread_buf_sz = 64,
        .callback_rx = &tinyusb_cdc_rx_callback, // the first way to register a callback
        .callback_rx_wanted_char = NULL,
        .callback_line_state_changed = NULL,
        .callback_line_coding_changed = NULL
    };

    ESP_ERROR_CHECK(tusb_cdc_acm_init(&acm_cfg));

#if (CONFIG_TINYUSB_CDC_COUNT > 1)
    acm_cfg.cdc_port = TINYUSB_CDC_ACM_1;
    ESP_ERROR_CHECK(tusb_cdc_acm_init(&acm_cfg));
    ESP_ERROR_CHECK(tinyusb_cdcacm_register_callback(
                        TINYUSB_CDC_ACM_1,
                        CDC_EVENT_LINE_STATE_CHANGED,
                        &tinyusb_cdc_line_state_changed_callback));
#endif

    app_queue = xQueueCreate(5, sizeof(app_message_t));
    assert(app_queue);

    ESP_LOGI(TAG, "USB initialization DONE");
    s_initialized = true;

    return ESP_OK;
}

esp_err_t tinyusb_cdc_rec(void){
    if (xQueueReceive(app_queue, &g_msg_recv, portMAX_DELAY)) {
        if (g_msg_recv.buf_len) {

            /* Print received data*/
            ESP_LOGI(TAG, "Data from channel %d:", g_msg_recv.itf);
            ESP_LOG_BUFFER_HEXDUMP(TAG, g_msg_recv.buf, g_msg_recv.buf_len, ESP_LOG_INFO);

            /* write back */
            tinyusb_cdcacm_write_queue(g_msg_recv.itf, g_msg_recv.buf, g_msg_recv.buf_len);
            esp_err_t err = tinyusb_cdcacm_write_flush(g_msg_recv.itf, 0);
            if (err != ESP_OK) {
                ESP_LOGE(TAG, "CDC ACM write flush error: %s", esp_err_to_name(err));
                return err;
            }
        }
    }
    return ESP_OK;
}
