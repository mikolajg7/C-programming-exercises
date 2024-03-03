#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Student { // Struktura Student
    char imie[50]; // Imię studenta jako tablica znaków
    float ocenaKoncowa; // Ocena końcowa studenta jako liczba zmiennoprzecinkowa
} Student;

void sortujStudentow(Student* studenci, int n) { // Funkcja sortująca studentów (bąbelkowo)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (studenci[j].ocenaKoncowa < studenci[j + 1].ocenaKoncowa) {
                Student temp = studenci[j];
                studenci[j] = studenci[j + 1];
                studenci[j + 1] = temp;
            }
        }
    }
}

int main() {
    int liczbastudentow=150; // Liczba studentów
    Student studenci[liczbastudentow]; // Tablica studentów

    // Generowanie danych dla 100 studentów
    for (int i = 0; i < liczbastudentow; i++) {
        sprintf(studenci[i].imie, "Student%d", i + 1);
        studenci[i].ocenaKoncowa = (float)rand() / (float)RAND_MAX * 5.0;
    }

    // Posortuj studentów
    sortujStudentow(studenci, liczbastudentow);

    // Wypisz posortowaną listę studentów
    for (int i = 0; i < liczbastudentow; i++) {
        printf("%s: %.2f\n", studenci[i].imie, studenci[i].ocenaKoncowa);
    }

    return 0;
}
