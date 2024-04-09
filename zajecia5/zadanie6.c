#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void add_first(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    new_node->next = *head;

    *head = new_node;
}
// dodawanie elementu na koniec listy
void add_last(node **head, int value) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = NULL; // Nowy element staje się ostatnim

    // jeśli lista jest pusta, nowy element staje się pierwszym i ostatnim
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // przejście do ostatniego elementu
    node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    // ostatni element wskazuje na nowy
    current->next = new_node;
}

// funkcja dodająca element na określonym indeksie do listy
void add_at_index(node **head, int index, int value) {
    // sprawdzenie, czy lista jest pusta
    if (*head == NULL) {
        // Jeśli lista jest pusta, dodajemy element na początku
        add_first(&head, value);
        return;
    }

    // wskaźnik do bieżącego elementu
    node *current = *head;

    // wskaźnik do poprzedniego elementu
    node *prev = NULL;

    // przechodzenie przez listę do momentu znalezienia miejsca do wstawienia
    int i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    // jeśli przekroczono zakres listy, dodajemy element na końcu
    if (current == NULL) {
        add_last(&head, value);
        return;
    }

    // utworzenie nowego elementu
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = value;

    // wstawienie nowego elementu
    if (prev == NULL) {
        *head = new_node;
    } else {
        prev->next = new_node;
    }

    new_node->next = current;
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    add_first(&head, 10);
    add_first(&head, 20);

    add_at_index(&head, 0, 30);

    print_list(head);

    return 0;
}
