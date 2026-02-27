#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int PARTITION(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;

    while (i <= j) {
        while (i < high && A[i] <= pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i < j)
            swap(&A[i], &A[j]);
    }
    swap(&A[low], &A[j]);
    return j;
}

void QUICKSORT(int A[], int low, int high) {
    if (low < high) {
        int mid = PARTITION(A, low, high);
        QUICKSORT(A, low, mid - 1);
        QUICKSORT(A, mid + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    QUICKSORT(A, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    return 0;
}