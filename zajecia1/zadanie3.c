#include <stdio.h>
#define SIZE 10

void zadanie3(int array[]){
    for (int i = 0; i < SIZE; i++) {
        int factorial = 1; // zmienna do przechowywania wyniku
        for (int j = 1; j <= array[i]; j++) { // petla for do liczenia silni
            factorial *= j;
        }
        printf("Silnia %d wynosi: %d\n", array[i], factorial); // wypisanie wyniku
    }
}
int main() {
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    zadanie3(array);
    return 0;
}
