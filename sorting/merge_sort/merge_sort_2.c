#include <stdio.h>

void printArray(int num[], int size)
{
    printf("The Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void merge(int num[], int low, int mid, int high)
{
    int i, j, k;
    int num2[high];
    i = 0;
    j = 0;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (num[i] < num[j])
        {
            num2[k] = num[i];
            k++, i++;
        }
        else
        {
            num2[k] = num[j];
            k++, j++;
        }
    }
    while (i <= mid)
    {
        num2[k] = num[i];
        k++, i++;
    }
    while (j <= high)
    {
        num2[k] = num[j];
        k++, j++;
    }

    for (i = 0; i <= high - low; i++)
    {
        num[low + i] = num2[i];
    }
}

void mergeSort(int num[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(num, low, mid);
        mergeSort(num, mid+1, high);

        merge(num, low, mid, high);
    }
}

int main()
{
    int num[] = {1, 3, 5, 2, 4, 6, 7};
    int size = sizeof(num) / sizeof(int);

    printArray(num, size);
    mergeSort(num, 0, size-1);
    printArray(num, size);
    return 0;
}
