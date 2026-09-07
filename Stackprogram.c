#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1; 

void push(int value);
int pop();
int peek();
void display();
int isFull();
int isEmpty();

int main() {
    int choice, value;

    while (1) {
        printf("\n*** STACK MENU ***\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Peek (View Top)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Value at the top: %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

int isFull() {
    return top == MAX - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d onto a full stack.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d successfully pushed onto the stack.\n", value);
    }
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1; 
    } else {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (from top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-----\n");
    }
}
