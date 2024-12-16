#include <stdio.h>

// Function for binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // To prevent overflow

        // Check if the target is at mid
        if (arr[mid] == target)
            return mid;

        // If the target is greater, ignore the left half
        if (arr[mid] < target)
            low = mid + 1;

        // If the target is smaller, ignore the right half
        else
            high = mid - 1;
    }

    // Target not found
    return -1;
}

int main() {
    int size, target;

    // Input size of array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    printf("Enter %d sorted elements of the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target element
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, size, target);

    // Output result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
