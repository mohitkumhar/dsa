#include <stdio.h>

void printArray(int num[], int size)
{
    printf("The New Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void mergeSort(int num1[], int size1, int num2[], int size2, int num3[])
{
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2)
    {
        if (num1[i] < num2[j])
        {
            num3[k] = num1[i];
            k++, i++;
        }
        else
        {
            num3[k] = num2[j];
            k++, j++;
        }
    }
    while (i < size1)
    {
        num3[k] = num1[i];
        k++, i++;
    }
    while (j < size2)
    {
        num3[k] = num2[j];
        k++, j++;
    }
}

int main()
{
    int num1[] = {0, 2, 4, 6, 8};
    int num2[] = {1, 3, 5, 7, 9};
    int num3[10];

    int size1 = sizeof(num1) / sizeof(int);
    int size2 = sizeof(num2) / sizeof(int);
    int size3 = sizeof(num3) / sizeof(int);

    printArray(num3, size3);
    mergeSort(num1, size1, num2, size2, num3);
    printArray(num3, size3);
    return 0;
}
