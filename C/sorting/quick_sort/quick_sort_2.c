#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partation(int arr[], int se, int ee)
{
    int start = se;
    int end = ee;

    int pivot = arr[start];

    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (end > start)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[se], &arr[end]);

    return end;
}

void quick_sort(int arr[], int se, int ee)
{
    if (se < ee){
        int loc = partation(arr, se, ee);

        quick_sort(arr, se, loc - 1);
        quick_sort(arr, loc + 1, ee);
    }
}

int main()
{
    int arr[] = {2, 4, 3, 6, 5, 7, 9, 1, 0};

    int size = sizeof(arr) / sizeof(arr[0]);


    for (int i = 0; i < size; i++) printf("%d ", arr[i]);

    printf("\n");
    quick_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    
    return 0;
}



