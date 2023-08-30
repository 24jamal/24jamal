// Linked List And their Operations:
#include <stdio.h>
#include <stdlib.h>

// Created At 20-08-2023 : Sunday

// Struct Declaration

struct lnode
{
    int data;
    struct lnode *next;
};
typedef struct lnode node;

node *head = NULL;

// 1 : insertAtBeginning

void insertAtBeginning(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }
    int data = val;
    if (head == NULL)
    {
        newNode->data = val;
        newNode->next = NULL;
        head = newNode;
        return;
    }

    else
    {
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    printf("Inserted at beginning is %d", val);
}

// 2 : displayAll
void displayAll()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    printf("ELements of list are:\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// 3 : insertAtPos
void insertAtPos(int pos, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }

    node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted at postion %d is %d", pos, val);
}
// 4 deleteAtPos
void deleteAtPos(int pos)
{
    node *temp = head;
    node *prev = temp;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    for (int i = 1; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    printf("Deleted at pos %d is %d", pos, temp->data);
    free(temp);
    return;
}
// 5 deleteatBegin
void deleteatBegin(int pos)
{
    node *temp = head;
    node *prev = temp;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }

    if (pos == 0)
    {
        head = head->next;
        printf("Deleted at beginning : %d", temp->data);
        free(temp);
        return;
    }
    printf("Invalid Postion");
}
// 6 insertAtEnd
/*void insertAtEnd(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }

    node *temp = head;
    for (int i = 0; i <= 100; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            newNode->data = val;
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Element inserted at end is %d", val);
            return;
        }
    }
}

*/

// Not by me done by chatgpt:
void insertAtEnd(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode; // List was empty, newNode is the only node
        printf("Element inserted at end is %d", val);
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    printf("Element inserted at end is %d", val);
}

// 7 CountAll
void CountAll()
{
    int count = 0;
    node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    while (temp != NULL)
    {
        // printf("%d ", temp->data);
        count = count + 1;
        temp = temp->next;
    }

    printf("Count of elements in list is : %d\n", count);
}
// 8 deleteAtEnd
void deleteAtEnd()
{
    node *temp = head;
    node *prev = NULL;

    if (head == NULL)
    {
        printf("List is Empty");
        return;
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL)
    {
        head = NULL;
    }

    else
    {
        prev->next = NULL;
    }

    printf("Deleted at End pos is %d", temp->data);
    free(temp);
    return;
}
// 9 readAtPos
void readAtPos(int pos)
{
    node *temp = head;
    for (int i = 1; i <= pos; i++)
    {
        temp = temp->next;
    }

    printf("Value at postion %d is %d", pos, temp->data);
    return;
}

// 10 UpdateThevalue
void updateTheValue(int pos, int val)
{
    node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    for (int i = 1; i <= pos; i++)
    {
        temp = temp->next;
    }

    temp->data = val;

    printf("Upatated Value at postion %d is %d", pos, val);
    return;
}

void searchTheList(int val)
{
    int counter = 0;
    node *temp = head;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    while (temp != NULL)
    {
        temp = temp->next;

        counter = counter + 1;
        if (temp->data == val)
        {

            printf("Element %d is presented at position : %d ", val, counter);
            break;
        }
        else
        {
            printf("Element is not found \n");
        }
    }

    return;
}

// Main Menu
int main()
{
    int choice, pos, val;

    while (1)
    {

        printf("Enter 1 for insert at beginning \n");
        printf("Enter 2 for Display All \n");
        printf("Enter 3 for Insert At position\n");
        printf("Enter 4 for delete at postion\n");
        printf("Enter 5 for Delete at beginning\n");
        printf("Enter 6 for Insert at End\n");
        printf("Enter 7 for Count the elements in list\n");
        printf("Enter 8 for Delete at end\n");
        printf("Enter 9 for read \n");
        printf("Enter 10 for Update the exiting value at position:\n");
        printf("Enter 11 for Search the element : \n");
        printf("Enter 15 for exit: \n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the data:");
            scanf("%d", &val);
            insertAtBeginning(val);
            break;
        }

        case 2:
        {
            displayAll();
            break;
        }

        case 3:
        {
            printf("Enter the position: ");
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("Invalid postion");
            }
            printf("Enter the value:");
            scanf("%d", &val);
            insertAtPos(pos, val);
            break;
        }

        case 4:
        {
            printf("Enter the postion");
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("Invalide position");
                return;
            }
            deleteAtPos(pos);
            break;
        }
        case 5:
        {
            int pos = 0;
            deleteatBegin(pos);
            break;
        }
        case 6:
        {
            printf("Enter the data:");
            scanf("%d", &val);
            insertAtEnd(val);
            break;
        }

        case 7:
        {
            CountAll();
            break;
        }

        case 8:
        {
            deleteAtEnd();
            break;
        }
        case 9:
        {
            printf("Enter the position : (Starts from 0) ");
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("Enter the valid Position");
            }
            readAtPos(pos);
            break;
        }
        case 10:
        {
            printf("Enter the postion: (Starts from 0) ");
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("Enter the valid position ");
            }
            printf("Enter the Updating value: ");
            scanf("%d", &val);
            updateTheValue(pos, val);
            break;
        }

        case 11:
        {
            printf("Enter the number to search:");
            scanf("%d", &val);
            searchTheList(val);
            break;
        }

        case 15:
        {
            exit(0);
            break;
        }

        default:
        {
            printf("Enter the valid input");
        }
        }
    }
    return 0;
}