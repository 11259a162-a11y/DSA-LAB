#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int value;
    int priority;
    struct Node* next;
} Node;

Node* createNode(int value, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(Node* head) {
    return head == NULL;
}

void enqueue(Node** head, int value, int priority) {
    Node* newNode = createNode(value, priority);

    if (*head == NULL || (*head)->priority < priority) {
        newNode->next = *head;
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    printf("Inserted: %d (Priority: %d)\n", value, priority);
}

void dequeue(Node** head) {
    if (isEmpty(*head)) {
        printf("Queue Underflow! Nothing to remove.\n");
        return;
    }
    Node* temp = *head;
    printf("Dequeued: %d (Priority: %d)\n", temp->value, temp->priority);
    *head = (*head)->next;
    free(temp);
}

void peek(Node* head) {
    if (isEmpty(head)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Highest Priority Element: %d (Priority: %d)\n", head->value, head->priority);
}

void display(Node* head) {
    if (isEmpty(head)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue state: ");
    Node* current = head;
    while (current != NULL) {
        printf("[%d, P:%d] ", current->value, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* pq = NULL;

    enqueue(&pq, 10, 1);
    enqueue(&pq, 20, 3);
    enqueue(&pq, 30, 2);
    enqueue(&pq, 40, 3);

    display(pq);

    peek(pq);

    dequeue(&pq);
    display(pq);

    dequeue(&pq);
    display(pq);

    return 0;
}

