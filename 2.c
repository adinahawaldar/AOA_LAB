#include <stdio.h>

int BinarySearch(int array[], int start_index, int end_index, int KEY) {
    if (end_index >= start_index) {
        int middle = start_index + (end_index - start_index) / 2;
        if (array[middle] == KEY)
            return middle;
        if (array[middle] > KEY)
            return BinarySearch(array, start_index, middle - 1, KEY);
        return BinarySearch(array, middle + 1, end_index, KEY);
    }
    return -1;
}

int main() {
    int n, i, KEY, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array[n];

    printf("Enter elements in increasing order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &KEY);

    result = BinarySearch(array, 0, n - 1, KEY);

    if (result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}