#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
};

typedef struct lnode node;

node *last = NULL;

void insAtBegin(int val)
{

    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }
    else
    {
        newNode->data = val;
        if (last == NULL) // Initially list is empty
        {
            newNode->next = newNode;
            last = newNode;
        }
        else
        {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    printf("%d is inserted at beginnning", val);

    return;
}

void insAtEnd(int val)
{

    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }

    newNode->data = val;
    if (last == NULL)
    {
        newNode->next = newNode;
        last = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    return;
}

void displayAll()
{
    int counter = 0;
    node *temp = last;
    if (last == NULL)
    {
        printf("List is Empty");
        return;
    }

    else
    {
        do
        {
            printf("%d ", temp->next->data);
            temp = temp->next;
            counter = counter + 1;

        } while (temp != last);
    }

    printf("counter = %d", counter);
}
node *del;
void delAtBeg()
{
    if (last == NULL)
    {
        printf("List is Empty");
    }

    if (last->next == last)
    {
        del = last;
        last = NULL;
    }

    del = last->next;
    last->next = last->next->next;
    printf("Deleted value is %d", del->data);
    free(del);
}

void delAtEnd()
{
    node *del, *temp;
    if (last == NULL)
    {
        printf("List is Empty");
    }

    if (last->next == last)
    {
        del = last;
        last = NULL;
    }
    else
    {

        temp = last->next;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        del = last;
        temp->next = last->next;
        last = temp;
    }
    printf("Deleted at end is %d", del->data);
    free(del);
}

int main()
{
    int choice, val, pos;
    while (1)
    {
        printf("Enter 1 - Insert At begin 2 - Insert At End 3-Display 4.Del At Begin 5.Del at End 6-Exit ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value to insert at Beginning: ");
            scanf("%d", &val);
            insAtBegin(val);
            break;
        }

        case 2:
        {
            printf("Enter the value to insert at End :");
            scanf("%d", &val);
            insAtEnd(val);
            break;
        }

        case 3:
        {
            displayAll();
            break;
        }

        case 4:
        {
            delAtBeg();
            break;
        }
        case 5:
        {
            delAtEnd();
            break;
        }

        case 6:
        {
            exit(0);
            break;
        }
        }
    }
    return 0;
}