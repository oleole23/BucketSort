/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdBucketSort
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdBucketSort
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __ID_BUCKETSORT_H__
#define __ID_BUCKETSORT_H__

#include "IEcoBase1.h"
#include "IBucketSort.h"

/* BucketSort CID = {6343D68A-B28A-4F8F-ABE9-0F23A040FC88} */
#ifndef __CID_BucketSort
static const UGUID CID_BucketSort = {0x01, 0x10, 0x63, 0x43, 0xD6, 0x8A, 0xB2, 0x8A, 0x4F, 0x8F, 0xAB, 0xE9, 0x0F, 0x23, 0xA0, 0x40, 0xFC, 0x88};
#endif /* __CID_BucketSort */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_6343D68AB28A4F8FABE90F23A040FC88;
#endif

#endif /* __ID_BUCKETSORT_H__ */
