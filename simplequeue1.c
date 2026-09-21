#include <stdio.h>
#include <stdbool.h>

#define SIZE 5 

int queue[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (rear == SIZE - 1);
}

bool isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front == -1) {
        front = 0;
    }
    
    rear++;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    
    printf("Deleted: %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Demonstration
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60); 
    display();

    return 0;
}
