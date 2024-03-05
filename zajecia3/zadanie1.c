#include <stdio.h>

long long int wspolczynnik_dwumianowy(int n, int k) { // dla n>126 potrzeba long long int
    if (k == 0 || k == n) {
        return 1;
    } else {
        return wspolczynnik_dwumianowy(n - 1, k - 1) + wspolczynnik_dwumianowy(n - 1, k); // rekurencyjne wywołanie funkcji
    }
}
void trojkat_pascala(int n) { // funkcja rysująca trójkąt Pascala
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) { // wyrównanie do lewej
            printf("    ");
        }
        for (j = 0; j <= i; j++) {
            printf("%3lld ", wspolczynnik_dwumianowy(i, j));
        }
        printf("\n");
    }
}

int main() {
    int wysokosc;

    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &wysokosc);

    trojkat_pascala(wysokosc);

    return 0;
}
