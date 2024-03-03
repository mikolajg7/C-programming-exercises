#include <stdio.h>

typedef struct Point { // Struktura Point ktora przechowuje wspolrzedne punktu na plaszczyznie
    float x;
    float y;
} Point;

typedef struct Rectangle { // Struktura Rectangle
    float dlugosc;
    float szerokosc;
} Rectangle;

float PoleProstokata(Rectangle prostokat) { // Funkcja obliczajaca pole prostokata
    return prostokat.dlugosc * prostokat.szerokosc;
}

float ObwodProstokata(Rectangle prostokat) { // Funkcja obliczajaca obwod prostokata
    return 2 * (prostokat.dlugosc + prostokat.szerokosc);
}


void zadanie3(Point* punkt, float noweX, float noweY) { // Funkcja zmieniajaca wspolrzedne punktu
    punkt->x = noweX;
    punkt->y = noweY;
}

int main() {
    Point punkt; // instancja struktury Point
    punkt.x = 1.5f; // przypisanie wartosci do pol x i y
    punkt.y = 2.75f;

    zadanie3(&punkt, 4.2f, 6.35f); // wywolanie funkcji zadanie3

    printf("Nowe współrzędne punktu: (%f, %f)\n", punkt.x, punkt.y);

    Rectangle prostokat; // instancja struktury Rectangle
    prostokat.dlugosc = 5.0f; // przypisanie wartosci do pol dlugosc i szerokosc
    prostokat.szerokosc = 3.0f;

    printf("Pole prostokąta: %f\n", PoleProstokata(prostokat)); // wywolanie funkcji PoleProstokata
    printf("Obwód prostokąta: %f\n", ObwodProstokata(prostokat)); // wywolanie funkcji ObwodProstokata

    return 0;
}
