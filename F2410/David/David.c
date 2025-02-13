#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define MAX_NAME_LENGTH 25

// Struct untuk menyimpan data karyawan
typedef struct {
    int employeeID;
    char name[MAX_NAME_LENGTH];
    float salary;
} Employee;

int sortingType, sortingColumn;

// Fungsi untuk menukar dua elemen Employee
void swap(Employee *a, Employee *b) {
    Employee temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort berdasarkan Employee ID
void sortByID(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((sortingType && arr[j].employeeID > arr[j + 1].employeeID) || 
                (!sortingType && arr[j].employeeID < arr[j + 1].employeeID)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Bubble Sort berdasarkan Nama
void sortByName(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((sortingType && strcmp(arr[j].name, arr[j + 1].name) > 0) || 
                (!sortingType && strcmp(arr[j].name, arr[j + 1].name) < 0)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Bubble Sort berdasarkan Gaji
void sortBySalary(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((sortingType && arr[j].salary > arr[j + 1].salary) || 
                (!sortingType && arr[j].salary < arr[j + 1].salary)) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    FILE *file = fopen("testdata.in", "r");
    if (!file) {
        printf("Error: Cannot open file employeedata.in\n");
        return 1;
    }

    int n;
    fscanf(file, "%d %d %d", &n, &sortingType, &sortingColumn);

    if (n < 1 || n > MAX_EMPLOYEES || (sortingType != 0 && sortingType != 1) || (sortingColumn < 1 || sortingColumn > 3)) {
        printf("Error: Invalid input format\n");
        fclose(file);
        return 1;
    }

    Employee employees[MAX_EMPLOYEES];

    // Membaca data karyawan
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %s %f", &employees[i].employeeID, employees[i].name, &employees[i].salary);
    }
    fclose(file);

    // Menentukan metode sorting berdasarkan kolom
    if (sortingColumn == 1) {
        sortByID(employees, n);
    } else if (sortingColumn == 2) {
        sortByName(employees, n);
    } else if (sortingColumn == 3) {
        sortBySalary(employees, n);
    }

    // Mencetak hasil setelah sorting
    for (int i = 0; i < n; i++) {
        printf("%d %s %.2f\n", employees[i].employeeID, employees[i].name, employees[i].salary);
    }
    printf("\n");
    return 0;
}