#include <stdio.h>

int binary_search(int *arr, int left, int right, int x) { // wyszukiwanie binarne
    if (left > right) { // jesli lewa granica jest wieksza od prawej to elementu nie ma w tablicy
        return -1;
    }
    int mid = (left + right) / 2; // srodek tablicy
    if (arr[mid] == x) { // jesli srodkowy element jest rowny x to zwracamy indeks
        return mid;
    } else if (arr[mid] < x) { // jesli srodkowy element jest mniejszy od x to szukamy w prawej czesci tablicy
        return binary_search(arr, mid + 1, right, x);
    } else { // jesli srodkowy element jest wiekszy od x to szukamy w lewej czesci tablicy
        return binary_search(arr, left, mid - 1, x);
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15}; // posortowana tablica
    int n = sizeof(arr) / sizeof(arr[0]); // rozmiar tablicy
    int x = 11; // szukany element

    int index = binary_search(arr, 0, n - 1, x); // wywolanie funkcji

    if (index == -1) {
        printf("Element %d nie został znaleziony.\n", x);
    } else {
        printf("Element %d został znaleziony na indeksie %d.\n", x, index);
    }
    return 0;
}
