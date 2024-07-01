#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int num[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void bubbleSort(int num[], int size)
{
    int isSorted;
    for (int i = 0; i < size - 1; i++) // Number of Passes
    {
        printf("Loop Running Number: %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < size - 1 - i; j++) // Number of Comparision
        {
            if (num[j] > num[j + 1])
            {
                swap(&num[j], &num[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            break;
        }
    }
}

int main()
{
    int num[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
    int size = sizeof(num) / sizeof(int);

    printArray(num, size);
    bubbleSort(num, size);
    printArray(num, size);
    return 0;
}
