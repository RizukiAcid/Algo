#include <stdio.h>

#define MAX_SIZE 100

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSortWithSteps(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Print the array after this step
        printArray(arr, n);
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        printf("Error: Could not open file testdata.in\n");
        return 1;
    }

    int arr[MAX_SIZE];
    int n = 0;

    // Read integers from the file
    while (fscanf(file, "%d", &arr[n]) != EOF) {
        n++;
    }

    fclose(file);

    printf("Before: ");
    printArray(arr, n);

    // Perform insertion sort and print steps
    insertionSortWithSteps(arr, n);

    printf("After: ");
    printArray(arr, n);

    printf("\n");
    return 0;
}
