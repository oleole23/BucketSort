/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CBucketSort
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CBucketSort
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_BUCKETSORT_H__
#define __C_BUCKETSORT_H__

#include "IBucketSort.h"
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CBucketSort_A040FC88 {

    /* Таблица функций интерфейса IBucketSort */
    IBucketSortVTbl* m_pVTblIBucketSort;


    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Системный интерфейс */
    IEcoSystem1* m_pISys;

    /* Данные экземпляра */
    //char_t* m_Name;
	int16_t (*buckets)[N];  // Указатель на двумерный массив buckets[max_val][n]
    size_t* bucket_sizes;    // Указатель на массив bucket_sizes[max_val]

} CBucketSort_A040FC88, *CBucketSort_A040FC88Ptr;

/* Инициализация экземпляра */
int16_t ECOCALLMETHOD initCBucketSort_A040FC88(/*in*/ struct IBucketSort* me, /* in */ IEcoUnknown *pIUnkSystem);
/* Создание экземпляра */
int16_t ECOCALLMETHOD createCBucketSort_A040FC88(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IBucketSort** ppIBucketSort);
/* Удаление */
void ECOCALLMETHOD deleteCBucketSort_A040FC88(/* in */ IBucketSort* pIBucketSort);

#endif /* __C_BUCKETSORT_H__ */
