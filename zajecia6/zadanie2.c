#include <stdio.h>

int main() {
    int tablica[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int* wsk = tablica; // Wskaźnik wsk na początek tablicy

    for (int i = 0; i < 10; i++) {
        printf("%d ", *wsk); // Wyświetl wartość wskazywaną przez wskaźnik
        wsk++; // Inkrement wskaźnika, aby wskazywał na następny element
    }
    return 0;
}
