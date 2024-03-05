#include <stdio.h>
#include <stdlib.h>

#define max 100

int **alokuj_macierz(int wiersze, int kolumny) {
    int **macierz = malloc(wiersze * sizeof(int *)); // alokacja pamięci dla wierszy
    for (int i = 0; i < wiersze; i++) {
        macierz[i] = malloc(kolumny * sizeof(int)); // alokacja pamięci dla kolumn
    }
    return macierz;
}

void zwolnij_macierz(int **macierz, int wiersze) {
    for (int i = 0; i < wiersze; i++) {
        free(macierz[i]); // zwolnienie pamięci zaalokowanej dla kolumn
    }
    free(macierz); // zwolnienie pamięci zaalokowanej dla wierszy
}

void wypelnij_macierz(int **macierz, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = rand() % max+1; // losowa liczba z zakresu 1-100
        }
    }
}

void wyswietl_macierz(int **macierz, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%d ", macierz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int wiersze, kolumny;

    // Pobieranie rozmiarów macierzy od użytkownika
    printf("Podaj liczbę wierszy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbę kolumn: ");
    scanf("%d", &kolumny);

    // Alokacja pamięci dla macierzy
    int **macierz = alokuj_macierz(wiersze, kolumny);

    // Wypełnianie macierzy losowymi liczbami
    wypelnij_macierz(macierz, wiersze, kolumny);

    // Wyświetlanie zawartości macierzy na ekranie
    printf("Zawartość macierzy:\n");
    wyswietl_macierz(macierz, wiersze, kolumny);

    // Zwolnienie zaalokowanej pamięci
    zwolnij_macierz(macierz, wiersze);

    return 0;
}
