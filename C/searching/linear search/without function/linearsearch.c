#include <stdio.h>

int main()
{
    int n, key, found = 0;
    printf("Enter the Length of Array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Element %dth: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter Element You want to search: ");
    scanf("%d", &key);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Not found\n");
    return 0;
}
