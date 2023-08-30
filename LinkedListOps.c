// Not working properly
#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
    struct lnode *prev;
};

typedef struct lnode node;

node *head = NULL;
node *tail = NULL;

void insAtBegin(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory ");
        return;
    }
    newNode->data = val;
    if (head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }

    else
    {

        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
    }

    printf("Element inserted at beginning is %d", val);
    return;
}

void displayAll()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    printf("Elements of list are : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return;
}

void displayRev()
{
    node *temp = tail;
    if (tail == NULL)
    {
        printf("List is Empty");
        return;
    }

    printf("Elements of list are : ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    return;
}

void insAtPos(int pos, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory ");
        return;
    }
    node *temp = head;
    newNode->data = val;

    if (pos == 0)
    {
        insAtBegin(val);
        return;
    }
    else
    {
        for (int i = 0; i <= pos - 1; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("Invalid Positon ");
            }

            if (tail == NULL)
            {
                tail = newNode;
                temp->next = newNode;
            }

            else
            {
                temp->next->prev = newNode;
                newNode->prev = temp;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
        }
        printf("Inserted at postion %d is %d", pos, val);
        return;
    }
}

void delAtPos(int pos)
{
    node *temp = head;
    node *prev = temp;
    if (head == NULL)
    {
        printf("List is Empty:");
    }

    if (pos == 0)
    {

        head = head->next;
        printf("Deleted at position %d is %d\n", pos, temp->data);
        free(temp);
    }

    for (int i = 1; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = temp->next;
    printf("Deleted at position %d is %d\n", pos, temp->data);
    free(temp);
}

int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\nEnter 1.InsAtBegin 2.Display 3.DisplayRev 4. InstPos 5.DelAtPos 10.Exit: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value : ");
            scanf("%d", &val);
            insAtBegin(val);
            break;
        }

        case 2:
        {
            displayAll();
            break;
        }

        case 3:
        {
            displayRev();
            break;
        }

        case 4:
        {
            printf("Enter the position to insert : ");
            scanf("%d", &pos);
            printf("Enter the value: ");
            scanf("%d", &val);
            insAtPos(pos, val);
            break;
        }

        case 5:
        {
            printf("Enter the position to delete : ");
            scanf("%d", &pos);
            delAtPos(pos);
            break;
        }

        case 10:
        {
            exit(0);
            break;
        }

        default:
        {
            printf("Enter Valid Input!!\n");
        }
        }
    }
}