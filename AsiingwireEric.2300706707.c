#include <stdio.h>
#include <stdlib.h>

struct Node {
    int number;
    struct Node *next;
};

struct Node *createNode(int number) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Unable to allocate memory for a new node\n");
        exit(1);
    }

    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}

void prepend(struct Node **head, int num) {
    struct Node *newNode = createNode(num);
    newNode->next = *head;
    *head = newNode;
}

void append(struct Node **head, int num) {
    struct Node *newNode = createNode(num);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(struct Node *head) {
    struct Node *current = head;
    printf("[");
    while (current != NULL) {
        printf("%d", current->number);
        current = current->next;

        if (current != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

void deleteByValue(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->number != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("Node with value %d deleted successfully.\n", value);
}


int getMenuChoice() {
    int choice;
    printf("\nLinked List Operations\n");
    printf("1. Print List\n");
    printf("2. Append\n");
    printf("3. Prepend\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Node *head = NULL;
    int choice, data;

    do {
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            printList(head);
            break;
        case 2:
            printf("Enter data to append: ");
            scanf("%d", &data);
            append(&head, data);
            break;
        case 3:
            printf("Enter data to prepend: ");
            scanf("%d", &data);
            prepend(&head, data);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
