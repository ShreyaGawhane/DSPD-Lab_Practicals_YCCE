//ShreyaGawhane-IT-B-120 
/*Write a program to insert Number of Nodes in the Binary Tree and Traverse in Inorder , Preorder and Post Order and  Search an element in
Binary Tree(Display NULL if not found, If found Display Found)*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}
void inorder(struct node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct node* search(struct node* root, int key) {
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
int main() {
    struct node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    printf("\n\nEnter element to search: ");
    scanf("%d", &key);
    struct node* result = search(root, key);
    if(result != NULL)
        printf("Found\n");
    else
        printf("NULL\n");
    return 0;

}
