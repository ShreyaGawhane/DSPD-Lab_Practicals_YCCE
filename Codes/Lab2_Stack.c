//ShreyaGawhane-IT-B-120 
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x)
{
    if(top == MAX-1)
        printf("Overflow! Stack full.\n");
    else
    {
        stack[++top] = x;
        printf("%d pushed.\n", x);
    }
}
void pop()
{
    if(top == -1)
        printf("Underflow! Stack empty.\n");
    else
        printf("%d popped.\n", stack[top--]);
}
void display()
{
    if(top == -1)
        printf("Stack is empty.\n");
    else
    {
        printf("Stack: ");
        for(int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}
void palindrome()
{
    int n, temp, rev = 0;
    printf("Enter number: ");
    scanf("%d", &n);
    temp = n;
    top = -1;

    while(temp > 0)
    {
        push(temp % 10);
        temp = temp / 10;
    }

    while(top != -1)
        rev = rev * 10 + stack[top--];

    if(rev == n)
        printf("%d is palindrome.\n", n);
    else
        printf("%d is not palindrome.\n", n);
}
int main()
{
    int ch, val;
    while(1)
    {
        printf("\n1.Push  2.Pop  3.Display  4.Palindrome  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                palindrome();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}