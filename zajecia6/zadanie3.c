#include <stdio.h>

int dodaj(int a, int b) { // Funkcja dodająca dwie liczby
    return a + b;
}

int mnoz(int a, int b) { // Funkcja mnożąca dwie liczby
    return a * b;
}

int odejmij(int a, int b) { // Funkcja odejmująca dwie liczby
    return a - b;
}

typedef int (*operacja_matematyczna)(int, int); // Definicja wskaźnika do funkcji

int main() {
    int a, b;
    char operacja;

    printf("Podaj dwie liczby: ");
    scanf("%d %d", &a, &b); // Pobranie dwóch liczb

    printf("Wybierz operację (+, -, *): ");
    scanf(" %c", &operacja); // Pobranie znaku operacji

    // Użycie wskaźnika do funkcji
    operacja_matematyczna fptr;
    switch (operacja) {
        case '+':
            fptr = dodaj;
            break;
        case '-':
            fptr = odejmij;
            break;
        case '*':
            fptr = mnoz;
            break;
        default:
            printf("Nieznana operacja!\n");
            return 1;
    }

    int wynik = fptr(a, b); // Wywołanie funkcji za pomocą wskaźnika
    printf("Wynik: %d\n", wynik);

    return 0;
}
