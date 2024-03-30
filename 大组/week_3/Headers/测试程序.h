#pragma once
#include "排序函数.h"
// 生成随机数
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// 生成测试数据
void generateTestData(int* nums, int numCount, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < numCount; i++) {
        nums[i] = generateRandomNumber(min, max);
    }
}
// 测试排序函数不同在大量数据下的用时
void testSortingTime1(int numCount) {
    int* nums = (int*)malloc(numCount * sizeof(int));

    // 生成测试数据
    generateTestData(nums, numCount, 1, numCount);

    // 记录排序开始时间
    clock_t startTime1 = clock();
    InsertSort(nums, numCount);//插入排序
    clock_t endTime1 = clock();
    double elapsedTime1 = (double)(endTime1 - startTime1) * 1000 / CLOCKS_PER_SEC;

    clock_t startTime2 = clock();
    int* t = (int*)malloc(numCount * sizeof(int));
    MergeSort(nums, 0, numCount,t);//归并排序
    clock_t endTime2 = clock();
    double elapsedTime2 = (double)(endTime2 - startTime2) * 1000 / CLOCKS_PER_SEC;
    free(t);
    t = NULL;

    clock_t startTime3 = clock();
    QuickSort(nums, 0, numCount);//快速排序
    clock_t endTime3 = clock();
    double elapsedTime3 = (double)(endTime3 - startTime3) * 1000 / CLOCKS_PER_SEC;

    clock_t startTime4 = clock();
    CountSort(nums, numCount);//计数排序
    clock_t endTime4 = clock();
    double elapsedTime4 = (double)(endTime4 - startTime4) * 1000 / CLOCKS_PER_SEC;

    clock_t startTime5 = clock();
    RadixCountSort(nums,numCount);//基数计数排序
    clock_t endTime5 = clock();
    double elapsedTime5 = (double)(endTime5 - startTime5) * 1000 / CLOCKS_PER_SEC;


    printf("数据量：%d\n插入排序用时：%.2f毫秒\n归并排序用时：%.2f毫秒\n快速排序用时：%.2f毫秒\n计数排序用时：%.2f毫秒\n基数计数排序用时：%.2f毫秒\n", numCount, elapsedTime1, elapsedTime2, elapsedTime3, elapsedTime4, elapsedTime5);

    free(nums);
    nums = NULL;
}

//排序函数在大量小数据量下的用时
void testSortingTime2(int numCount,int repeatCount) {
    double sum[5] = {0};
    for (int i = 1; i <= repeatCount; i++)
    {
        // 生成测试数据
        int* nums = (int*)malloc(numCount * sizeof(int));
        int* temp = (int*)malloc(numCount * sizeof(int));
        generateTestData(nums, numCount, 1, numCount);
        memcpy(temp, nums, numCount);
        // 记录排序开始时间
        clock_t startTime1 = clock();
        InsertSort(temp, numCount);//插入排序
        clock_t endTime1 = clock();
        sum[0] += (double)(endTime1 - startTime1) * 1000 / CLOCKS_PER_SEC;

        memcpy(temp, nums, numCount);
        clock_t startTime2 = clock();
        int* t = (int*)malloc(numCount * sizeof(int));
        MergeSort(temp, 0, numCount, t);//归并排序
        clock_t endTime2 = clock();
        sum[1] += (double)(endTime2 - startTime2) * 1000 / CLOCKS_PER_SEC;
        free(t);
        t = NULL;

        memcpy(temp, nums, numCount);
        clock_t startTime3 = clock();
        QuickSort(temp, 0, numCount);//快速排序
        clock_t endTime3 = clock();
        sum[2] += (double)(endTime3 - startTime3) * 1000 / CLOCKS_PER_SEC;

        memcpy(temp, nums, numCount);
        clock_t startTime4 = clock();
        CountSort(temp, numCount);//计数排序
        clock_t endTime4 = clock();
        sum[3] += (double)(endTime4 - startTime4) * 1000 / CLOCKS_PER_SEC;

        memcpy(temp, nums, numCount);
        clock_t startTime5 = clock();
        RadixCountSort(temp,numCount);//基数计数排序
        clock_t endTime5 = clock();
        sum[4] += (double)(endTime5 - startTime5) * 1000 / CLOCKS_PER_SEC;

        free(temp);
        free(nums);
        nums = NULL;
    }
    
    printf("数据量：%d、排序次数：%d\n插入排序用时：%.2f毫秒\n归并排序用时：%.2f毫秒\n快速排序用时：%.2f毫秒\n计数排序用时：%.2f毫秒\n基数计数排序用时：%.2f毫秒\n", numCount, repeatCount,sum[0], sum[1], sum[2], sum[3], sum[4]);

}

//生成测试数据并保存到文件
void generateTestDataToFile(const char* filename, int numCount, int min, int max) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < numCount; i++) {
        int num = generateRandomNumber(min, max);
        fprintf(file, "%d\n", num);
    }

    fclose(file);
    printf("测试数据已生成并保存到文件：%s\n", filename);
}

//读取文件中的数据
void readDataAndSort(const char* filename) {
    int t[500] = {0};
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("无法打开文件\n");
        return;
    }

    int numCount = 0;
    int* nums = NULL;

    // 读取文件中的数据
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        numCount++;
        nums = (int*)realloc(nums, numCount * sizeof(int));
        nums[numCount - 1] = num;
    }
    fclose(file);

    printf("打开成功，原始数据为：");
    for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
    int op;
    printf("\n请选择使用的排序算法：\n1.插入排序\n2.归并排序\n3.快速排序\n4.计数排序\n5.基数计数排序\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        InsertSort(nums, numCount);
        printf("\n排序后的数据为：\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 2:
        MergeSort(nums, 0, numCount, t);
        printf("\n排序后的数据为：\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 3:
        QuickSort(nums, 0, numCount);
        printf("\n排序后的数据为：\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 4:
        CountSort(nums, numCount);
        printf("\n排序后的数据为：\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 5:
        RadixCountSort(nums,numCount);
        printf("\n排序后的数据为：\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    }
    free(nums);
    nums = NULL;
}