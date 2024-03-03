/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   BucketSort
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdBucketSort.h"
#include "stdio.h"

/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    //char_t* name = 0;
    //char_t* copyName = 0;
	int16_t* array;
	int16_t i;
    /* Указатель на тестируемый интерфейс */
    IBucketSort* pIBucketSort = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#ifdef ECO_LIB
    /* Регистрация статического компонента для работы со списком */
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_BucketSort, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1513C9E5E5FC40C8AFFA7916AEB44AD1);
    if (result != 0 ) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
#endif
    /* Получение интерфейса управления памятью */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**) &pIMem);

    /* Проверка */
    if (result != 0 || pIMem == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
        goto Release;
    }

    /* Выделение блока памяти */
    //name = (char_t *)pIMem->pVTbl->Alloc(pIMem, 10);
	array = (int16_t *)pIMem->pVTbl->Alloc(pIMem, 10*sizeof(int16_t));
	
	//i = 100;

    /* Заполнение блока памяти */
   // pIMem->pVTbl->Fill(pIMem, name, 'a', 9);
	for (i=0; i<10; i++){
        array[i]=10-i;
    }
	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");


	
	//while (i > 0){
	//	printf("Generated Array: ");
		//i = i - 1;
	//}

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_BucketSort, 0, &IID_IBucketSort, (void**) &pIBucketSort);
    printf("%d %d", result, pIBucketSort);
	if (result != 0 || pIBucketSort == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }


    result = pIBucketSort->pVTbl->Sort(pIBucketSort, array, 10, 10);

	for (i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");

    /* Освобождение блока памяти */
    //pIMem->pVTbl->Free(pIMem, name);
	pIMem->pVTbl->Free(pIMem, array);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение тестируемого интерфейса */
    if (pIBucketSort != 0) {
        pIBucketSort->pVTbl->Release(pIBucketSort);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

