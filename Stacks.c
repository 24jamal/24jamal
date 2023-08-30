#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int arr[MAX];
int top = -1;

int push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack is full");
        return;
    }
    top++;
    arr[top] = val;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is Empty");
        return;
    }
    printf("Popped element is %d\n", arr[top]);
    top--;
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is Empty");
        return;
    }
    printf("Peek element is %d\n", arr[top]);
}

int display()
{
    if (top == -1)
    {
        printf("Stack is empty");
        return;
    }

    printf("Stack elements are: \n");
    for (int i = top; i > 0; i--)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main()
{

    int choice, val;
    while (1)
    {
        printf("Enter the choice:  1.Push  2.Pop  3.Peek  4.Display : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value :");
            scanf("%d", &val);
            push(val);
            break;
        }

        case 2:
        {
            pop();
            break;
        }

        case 3:
        {
            peek();
            break;
        }

        case 4:
        {
            display();
            break;
        }

        case 5:
        {
            exit(0);
        }

        default:
        {
            printf("Enter the valid choice");
        }
        }
    }
}