#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

// dodawanie elementu na początek listy
void add_first(node **head, int data) {
    // utworzenie nowego elementu
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;

    // połączenie nowego elementu z początkiem listy
    new_node->next = *head;

    // ustawienie nowego elementu jako nagłówka listy
    *head = new_node;
}

// printowanie listy
void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // stworzenie listy
    node *head = NULL;
    add_first(&head, 10);
    add_first(&head, 20);
    add_first(&head, 30);

    // sydrukowanie listy
    print_list(head);

    return 0;
}

