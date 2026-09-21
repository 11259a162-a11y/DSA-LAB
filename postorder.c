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

void postorderIterative(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {  
        struct Node* curr = stack1[top1--];
        stack2[++top2] = curr;

        if (curr->left != NULL) {
            stack1[++top1] = curr->left;
        }
        if (curr->right != NULL) {
            stack1[++top1] = curr->right;
        }
    }

    while (top2 >= 0) {
        struct Node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    printf("Iterative Postorder: ");
    postorderIterative(root);
    printf("\n");

    return 0;
}
