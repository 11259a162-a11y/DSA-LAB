#include <stdio.h>
#include <stdbool.h>

#define SIZE 5 

int queue[SIZE];
int front = -1;
int rear = -1;

bool isFull() {

    return ((rear + 1) % SIZE == front);
}

bool isEmpty() {
    return (front == -1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (isEmpty()) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to delete.\n");
        return;
    }
    
    printf("Deleted: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE; 
    }
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display(); 

    dequeue(); 
    dequeue();
    display(); 

    enqueue(60);
    enqueue(70);
    display(); 

    enqueue(80); 
    return 0;
}
