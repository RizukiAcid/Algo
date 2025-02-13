#include <stdio.h>

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int arr[100];
    int count = 0;
    while (fscanf(file, "%d", &arr[count]) != EOF && count < 100) {
        count++;
    }
    fclose(file);

    printf("Before: ");
    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                for (int k = 0; k < count; k++) {
                    printf("%d", arr[k]);
                    if (k < count - 1) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }

    printf("After: ");
    for (int i = 0; i < count; i++) {
        printf("%d", arr[i]);
        if (i < count - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}