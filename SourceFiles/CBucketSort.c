/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CBucketSort_A040FC88
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CBucketSort_A040FC88
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "CBucketSort.h"

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IBucketSort
 * </описание>
 *
 */
int16_t ECOCALLMETHOD CBucketSort_A040FC88_QueryInterface(/* in */ struct IBucketSort* me, /* in */ const UGUID* riid, /* out */ void** ppv) {
    CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if ( IsEqualUGUID(riid, &IID_IBucketSort) ) {
        *ppv = &pCMe->m_pVTblIBucketSort;
        pCMe->m_pVTblIBucketSort->AddRef((IBucketSort*)pCMe);
    }
    else if ( IsEqualUGUID(riid, &IID_IEcoUnknown) ) {
        *ppv = &pCMe->m_pVTblIBucketSort;
        pCMe->m_pVTblIBucketSort->AddRef((IBucketSort*)pCMe);
    }
    else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IBucketSort
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBucketSort_A040FC88_AddRef(/* in */ struct IBucketSort* me) {
    CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IBucketSort
 * </описание>
 *
 */
uint32_t ECOCALLMETHOD CBucketSort_A040FC88_Release(/* in */ struct IBucketSort* me) {
    CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)me;

    /* Проверка указателя */
    if (me == 0 ) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if ( pCMe->m_cRef == 0 ) {
        deleteCBucketSort_A040FC88((IBucketSort*)pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
//int16_t ECOCALLMETHOD CBucketSort_A040FC88_MyFunction(/* in */ struct IBucketSort* me, /* in */ char_t* Name, /* out */ char_t** copyName) {
  /*  CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)me;
    int16_t index = 0;

    /* Проверка указателей */
  /*  if (me == 0 || Name == 0 || copyName == 0) {
        return -1;
    }

    /* Копирование строки */
 /*   while(Name[index] != 0) {
        index++;
    }
    pCMe->m_Name = (char_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, index + 1);
    index = 0;
    while(Name[index] != 0) {
        pCMe->m_Name[index] = Name[index];
        index++;
    }
    *copyName = pCMe->m_Name;

    return 0;
}
*/

int16_t insertionSort(int16_t arr[], size_t n) {
	if (n > 0) {
		for (size_t i = 1; i < n; ++i) {
			int16_t key = arr[i];
			int16_t j = i - 1;

			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}

			arr[j + 1] = key;
		}
	}
	return 0;
}

#define N 10000
#define MAX_VAL 10000

int16_t ECOCALLMETHOD CBucketSort_A040FC88_Sort ( struct IBucketSort* me, void *base, size_t n, int16_t max_val){
	CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)me;
	/* Проверка указателей */
    if (me == 0) {
        return -1;
    }

	int16_t* array = (int16_t*)base;
	int16_t (*buckets)[N] = (int16_t(*)[N])pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, max_val * N * sizeof(int16_t));
	size_t* bucket_sizes = (size_t*)pCMe->m_pIMem->pVTbl->Alloc(pCMe->m_pIMem, max_val * sizeof(size_t));

	//int16_t buckets[MAX_VAL][N];
    //size_t bucket_sizes[MAX_VAL];
    for (int16_t i = 0; i < max_val; ++i) {
        bucket_sizes[i] = 0;
    }
    for (size_t i = 0; i < n; ++i) {
        size_t index = array[i];
        buckets[index][bucket_sizes[index]++] = array[i];
    }
	for (size_t i = 0; i < max_val; ++i) {
        insertionSort(buckets[i], bucket_sizes[i]);
    }
	size_t index = 0;
    for (size_t i = 0; i < max_val; ++i) {
        for (size_t j = 0; j < bucket_sizes[i]; ++j) {
            array[index++] = buckets[i][j];
        }
    }

	pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe->buckets);
	pCMe->m_pIMem->pVTbl->Free(pCMe->m_pIMem, pCMe->bucket_sizes);
	return 0;
};





/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD initCBucketSort_A040FC88(/*in*/ struct IBucketSort* me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)me;
    IEcoInterfaceBus1* pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

    /* Проверка указателей */
    if (me == 0 ) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1*)pIUnkSystem;



    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);
	
    return result;
}

/* Create Virtual Table IBucketSort */
IBucketSortVTbl g_x3727D6686FA842AAAA37CA59CA02912DVTbl_A040FC88 = {
    CBucketSort_A040FC88_QueryInterface,
    CBucketSort_A040FC88_AddRef,
    CBucketSort_A040FC88_Release,
	CBucketSort_A040FC88_Sort
};




/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t ECOCALLMETHOD createCBucketSort_A040FC88(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* out */ IBucketSort** ppIBucketSort) {
    int16_t result = -1;
    IEcoSystem1* pISys = 0;
    IEcoInterfaceBus1* pIBus = 0;
    IEcoInterfaceBus1MemExt* pIMemExt = 0;
    IEcoMemoryAllocator1* pIMem = 0;
    CBucketSort_A040FC88* pCMe = 0;
    UGUID* rcid = (UGUID*)&CID_EcoMemoryManager1;
	
    /* Проверка указателей */
    if (ppIBucketSort == 0 || pIUnkSystem == 0) {
        return result;
    }

    /* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **)&pISys);

    /* Проверка */
    if (result != 0 && pISys == 0) {
        return result;
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);

	/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void**)&pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID*)pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->Release(pIMemExt);
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, rcid, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 && pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->Release(pISys);
        return result;
    }

    /* Выделение памяти для данных экземпляра */
    pCMe = (CBucketSort_A040FC88*)pIMem->pVTbl->Alloc(pIMem, sizeof(CBucketSort_A040FC88));

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

    /* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

    /* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

    /* Создание таблицы функций интерфейса IBucketSort */
    pCMe->m_pVTblIBucketSort = &g_x3727D6686FA842AAAA37CA59CA02912DVTbl_A040FC88;

    /* Инициализация данных */
    //pCMe->m_Name = 0;
	pCMe->buckets = 0;
    pCMe->bucket_sizes = 0;


    /* Возврат указателя на интерфейс */
    *ppIBucketSort = (IBucketSort*)pCMe;

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void ECOCALLMETHOD deleteCBucketSort_A040FC88(/* in */ IBucketSort* pIBucketSort) {
    CBucketSort_A040FC88* pCMe = (CBucketSort_A040FC88*)pIBucketSort;
    IEcoMemoryAllocator1* pIMem = 0;

    if (pIBucketSort != 0 ) {
        pIMem = pCMe->m_pIMem;
        /* Освобождение */
        //if ( pCMe->m_Name != 0 ) {
          //  pIMem->pVTbl->Free(pIMem, pCMe->m_Name);
        //}
		if (pCMe->buckets != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->buckets);
        }
		if (pCMe->bucket_sizes != 0) {
            pIMem->pVTbl->Free(pIMem, pCMe->bucket_sizes);
        }

        if ( pCMe->m_pISys != 0 ) {
            pCMe->m_pISys->pVTbl->Release(pCMe->m_pISys);
        }
        pIMem->pVTbl->Free(pIMem, pCMe);
        pIMem->pVTbl->Release(pIMem);
    }
}
