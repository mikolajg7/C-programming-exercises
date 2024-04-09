#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// dodawanie
void add_first(node **head, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    new_node->next = *head;

    *head = new_node;
}

// popowanie
void pop(node **head) {
    // sprawdzenie, czy lista jest pusta
    if (*head == NULL) {
        return;
    }

    // zapamiętanie wskaźnika do usuwanego elementu
    node *temp = *head;

    // Przesunięcie wskaźnika na początek listy na następny element
    *head = (*head)->next;

    // zwolnienie pamięci alokowanej dla usuwanego elementu
    free(temp);
}

// printowanie
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Stworzenie listy
    node *head = NULL;
    add_first(&head, 10);
    add_first(&head, 20);
    add_first(&head, 30);

    pop(&head);

    print_list(head);

    return 0;
}
