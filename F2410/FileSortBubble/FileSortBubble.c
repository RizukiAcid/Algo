#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        printf("Error: Could not open file testdata.in\n");
        return 1;
    }
    
    int arr[MAX_SIZE];
    int n = 0;
    while (n < MAX_SIZE && fscanf(fp, "%d", &arr[n]) == 1) {
        n++;
    }
    fclose(fp);
    
    // Print the array before sorting
    printf("Before: ");
    printArray(arr, n);
    
    // Bubble sort with printing intermediate steps after each outer iteration
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Print intermediate state after each outer loop iteration
        printArray(arr, n);
    }
    
    // Print the final sorted array
    printf("After: ");
    printArray(arr, n);
    
    return 0;
}
