#include <stdio.h>
#include <stdlib.h>

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


void iterativePreorder(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {

        struct Node* curr = stack[top--];
        printf("%d ", curr->data);

        if (curr->right != NULL) {
            stack[++top] = curr->right;
        }
        if (curr->left != NULL) {
            stack[++top] = curr->left;
        }
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Iterative Preorder Traversal: ");
    iterativePreorder(root);
    printf("\n");

    return 0;
}

