#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

char **split(const char *s, char delimiter, int *outSize) {
    char **result = NULL;
    int size = 0;
 char *str = (char *)malloc(strlen(s) + 1);
    strcpy(str, s);
    char *token = strtok(str, " ");
    while (token) {
        size++;
        result = (char **)realloc(result, size * sizeof(char *));
        result[size - 1] = (char *)malloc(strlen(token) + 1);
        strcpy(result[size - 1], token);
        token = strtok(NULL, " ");
    }
    *outSize = size;
    free(str);
    return result;
}

int main() {
    FILE *fp = fopen("testdata.in", "r");
    if (!fp) {
        printf("File not found.\n");
        return 1;
    }

    char line1[MAX_LINE];
    char line2[MAX_LINE];
    if (fgets(line1, MAX_LINE, fp) == NULL) {
        printf("Error reading first line.\n");
        return 1;
    }
    if (fgets(line2, MAX_LINE, fp) == NULL) {
        printf("Error reading second line.\n");
        return 1;
    }

    // Remove newline characters
    if (strlen(line1) > 0 && line1[strlen(line1) - 1] == '\n') {
        line1[strlen(line1) - 1] = '\0';
    }
    if (strlen(line2) > 0 && line2[strlen(line2) - 1] == '\n') {
        line2[strlen(line2) - 1] = '\0';
    }

    // Split the first line into elements
    int n;
    char **elements = split(line1, ' ', &n);
    if (n == 0) {
        printf("No elements found in the first line.\n");
        return 1;
    }

    // Set the target
    char *target = line2;

    int low = 0;
    int high = n - 1;
    int found = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(elements[mid], target);

        printf("low[i]: %d, high[i]: %d, mid[i]: %d, mid_value: %s\n", low, high, mid, elements[mid]);

        if (cmp < 0) {
            printf("%s > %s (search right)\n", target, elements[mid]);
            low = mid + 1;
        } else if (cmp > 0) {
            printf("%s < %s (search left)\n", target, elements[mid]);
            high = mid - 1;
        } else {
            printf("%s found (i = %d)\n", target, mid);
            found = mid;
            break;
        }
    }

    if (found == -1) {
        printf("%s not found in the array.\n", target);
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(elements[i]);
    }
    free(elements);

    fclose(fp);
    // printf('\n');
    return 0;
}