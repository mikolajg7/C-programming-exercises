#include <stdio.h>


int zadanie5(int liczba) {
    if (liczba < 0) { // jesli liczba jest mniejsza od 0 to zwracamy 0
        return 0;
    }
    int suma = 0; // suma do liczenia wielokrotnosci
    for (int i = 1; i < liczba; i++) {
        if (i % 3 == 0 || i % 5 == 0) { // jesli liczba jest podzielna przez 3 lub 5 to dodajemy ja do sumy
            suma += i;
        }
    }
    return suma;
}
int main() {
    printf("%d\n", zadanie5(10));
    printf("%d\n", zadanie5(15));
    printf("%d\n", zadanie5(1000));
    printf("%d\n", zadanie5(-10));
    return 0;
}