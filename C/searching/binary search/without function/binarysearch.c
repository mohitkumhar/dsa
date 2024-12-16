#include <stdio.h>

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

    // Input the target element to search for
    printf("Enter the target element to search for: ");
    scanf("%d", &target);

    int low = 0, high = size - 1;
    int result = -1; // To store the index of the target if found

    // Binary search logic
    while (low <= high) {
        int mid = low + (high - low) / 2; // To prevent overflow

        if (arr[mid] == target) {
            result = mid;
            break;
        } else if (arr[mid] < target) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    // Output the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}
