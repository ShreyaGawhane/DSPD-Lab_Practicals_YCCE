//ShreyaGawhane-IT-B-120
/*Implement Binary search tree(BST) with following Menu operations.
1.	Search an element in BST(Display NULL if not found, If found Display Found)
2.	Insert an element in BST
3.	Delete leaf element in BST
4.	Exit*/
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
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}
struct node* search(struct node* root, int key) {
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
struct node* deleteLeaf(struct node* root, int key) {
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if(key > root->data)
        root->right = deleteLeaf(root->right, key);
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else {
            printf("Not a leaf node, Cannot delete.\n");
            return root;
        }
    }
    return root;
}
int main() {
    struct node* root = NULL;
    struct node* result;
    int choice, value;
    while(1) {
        printf("\n1. Search\n2. Insert\n3. Delete Leaf Node\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value to search: ");
                scanf("%d", &value);
                result = search(root, value);
                if(result != NULL)
                    printf("Found\n");
                else
                    printf("NULL\n");
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 3:
                printf("Enter leaf value to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;

}
