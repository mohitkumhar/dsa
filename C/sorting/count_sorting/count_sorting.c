#include <stdio.h>

void printArray(int num[], int size)
{
    printf("The Array is: ");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

int arrMax(int num[], int size)
{
    int max = num[0];

    for (int i = 0; i < size; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
        }
    }
    return max;
}

void countSort(int num[], int size)
{
    int maximum = arrMax(num, size);
    int newMaxArr[maximum + 1];

    for (int i = 0; i <= maximum; i++)
    {
        newMaxArr[i] = 0;
    }

    for (int k = 0; k < size; k++)
    {
        int j = num[k];
        newMaxArr[j]++;
    }

    int z = 0;
    for (int l = 0; l <= maximum; l++)
    {
        while (newMaxArr[l] != 0)
        {
            num[z] = l;
            z++;
            newMaxArr[l]--;
        }
    }
}

int main()
{
    int num[] = {9, 8, 7, 6, 5, 4, 3, 2};

    int size = sizeof(num) / sizeof(int);

    printArray(num, size);
    countSort(num, size);
    printArray(num, size);

    return 0;
}
