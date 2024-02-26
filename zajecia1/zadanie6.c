#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void wyswietl_informacje(int suma_wynikow[], int ruchy_gracza[], int ruchy_komputera[], int wyniki[], int ilosc_rund) { //metoda do wyswietlania wynikow
    char slownik_ruchy[3][10] = {"Papier", "Kamien", "Nozyce"}; //tablica z mozliwymi ruchami
    char slownik_wyniki[3][10] = {"Remis", "Gracz", "Komputer"}; //tablica z mozliwymi wynikami

    printf("Gracz: %d Komputer: %d Remis: %d\n", suma_wynikow[1], suma_wynikow[2], suma_wynikow[0]);

    for (int i = 0; i < ilosc_rund; i++) {
        printf("Runda %d: Gracz: %s Komputer: %s Wynik: %s\n", i + 1, slownik_ruchy[ruchy_gracza[i]], slownik_ruchy[ruchy_komputera[i]], slownik_wyniki[wyniki[i]]);
    }
}

int rozegraj_runde(int ruch_gracza_num, int ruch_komputera) { //metoda do rozegrania rundy
    if (ruch_gracza_num == ruch_komputera) {
        return 0;
    } else if ((ruch_gracza_num == 0 && ruch_komputera == 1) || // papier vs kamien, wygrywa uzytkownik
               (ruch_gracza_num == 1 && ruch_komputera == 2) || // kamien vs nozyce, wygrywa uzytkownik
               (ruch_gracza_num == 2 && ruch_komputera == 0)) { // nozyce vs papier, wygrywa uzytkownik
        return 1;
    } else {
        return 2;
    }
}

int main() { //metoda glowna
    int ilosc_rund=0; //zmienna do przechowywania ilosci rund
    int wyniki[100]; //tablica do przechowywania wynikow
    int ruchy_gracza[100]; //tablica do przechowywania ruchow gracza
    int ruchy_komputera[100]; //tablica do przechowywania ruchow komputera
    int suma_wynikow[3] = {0,0,0}; //tablica do przechowywania wszystkich wynikow


    while (1) { //petla do gry
        char ruch_gracza[10];
        printf("Podaj swój ruch (papier/kamien/nozyce), lub wpisz 'scores' aby zobaczyć wyniki lub 'exit' aby wyjść: ");
        scanf("%s", ruch_gracza);

        // Zamiana na duze litery
        for (int i = 0; ruch_gracza[i]; ++i) {
            ruch_gracza[i] = toupper(ruch_gracza[i]);
        }

        if (strcmp(ruch_gracza, "SCORES") == 0) {
            wyswietl_informacje(suma_wynikow, ruchy_gracza, ruchy_komputera, wyniki, ilosc_rund);
        } else {
            int ruch_gracza_num;
            if (strcmp(ruch_gracza, "PAPIER") == 0) {
                ruch_gracza_num = 0;
            } else if (strcmp(ruch_gracza, "KAMIEN") == 0) {
                ruch_gracza_num = 1;
            } else if (strcmp(ruch_gracza, "NOZYCE") == 0) {
                ruch_gracza_num = 2;
            } else if (strcmp(ruch_gracza, "EXIT") == 0) {
                break;
            } else {
                printf("Niepoprawny ruch. Wprowadź poprawną wartość.\n");
                continue;
            }

            int ruch_komputera = rand() % 3; //losowanie ruchu komputera
            int wynik = rozegraj_runde(ruch_gracza_num, ruch_komputera); //rozegranie rundy
            wyniki[ilosc_rund] = wynik; //zapisanie wyniku
            ruchy_gracza[ilosc_rund] = ruch_gracza_num; //zapisanie ruchu gracza
            ruchy_komputera[ilosc_rund] = ruch_komputera; //zapisanie ruchu komputera
            ilosc_rund++; //zwiekszenie ilosci rund
            printf("Wynik rundy: "); //wypisanie wyniku rundy
            if (wynik == 0) {
                printf("Remis\n");
                suma_wynikow[0]++;
            } else if (wynik == 1) {
                printf("Gracz wygrywa\n");
                suma_wynikow[1]++;
            } else {
                printf("Komputer wygrywa\n");
                suma_wynikow[2]++;
            }


        }
    }
}
