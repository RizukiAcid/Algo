#include <stdio.h>
#include <string.h>

// Fungsi rekursif untuk membalik string
void reverseString(char *s, int left, int right) {
    if (left >= right) return; // Basis rekursi
    // Tukar karakter
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;
    // Panggil rekursi untuk bagian yang lebih kecil
    reverseString(s, left + 1, right - 1);
}

int main() {
    int N;
    scanf("%d", &N); // Baca jumlah test case

    for (int i = 1; i <= N; i++) {
        char S[1001]; // Array untuk menampung angka (maksimal 1000 digit)
        scanf("%s", S);

        int len = strlen(S);
        reverseString(S, 0, len - 1); // Balik string dengan rekursi

        // Cetak output sesuai format
        printf("Test Case #%d: %s\n", i, S);
    }

    return 0;
}
