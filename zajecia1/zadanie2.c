#include <stdio.h>

void zadanie2() {
    double grades[2][3] = {{4.5, 3.0, 5.0},  // oceny z matematyki
                         {  5.0, 4.0, 4.5}}; // oceny z fizyki
    int total_size= (sizeof(grades) / sizeof(double))/2;
    // obliczanie średnich
    double sr_matma = 0.0f, sr_fizyka = 0.0f;
    for (int i = 0; i < total_size; i++) {
        sr_matma += grades[0][i];
        sr_fizyka += grades[1][i];
    }
    sr_matma /= total_size; // liczenie sumy ocen z matematyki przez 3 uczniow
    sr_fizyka /= total_size; // liczenie sumy ocen z fizyki przez 3 uczniow

    printf("Średnia z matematyki: %2f\n", sr_matma); // wyswietlenie sredniej
    printf("Średnia z fizyki: %2f\n", sr_fizyka);   // wyswietlenie sredniej
}
int main() {
    zadanie2();
    return 0;
}


