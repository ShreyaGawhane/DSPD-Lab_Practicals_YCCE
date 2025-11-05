//ShreyaGawhane-IT-B-120
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main()
{
    struct node *head = NULL, *temp = NULL, *newNode;
    int value, count = 0;
    printf("Enter elements to insert in Linked List (enter 0 to stop):\n");
    while(1)
    {
        scanf("%d", &value);
        if(value == 0)
            break;

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("\nLinked List elements: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes: %d\n", count);
    return 0;
}