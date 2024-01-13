#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int num[], int size)
{
    printf("The Array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
}

void selectionSort(int num[], int size)
{
    int indexOfMin;
    for (int i = 0; i < size; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if(num[j] < num[i])
            {
                swap(&num[j], &num[indexOfMin]);
            }
        }
    }
}

int main()
{
    int num[] = {2, 4, 6, 8, 0, 1, 3, 5, 7, 9};
    int size = sizeof(num) / sizeof(int);

    printArray(num, size);
    selectionSort(num, size);
    printArray(num, size);

    return 0;
}

//  (2)   4   3   9   1   4   8   7   5   6

//  (2)   1   3   9   4   4   8   7   5   6

//  {1}   (2)   3   9   4   4   8   7   5   6

//  {1}   {2}   (3)   9   4   4   8   7   5   6

//  {1}   {2}   {3}   (9)   4   4   8   7   5   6

//  {1}   {2}   {3}   (9)   4   4   8   7   5   6

//  {1}   {2}   {3}   (6)   4   4   8   7   5   {9}

//  {1}   {2}   {3}   (6)   4   4   8   7   5   {9}

//  {1}   {2}   {3}   (6)   4   4   5   7   8   {9}

//  {1}   {2}   {3}   (5)   4   4   {6}   7   8   {9}

//  {1}   {2}   {3}   (4)   4   {5}   {6}   7   8   {9}

//  {1}   {2}   {3}   (4)   {4}   {5}   {6}   7   8   {9}

// +-+-+-+-+-+
// |3|4|6|8|7|
// +-+-+-+-+-+
