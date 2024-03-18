#include <stdio.h>

long long int factorial(int n) { // funkcja rekurencyjna obliczajaca silnie
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    printf("Podaj liczbe: "); // wczytanie liczby
    scanf("%d", &n);
    printf("Silnia z %d to %lld\n", n, factorial(n));
    return 0;

}
