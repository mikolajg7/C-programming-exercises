#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CONTACTS 100

typedef struct Contact { // Struktura Contact
    char imie[50]; // Imię jako tablica znaków
    char nazwisko[50]; // Nazwisko jako tablica znaków
    char numerTelefonu[10]; // Numer telefonu jako tablica znaków
} Contact;

void dodajKontakt(Contact* kontakty, int *liczbaKontaktow) { // Funkcja dodająca kontakt
    printf("Podaj imię: ");
    scanf("%s", kontakty[*liczbaKontaktow].imie);

    printf("Podaj nazwisko: ");
    scanf("%s", kontakty[*liczbaKontaktow].nazwisko);

    printf("Podaj numer telefonu: ");
    scanf("%s", kontakty[*liczbaKontaktow].numerTelefonu);

    (*liczbaKontaktow)++; // Zwiększenie liczby kontaktów
}
int znajdzKontaktPoNazwisku(Contact* kontakty, int liczbaKontaktow, const char* nazwisko) { // Funkcja wyszukiwania kontaktu po nazwisku
    for (int i = 0; i < liczbaKontaktow; i++) {
        if (strcmp(kontakty[i].nazwisko, nazwisko) == 0) {
            return i; // Indeks znalezionego kontaktu
        }
    }
    return -1; // Kontaku nie znaleziono
}

int usunKontaktPoNazwisku(Contact* kontakty, int *liczbaKontaktow, const char* nazwisko) { // Funkcja usuwania kontaktu po nazwisku
    int index = znajdzKontaktPoNazwisku(kontakty, *liczbaKontaktow, nazwisko);

    if (index == -1) {
        return -1; // Kontakt nie znaleziony
    }

    // Przesunięcie elementów tablicy
    for (int i = index; i < *liczbaKontaktow - 1; i++) {
        kontakty[i] = kontakty[i + 1];
    }

    (*liczbaKontaktow)--;

    return 0;
}
void wyswietlWszystkieKontakty(Contact* kontakty, int liczbaKontaktow) { // Funkcja wypisywania wszystkich kontaktów w książce adresowej
    for (int i = 0; i < liczbaKontaktow; i++) {
        printf("Imię: %s\n", kontakty[i].imie);
        printf("Nazwisko: %s\n", kontakty[i].nazwisko);
        printf("Numer telefonu: %s\n\n", kontakty[i].numerTelefonu);
    }
}
int main() {
    Contact kontakty[MAX_CONTACTS]; // Tablica kontaktów
    int liczbaKontaktow = 0; // Liczba kontaktów

    // Dodanie 10 przykładowych kontaktów
    for (int i = 0; i < 10; i++) {
        sprintf(kontakty[i].imie, "Imię%d", i + 1);
        sprintf(kontakty[i].nazwisko, "Nazwisko%d", i + 1);
        // Generowanie losowego numeru telefonu
        for (int j = 0; j < 9; j++) {
            kontakty[i].numerTelefonu[j] = '0' + rand() % 10;
        }
        kontakty[i].numerTelefonu[9] = '\0';
        liczbaKontaktow++;
    }

    int wybor;
    char nazwisko[50];

    do {
        // Wyświetlenie menu
        printf("1. Dodaj kontakt\n");
        printf("2. Wyszukaj kontakt po nazwisku\n");
        printf("3. Usuń kontakt po nazwisku\n");
        printf("4. Wyświetl wszystkie kontakty\n");
        printf("0. Wyjście\n");

        // Pobranie wyboru użytkownika
        scanf("%d", &wybor);

        // Obsługa wyboru
        switch (wybor) {
            case 1:
                dodajKontakt(kontakty, &liczbaKontaktow);
                break;
            case 2:
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);

                int index = znajdzKontaktPoNazwisku(kontakty, liczbaKontaktow, nazwisko);

                if (index == -1) {
                    printf("Kontakt nie znaleziony.\n");
                } else {
                    printf("Imię: %s\n", kontakty[index].imie);
                    printf("Numer telefonu: %s\n", kontakty[index].numerTelefonu);
                }

                break;
            case 3:
                printf("Podaj nazwisko: ");
                scanf("%s", nazwisko);

                if (usunKontaktPoNazwisku(kontakty, &liczbaKontaktow, nazwisko) == -1) {
                    printf("Kontakt nie znaleziony.\n");
                } else {
                    printf("Kontakt usunięty.\n");
                }

                break;
            case 4:
                wyswietlWszystkieKontakty(kontakty, liczbaKontaktow);
                break;
            case 0:
                // Wyjście z programu
                break;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    } while (wybor != 0);

    return 0;
}



