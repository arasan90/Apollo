/** @file apolloHalStorage.h
 * @brief Module managing flash storage HAL
 * @ingroup apolloHalStorage
 */

#ifndef APOLLOHALSTORAGE_H
#define APOLLOHALSTORAGE_H
/*--------------------Includes--------------------*/
/*----------------Type definitions----------------*/
/*--------------Function declarations-------------*/
void apolloHalStorageInit(void);
int apolloHalStorageRead(const char* const fileName, char* const buffer, unsigned int bufferLength);
int apolloHalStorageWrite(const char* const fileName, const char* const value, unsigned int valueLen);

#endif /* APOLLOHALSTORAGE_H */