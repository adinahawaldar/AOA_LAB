#include <stdio.h>

int main() {
    int n, i, j, loc, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < n - 1; i++) {
        int min = A[i];
        loc = i;

        for (j = i + 1; j < n; j++) {
            if (A[j] < min) {
                min = A[j];
                loc = j;
            }
        }

        if (loc != i) {
            temp = A[i];
            A[i] = A[loc];
            A[loc] = temp;
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}