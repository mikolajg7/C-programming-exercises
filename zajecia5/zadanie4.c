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

// usuwanie na podstawie indeksu
void remove_by_index(node **head, int index) {
    // sprawdzenie, czy lista jest pusta
    if (*head == NULL) {
        return;
    }

    // wskaźnik do bieżącego elementu
    node *current = *head;

    // wskaźnik do poprzedniego elementu
    node *prev = NULL;

    // przechodzenie przez listę do momentu znalezienia elementu o danym indeksie
    int i = 0;
    while (current != NULL && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    // jeśli nie znaleziono elementu o danym indeksie
    if (current == NULL) {
        return;
    }

    // usunięcie elementu
    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
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
    add_first(&head, 30);

    remove_by_index(&head, 1);

    print_list(head);

    return 0;
}
