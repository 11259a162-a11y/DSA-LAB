#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int value;
    int priority;
} Element;

Element pq[MAX];
int size = 0;

int isFull() {
    return size == MAX;
}

int isEmpty() {
    return size == 0;
}

void enqueue(int value, int priority) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }
    
    pq[size].value = value;
    pq[size].priority = priority;
    size++;
    printf("Inserted: %d (Priority: %d)\n", value, priority);
}

int getHighestPriorityIndex() {
    int maxPriority = -1e9; 
    int index = -1;

    for (int i = 0; i < size; i++) {
        if (pq[i].priority > maxPriority) {
            maxPriority = pq[i].priority;
            index = i;
        } else if (pq[i].priority == maxPriority && index != -1) {
            if (pq[i].value > pq[index].value) {
                index = i;
            }
        }
    }
    return index;
}
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Nothing to remove.\n");
        return;
    }

    int index = getHighestPriorityIndex();
    printf("Dequeued: %d (Priority: %d)\n", pq[index].value, pq[index].priority);

    for (int i = index; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--; 
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    int index = getHighestPriorityIndex();
    printf("Highest Priority Element: %d (Priority: %d)\n", pq[index].value, pq[index].priority);
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue state: ");
    for (int i = 0; i < size; i++) {
        printf("[%d, P:%d] ", pq[i].value, pq[i].priority);
    }
    printf("\n");
}

int main() {
    enqueue(10, 1);
    enqueue(20, 3);
    enqueue(30, 2);
    enqueue(40, 3);

    display();

    peek();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}
