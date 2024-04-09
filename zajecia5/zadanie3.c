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

void remove_last(node **head) {
    // sprawdzenie, czy lista jest pusta
    if (*head == NULL) {
        return;
    }

    // wskaźnik do bieżącego elementu
    node *current = *head;

    // wskaźnik do poprzedniego elementu
    node *prev = NULL;

    // przechodzenie przez listę do momentu znalezienia ostatniego elementu
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    // jezeli lista zawiera tylko jeden element
    if (prev == NULL) {
        *head = NULL;
    } else {
        // Usunięcie ostatniego elementu
        prev->next = NULL;
    }
    free(current);
}

// print
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

    remove_last(&head);

    print_list(head);

    return 0;
}
