#include <stdio.h>

void zadanie1() {
    char imie[20]; //Tablica 20 znakow

    printf("Podaj imie: "); //Wyswietlenie pytania
    scanf("%s", imie); //Wczytanie imienia

    printf("Witaj %s!\n", imie); //Wyswietlenie imienia
}

int main() {
    zadanie1();
    return 0;
}