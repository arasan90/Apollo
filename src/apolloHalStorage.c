/** @file apolloHalStorage.c
 * @brief Module managing flash storage HAL
 * @ingroup apolloHalStorage
 */

/*--------------------Includes--------------------*/
#include "apolloHalStorage.h"
#include "esp_err.h"
#include "nvs_flash.h"

/*----------------Type definitions----------------*/
/*--------------------Constants-------------------*/
/*--------------------Variables-------------------*/
static nvs_handle_t my_handle = 0;

/*----------Static function declarations----------*/
/*--------------Function definitions--------------*/
/*-----------Static function definitions----------*/
void apolloHalStorageInit(void)
{
    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(nvs_open("storage", NVS_READWRITE, &my_handle));
}

int apolloHalStorageRead(const char* const fileName, char* const buffer, unsigned int bufferLength)
{
    size_t valueLength = -1;
    int strLength = -1;
    if (ESP_OK == nvs_get_str(my_handle, fileName, NULL, &valueLength))
    {
        if (bufferLength >= valueLength)
        {
            if (ESP_OK == nvs_get_str(my_handle, fileName, buffer, &valueLength))
            {
                strLength = valueLength;
            }
        }
    }
    return strLength;
}

int apolloHalStorageWrite(const char* const fileName, const char* const value, unsigned int valueLen)
{
    (void)valueLen;
    int retCode = -1;
    if (ESP_OK == nvs_set_str(my_handle, fileName, value))
    {
        if (ESP_OK == nvs_commit(my_handle))
        {
            retCode = 0;
        }
    }
    return retCode;
}