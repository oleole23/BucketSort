/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IBucketSort
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IBucketSort
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

#ifndef __I_BUCKETSORT_H__
#define __I_BUCKETSORT_H__

#include "IEcoBase1.h"

/* IBucketSort IID = {3727D668-6FA8-42AA-AA37-CA59CA02912D} */
#ifndef __IID_IBucketSort
static const UGUID IID_IBucketSort = {0x01, 0x10, 0x37, 0x27, 0xD6, 0x68, 0x6F, 0xA8, 0x42, 0xAA, 0xAA, 0x37, 0xCA, 0x59, 0xCA, 0x02, 0x91, 0x2D};
#endif /* __IID_IBucketSort */

typedef struct IBucketSortVTbl {

    /* IEcoUnknown */
    int16_t (ECOCALLMETHOD *QueryInterface)(/* in */ struct IBucketSort* me, /* in */ const UGUID* riid, /* out */ void **ppv);
    uint32_t (ECOCALLMETHOD *AddRef)(/* in */ struct IBucketSort* me);
    uint32_t (ECOCALLMETHOD *Release)(/* in */ struct IBucketSort* me);

    /* IBucketSort */
	int16_t(ECOCALLMETHOD* Sort)(struct IBucketSort* me, void* base, size_t n, int16_t max_val);

} IBucketSortVTbl, *IBucketSortVTblPtr;

interface IBucketSort {
    struct IBucketSortVTbl *pVTbl;
} IBucketSort;


#endif /* __I_BUCKETSORT_H__ */
