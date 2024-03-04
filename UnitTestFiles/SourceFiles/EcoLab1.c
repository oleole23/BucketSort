/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoLab1
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
#include "IdEcoLab1.h"
#include "stdlib.h"
#include "stdio.h"
#include <time.h>

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

int __cdecl IntComparator(const void * a_, const void * b_) { 
	int16_t a = *(int16_t *)a_;
	int16_t b = *(int16_t *)b_;
	return (a > b) - (a < b);
}

int __cdecl DoubleCompare(const void * a_, const void * b_) { 
	double a = *(double *)a_;
	double b = *(double *)b_;
	return (a > b) - (a < b);
}

int __cdecl FloatCompare(const void * a_, const void * b_) { 
    float a = *(float *)a_;
	float b = *(float *)b_;
	return (a > b) - (a < b);
}

int __cdecl CharCompare(const void * a_, const void * b_) { 
    char a = *(char *)a_;
	char b = *(char *)b_;
	return (a > b) - (a < b);
}

void IntArrayPrint(void *arr, size_t n){
	int16_t *array = (int16_t*) arr;
	size_t i;
	for (i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void DoubleArrayPrint(void* arr, size_t n){
	double *array = (double*) arr;
	size_t i;
	for (i = 0; i < n; i++) {
		printf("%lf ", array[i]);
	}
	printf("\n");
}

void FloatArrayPrint(void* arr, size_t n){
	float *array = (float*) arr;
	size_t i;
	for (i = 0; i < n; i++) {
		printf("%f ", array[i]);
	}
	printf("\n");
}

void CharArrayPrint(void* arr, size_t n){
	char *array = (char*) arr;
	size_t i;
	for (i = 0; i < n; i++) {
		printf("%s ", array[i]);
	}
	printf("\n");
}

void IntTest(IEcoLab1 *pIEcoLab1, IEcoMemoryAllocator1 *pIMem, size_t n, int16_t max_val){
	int16_t* array_bs;
	int16_t* array_qs;
	int16_t i;
	clock_t start_bs;
	clock_t end_bs;
	double cpu_time_bs;
	clock_t start_qs;
	clock_t end_qs;
	double cpu_time_qs;

    /* Выделение блока памяти */
	array_bs = (int16_t *)pIMem->pVTbl->Alloc(pIMem, n*sizeof(int16_t));
	array_qs = (int16_t *)pIMem->pVTbl->Alloc(pIMem, n*sizeof(int16_t));

	/* Заполнение блока памяти */
	srand(time(NULL));
    for (i = 0; i < n; i++){
        array_bs[i] = 0 + rand() % (50 - 0 +1);
		array_qs[i] = array_bs[i];
    }

	IntArrayPrint(array_bs, n);

	start_bs = clock();
    pIEcoLab1->pVTbl->BucketSort(pIEcoLab1, array_bs, n, max_val, IntComparator);
	end_bs = clock();
    cpu_time_bs = ((double) (end_bs - start_bs)*1000);

	start_qs = clock();
	qsort(array_qs, n, sizeof(int16_t), IntComparator);
	end_qs = clock();
    cpu_time_qs = ((double) (end_qs - start_qs)*1000);

	IntArrayPrint(array_bs, n);
	printf("Time taken by Bucket Sort: %f ms\n", cpu_time_bs);
    printf("Time taken by Quick Sort: %f ms\n", cpu_time_qs);

	
    /* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, array_bs);
	pIMem->pVTbl->Free(pIMem, array_qs);
}

void DoubleTest(IEcoLab1 *pIEcoLab1, IEcoMemoryAllocator1 *pIMem, size_t n, int16_t max_val){
	double* array_bs;
	double* array_qs;
	int16_t i;
	clock_t start_bs;
	clock_t end_bs;
	double cpu_time_bs;
	clock_t start_qs;
	clock_t end_qs;
	double cpu_time_qs;

    /* Выделение блока памяти */
	array_bs = (double *)pIMem->pVTbl->Alloc(pIMem, n*sizeof(double));
	array_qs = (double *)pIMem->pVTbl->Alloc(pIMem, n*sizeof(double));

	/* Заполнение блока памяти */
    for (i = 0; i < n; i++){
        array_bs[i] = (double)rand() / RAND_MAX;
		array_qs[i] = array_bs[i];
    }

	DoubleArrayPrint(array_bs, n);

	start_bs = clock();
    pIEcoLab1->pVTbl->BucketSort(pIEcoLab1, array_bs, n, max_val, IntComparator);
	end_bs = clock();
    cpu_time_bs = ((double) (end_bs - start_bs)*1000);

	start_qs = clock();
	qsort(array_qs, n, sizeof(double), IntComparator);
	end_qs = clock();
    cpu_time_qs = ((double) (end_qs - start_qs)*1000);

	DoubleArrayPrint(array_bs, n);
	printf("Time taken by Bucket Sort: %f ms\n", cpu_time_bs);
    printf("Time taken by Quick Sort: %f ms\n", cpu_time_qs);

	
    /* Освобождение блока памяти */
	pIMem->pVTbl->Free(pIMem, array_bs);
	pIMem->pVTbl->Free(pIMem, array_qs);
}

int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на тестируемый интерфейс */
    IEcoLab1* pIEcoLab1 = 0;

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
    result = pIBus->pVTbl->RegisterComponent(pIBus, &CID_EcoLab1, (IEcoUnknown*)GetIEcoComponentFactoryPtr_1F5DF16EE1BF43B999A434ED38FE8F3A);
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

    /* Получение тестируемого интерфейса */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLab1, 0, &IID_IEcoLab1, (void**) &pIEcoLab1);
    if (result != 0 || pIEcoLab1 == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }




	IntTest(pIEcoLab1, pIMem, 10, 1000);
	//DoubleTest(pIEcoLab1, pIMem, 10, 1000);






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
    if (pIEcoLab1 != 0) {
        pIEcoLab1->pVTbl->Release(pIEcoLab1);
    }


    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

