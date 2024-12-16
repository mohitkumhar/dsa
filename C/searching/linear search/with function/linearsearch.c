#include <stdio.h>

// Function for linear search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    int size, target;

    // Taking array size as input
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size]; // Array to hold the elements

    // Taking array elements as input
    printf("Enter %d elements of the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Taking the target value as input
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Performing linear search
    int result = linearSearch(arr, size, target);

    // Output the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
