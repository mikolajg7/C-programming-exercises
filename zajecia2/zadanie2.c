#include <stdio.h>

void zadanie2(float* wskaznikdozmiennej) { // funkcja przyjmuje wskaźnik do zmiennej typu float
    *wskaznikdozmiennej *= 2; // mnożenie wartości zmiennej przez 2
}
int main() {
    float liczba = 5.5f; // zmienna typu float z wartością 5.5
    float* wskaznik = &liczba; // wskaźnik do zmiennej liczba

    zadanie2(wskaznik);

    printf("Nowa wartość zmiennej: %f\n", liczba); // wyświetlenie nowej wartości zmiennej

    return 0;
}
