#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
};

typedef struct lnode node;

node *top = NULL;
void push(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
    }
    newNode->data = val;
    newNode->next = top;
    top = newNode;
    printf("Pushed element is %d", val);
    return;
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack is Empty");
        return -1;
    }
    node *del = top;
    top = top->next;
    int temp = del->data;

    printf("Popped element is %d\n", temp);
    free(del);
    return temp;
}

void peek()
{
    node *del = top;
    int temp = del->data;
    printf("Peek element is %d\n", temp);
    return;
}
void display()
{
    if (top == NULL)
    {
        printf("Stack is empty");
        return;
    }

    printf("Elements of the Stack is :\n");
    while (top != NULL)
    {

        printf("%d\n", top->data);
        top = top->next;
    }

    return;
}

int main()
{
    int choice, val;
    while (1)
    {
        printf("ENter the choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value");
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
            break;
        }

        default:
        {
            printf("Error: Enter valid input");
        }
        }
    }
}