#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "apolloHalStorage.h"
#include "apolloHalWiFi.h"


static const char *logTag = "main";
void app_main()
{
    apolloHalStorageInit();
    apolloHalWiFiInit(NULL);
    apolloHalWiFiConnect();
    ESP_LOGI(logTag, "Storage initialized.\r\n");
    while(1)
    {
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
