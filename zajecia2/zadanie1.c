#include <stdio.h>

void zadanie1() {
    int liczba = 10; // zmienna typu int z wartością 10
    int* wskaznik = &liczba; // wskaźnik do zmiennej liczba
    printf("Wartość zmiennej: %d\n", liczba); // wyświetlenie wartości zmiennej
    printf("Wartość zmiennej pobrana przez wskaźnik: %d\n", *wskaznik); // wyświetlenie wartości zmiennej pobranej przez wskaźnik
}

int main() {
    zadanie1();
    return 0;
}
