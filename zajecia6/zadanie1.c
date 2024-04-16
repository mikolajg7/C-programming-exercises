#include <stdio.h>

union Dane { // Definicja unii do przechowywania różnych typów danych
    int liczba_calkowita;
    float liczba_zmiennoprzecinkowa;
    char znak;
};

int main() {
    union Dane dane; // Deklaracja unii
    dane.liczba_calkowita = 10;
    printf("Liczba całkowita: %d\n", dane.liczba_calkowita);

    dane.liczba_zmiennoprzecinkowa = 5.2f;
    printf("Liczba zmiennoprzecinkowa: %f\n", dane.liczba_zmiennoprzecinkowa);

    dane.znak = 'A';
    printf("Znak: %c\n", dane.znak);

    return 0;
}
