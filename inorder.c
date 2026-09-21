#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void inorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100]; 
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {

        while (curr != NULL) {
            stack[++top] = curr; // Push
            curr = curr->left;
        }

        curr = stack[top--];
        printf("%d ", curr->data); 

        curr = curr->right;
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Iterative Inorder: ");
    inorderIterative(root);
    printf("\n");

    return 0;
}
