#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int compare(const char *a, const char *b) {
    bool a_letter = (strlen(a) == 1 && isalpha(a[0]));
    bool b_letter = (strlen(b) == 1 && isalpha(b[0]));

    if (a_letter && b_letter) {
        if (a[0] < b[0]) return -1;
        else if (a[0] > b[0]) return 1;
        else return 0;
    } else if (a_letter) {
        return 1;
    } else if (b_letter) {
        return -1;
    } else {
        long a_num = strtol(a, NULL, 10);
        long b_num = strtol(b, NULL, 10);
        if (a_num < b_num) return -1;
        else if (a_num > b_num) return 1;
        else return 0;
    }
}

int main() {
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[1024] = {0};
    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Error reading first line\n");
        fclose(fp);
        return 1;
    }

    int list_size = 0;
    char *token = strtok(buffer, " ");
    while (token) {
        list_size++;
        token = strtok(NULL, " ");
    }

    char **list = (char **)malloc(list_size * sizeof(char *));
    if (!list) {
        printf("Memory allocation error\n");
        fclose(fp);
        return 1;
    }

    token = strtok(buffer, " ");
    for (int i = 0; i < list_size; i++) {
        list[i] = (char *)malloc(strlen(token) + 1);
        if (!list[i]) {
            printf("Memory allocation error\n");
            fclose(fp);
            for (int j = 0; j < i; j++) free(list[j]);
            free(list);
            return 1;
        }
        strcpy(list[i], token);
        token = strtok(NULL, " ");
    }

    if (fgets(buffer, sizeof(buffer), fp) == NULL) {
        printf("Error reading target\n");
        fclose(fp);
        free(list);
        return 1;
    }

    size_t end = strlen(buffer);
    if (end > 0 && buffer[end - 1] == '\n') {
        buffer[end - 1] = '\0';
    }

    char *target = (char *)malloc(end + 1);
    if (!target) {
        printf("Memory allocation error\n");
        fclose(fp);
        free(list);
        return 1;
    }
    strcpy(target, buffer);

    fclose(fp);

    int low = 0;
    int high = list_size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        printf("low[i]: %d, high[i]: %d, mid[i]: %d, mid_value: %s\n", low, high, mid, list[mid]);

        int cmp = compare(target, list[mid]);
        if (cmp == 0) {
            printf("%s found (i = %d)\n", target, mid);
            break;
        } else if (cmp < 0) {
            high = mid - 1;
            printf("%s comes before %s (search left)\n", target, list[mid]);
        } else {
            low = mid + 1;
            printf("%s comes after %s (search right)\n", target, list[mid]);
        }
    }

    free(target);
    for (int i = 0; i < list_size; i++) {
        free(list[i]);
    }
    free(list);
    printf('\n');
    return 0;
}