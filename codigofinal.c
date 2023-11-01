#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Funcion para liberar la memoria de la lista
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Funcion para agregar un nodo al inicio de la lista
void insert(int data, struct Node** head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// Funcion para agregar un nodo al final de la lista 
void append(int data, struct Node** head) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

//Funcion para eliminar un nodo por valor
void deleteByValue(int data, struct Node** head) {
    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

// Función para buscar un nodo por su valor
int findValue(int data, struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == data) {
            return 1; // Encontrado
        }
        current = current->next;
    }
    return 0; // No encontrado
}

// Funcion para obtener elemento enecimo
int getValueAt(int index, struct Node* head) {
    struct Node* current = head;
    int count = 0;

    while (current != NULL) {
        if (count == index) {
            return current->data;
        }
        count++;
        current = current->next;
    }
    printf("indice fuera de rango\n");
    return -1;
}

// Funcion para imprimir la lista
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insert(10, &head);
    append(20, &head);
    append(30, &head);

    printf("Lista: ");
    printList(head);

    int value = 20;
    if (findValue(value, head)) {
        printf("El valor %d está en la lista.\n", value);
    } else {
        printf("El valor %d no está en la lista.\n", value);
    }

    int index = 1;
    int element = getValueAt(index, head);
    if (element != -1) {
        printf("Elemento en el índice %d: %d\n", index, element);
    }

    deleteByValue(20, &head);
    printf("Lista después de eliminar el valor 20: ");
    printList(head);

    freeList(head);

    return 0;
}
