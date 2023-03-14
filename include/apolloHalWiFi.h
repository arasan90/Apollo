/** @file apolloHalWiFi.h
 *  @brief Module managing Wi-Fi HAL
 * @ingroup apolloHalWiFi
 */

#ifndef APOLLOHALWIFI_H
#define APOLLOHALWIFI_H
/*--------------------Includes--------------------*/
#include <stdint.h>

/*----------------Type definitions----------------*/
typedef enum
{
    APOLLOHALWIFIEVENT_STA_STARTED,
    APOLLOHALWIFIEVENT_AP_STARTED,
    APOLLOHALWIFIEVENT_CONNECTED,
    APOLLOHALWIFIEVENT_DISCONNECTED,
    APOLLOHALWIFIEVENT_NEW_IP,
    APOLLOHALWIFIEVENT_LOST_IP,
}   apolloHalWifiEvent_t;

typedef void (*apolloHalWifiEventsManager)(apolloHalWifiEvent_t);

/*--------------Function declarations-------------*/

/**
 * @brief Initialize the Wi-Fi manager module
 */
void apolloHalWiFiInit(apolloHalWifiEventsManager eventsManager);
void apolloHalWiFiConnect(void);

#endif /* APOLLOHALWIFI_H */