#include <stdio.h>

void swap(int *a, int *b) {  // zamiana miejscami
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *array, int start, int end) { //
    if (start == end) { // jesli start==end to wypisujemy tablice
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            swap(&array[start], &array[i]); // zamiana miejscami
            permute(array, start + 1, end); // rekurencja
            swap(&array[start], &array[i]); // cofamy zamiane
        }
    }
}

int main() {
    int array[] = {1, 2, 3}; // tablica do permutacji
    int n = sizeof(array) / sizeof(array[0]); // rozmiar tablicy
    permute(array, 0, n - 1); // wywolanie funkcji
    return 0;
}
