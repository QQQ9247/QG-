#pragma once
#include "������.h"
// ���������
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// ���ɲ�������
void generateTestData(int* nums, int numCount, int min, int max) {
    srand(time(NULL));

    for (int i = 0; i < numCount; i++) {
        nums[i] = generateRandomNumber(min, max);
    }
}
// ������������ͬ�ڴ��������µ���ʱ
void testSortingTime1(int numCount) {
    int* nums = (int*)malloc(numCount * sizeof(int));

    // ���ɲ�������
    generateTestData(nums, numCount, 1, numCount);

    // ��¼����ʼʱ��
    clock_t startTime1 = clock();
    InsertSort(nums, numCount);//��������
    clock_t endTime1 = clock();
    double elapsedTime1 = (double)(endTime1 - startTime1) * 1000 / CLOCKS_PER_SEC;

    clock_t startTime2 = clock();
    int* t = (int*)malloc(numCount * sizeof(int));
    MergeSort(nums, 0, numCount,t);//�鲢����
    clock_t endTime2 = clock();
    double elapsedTime2 = (double)(endTime2 - startTime2) * 1000 / CLOCKS_PER_SEC;
    free(t);
    t = NULL;

    clock_t startTime3 = clock();
    QuickSort(nums, 0, numCount);//��������
    clock_t endTime3 = clock();
    double elapsedTime3 = (double)(endTime3 - startTime3) * 1000 / CLOCKS_PER_SEC;

    clock_t startTime4 = clock();
    CountSort(nums, numCount);//��������
    clock_t endTime4 = clock();
    double elapsedTime4 = (double)(endTime4 - startTime4) * 1000 / CLOCKS_PER_SEC;

    clock_t startTime5 = clock();
    RadixCountSort(nums,numCount);//������������
    clock_t endTime5 = clock();
    double elapsedTime5 = (double)(endTime5 - startTime5) * 1000 / CLOCKS_PER_SEC;


    printf("��������%d\n����������ʱ��%.2f����\n�鲢������ʱ��%.2f����\n����������ʱ��%.2f����\n����������ʱ��%.2f����\n��������������ʱ��%.2f����\n", numCount, elapsedTime1, elapsedTime2, elapsedTime3, elapsedTime4, elapsedTime5);

    free(nums);
    nums = NULL;
}

//�������ڴ���С�������µ���ʱ
void testSortingTime2(int numCount,int repeatCount) {
    double sum[5] = {0};
    for (int i = 1; i <= repeatCount; i++)
    {
        // ���ɲ�������
        int* nums = (int*)malloc(numCount * sizeof(int));
        int* temp = (int*)malloc(numCount * sizeof(int));
        generateTestData(nums, numCount, 1, numCount);
        memcpy(temp, nums, numCount);
        // ��¼����ʼʱ��
        clock_t startTime1 = clock();
        InsertSort(temp, numCount);//��������
        clock_t endTime1 = clock();
        sum[0] += (double)(endTime1 - startTime1) * 1000 / CLOCKS_PER_SEC;

        memcpy(temp, nums, numCount);
        clock_t startTime2 = clock();
        int* t = (int*)malloc(numCount * sizeof(int));
        MergeSort(temp, 0, numCount, t);//�鲢����
        clock_t endTime2 = clock();
        sum[1] += (double)(endTime2 - startTime2) * 1000 / CLOCKS_PER_SEC;
        free(t);
        t = NULL;

        memcpy(temp, nums, numCount);
        clock_t startTime3 = clock();
        QuickSort(temp, 0, numCount);//��������
        clock_t endTime3 = clock();
        sum[2] += (double)(endTime3 - startTime3) * 1000 / CLOCKS_PER_SEC;

        memcpy(temp, nums, numCount);
        clock_t startTime4 = clock();
        CountSort(temp, numCount);//��������
        clock_t endTime4 = clock();
        sum[3] += (double)(endTime4 - startTime4) * 1000 / CLOCKS_PER_SEC;

        memcpy(temp, nums, numCount);
        clock_t startTime5 = clock();
        RadixCountSort(temp,numCount);//������������
        clock_t endTime5 = clock();
        sum[4] += (double)(endTime5 - startTime5) * 1000 / CLOCKS_PER_SEC;

        free(temp);
        free(nums);
        nums = NULL;
    }
    
    printf("��������%d�����������%d\n����������ʱ��%.2f����\n�鲢������ʱ��%.2f����\n����������ʱ��%.2f����\n����������ʱ��%.2f����\n��������������ʱ��%.2f����\n", numCount, repeatCount,sum[0], sum[1], sum[2], sum[3], sum[4]);

}

//���ɲ������ݲ����浽�ļ�
void generateTestDataToFile(const char* filename, int numCount, int min, int max) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("�޷����ļ�\n");
        return;
    }

    srand(time(NULL));

    for (int i = 0; i < numCount; i++) {
        int num = generateRandomNumber(min, max);
        fprintf(file, "%d\n", num);
    }

    fclose(file);
    printf("�������������ɲ����浽�ļ���%s\n", filename);
}

//��ȡ�ļ��е�����
void readDataAndSort(const char* filename) {
    int t[500] = {0};
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("�޷����ļ�\n");
        return;
    }

    int numCount = 0;
    int* nums = NULL;

    // ��ȡ�ļ��е�����
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        numCount++;
        nums = (int*)realloc(nums, numCount * sizeof(int));
        nums[numCount - 1] = num;
    }
    fclose(file);

    printf("�򿪳ɹ���ԭʼ����Ϊ��");
    for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
    int op;
    printf("\n��ѡ��ʹ�õ������㷨��\n1.��������\n2.�鲢����\n3.��������\n4.��������\n5.������������\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        InsertSort(nums, numCount);
        printf("\n����������Ϊ��\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 2:
        MergeSort(nums, 0, numCount, t);
        printf("\n����������Ϊ��\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 3:
        QuickSort(nums, 0, numCount);
        printf("\n����������Ϊ��\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 4:
        CountSort(nums, numCount);
        printf("\n����������Ϊ��\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    case 5:
        RadixCountSort(nums,numCount);
        printf("\n����������Ϊ��\n");
        for (int i = 0; i < numCount; i++) printf("%d ", nums[i]);
        break;
    }
    free(nums);
    nums = NULL;
}