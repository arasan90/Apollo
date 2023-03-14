/** @file apolloHalWiFi.c
 * @brief Module managing Wi-Fi HAL
 * @ingroup apolloHalWiFi
 */

/*--------------------Includes--------------------*/
#include "apolloHalWifi.h"
#include "esp_log.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include "esp_netif.h"

/*----------------Type definitions----------------*/
/*--------------------Constants-------------------*/
/*--------------------Variables-------------------*/
static esp_netif_t *sta_netif = NULL;

/*----------Static function declarations----------*/
static void event_handler(void* arg, esp_event_base_t event_base, int32_t event_id, void* event_data);

/*--------------Function definitions--------------*/
void apolloHalWiFiInit(apolloHalWifiEventsManager eventsManager)
{
    wifi_init_config_t wifiConfig = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    ESP_ERROR_CHECK(esp_wifi_init(&wifiConfig));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT, ESP_EVENT_ANY_ID, &event_handler, NULL, NULL));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &event_handler, NULL, NULL));
    sta_netif = esp_netif_create_default_wifi_sta();
    assert(sta_netif);
    ESP_ERROR_CHECK(esp_netif_set_hostname(sta_netif, "mytest"));
}

void apolloHalWiFiConnect(void)
{
wifi_config_t wifi_config = {
        .sta = {
            .ssid = "NuovaFiber-D6FA6",
            .password = "894564gg",
            .listen_interval = 3,
        },
    };
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());
    esp_wifi_connect();
}

/*-----------Static function definitions----------*/
static void event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        //esp_wifi_connect();
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI("apolloWi-Fi", "got ip: " IPSTR, IP2STR(&event->ip_info.ip));
    }
}