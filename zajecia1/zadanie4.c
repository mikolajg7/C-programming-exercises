#include <stdio.h>

void zadanie4(){
    for (int liczba = 1; liczba <= 200; liczba++) {
        if (liczba % 5 == 0 && liczba % 7 == 0) { // jesli jest podzielna przez 5 i 7 wyswietl FooBar
            printf("FooBar\n");
        } else if (liczba % 5 == 0) { // jesli jest podzielna przez 5 wyswietl Foo
            printf("Foo\n");
        } else if (liczba % 7 == 0) { // jesli jest podzielna przez 7 wyswietl Bar
            printf("Bar\n");
        } else {
            printf("%d\n", liczba); // w przeciwnym wypadku wyswietl liczbe
        }
    }
}
int main() {
    zadanie4();
    return 0;
}