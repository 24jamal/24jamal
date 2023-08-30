// Doubly Linked List And their Operations:
#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
    struct lnode *prev;
};
typedef struct lnode node;

node *head1 = NULL;
node *tail1 = NULL;
node *head2 = NULL;
node *tail2 = NULL;

// 1 : insertAtBeginning

void insertAtBeginning(node **head, node **tail, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }
    int data = val;

    if ((*head) == NULL)
    {
        newNode->data = val;
        newNode->next = NULL;
        newNode->prev = NULL;
        *head = newNode;
        *tail = newNode;
        return;
    }

    else
    {
        newNode->data = val;
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
        (*head) = newNode;
    }

    printf("Inserted at beginning is %d", val);
}

void insAtPos(node **head, node **tail, int pos, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }

    node *temp = (*head);
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid Position");
            return;
        }
    }
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next == NULL)
    {
        (*tail) = newNode;
        temp->next = newNode;
    }

    else
    {

        temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("Inserted at postion %d is %d", pos, val);
}

// displayAll
void displayAll(node **head)
{
    node *temp = (*head);
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
    printf("\n");
}

void displayRev(node **tail)
{

    node *temp = (*tail);
    if (tail == NULL)
    {
        printf("List is empty");
        return;
    }
    // printf("ELements of Rev list are:\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void delAtPos(node **head, node **tail, int pos)
{
    node *temp = (*head);
    node *prev = temp;

    if ((*head) == NULL)
    {
        printf("List is Empty");
        return;
    }

    if (pos == 0)
    {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
    }

    for (int i = 1; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;

    if (temp == NULL)
    {
        printf("Invalid Position");
        return;
    }

    if (temp->next == NULL)
    {
        (*tail) = prev;
    }
    else
    {
        temp->next->prev = prev;
    }
    printf("Deleted at pos %d is %d", pos, temp->data);
    free(temp);
    return;
}

// Main Menu
int main()
{
    /*
        insertAtBeginning(&head1, &tail1, 3);
        insertAtBeginning(&head1, &tail1, 45);
        insertAtBeginning(&head1, &tail1, 33);
        displayAll(&head1);
        insertAtBeginning(&head2, &tail2, 55);
        insertAtBeginning(&head2, &tail2, 77);
        insertAtBeginning(&head2, &tail2, 88);
        displayAll(&head2);
    */

    int choice, pos, val, ListNo;

    while (1)
    {

        printf("Enter 1 for insert at beginning \n");
        printf("Enter 2 for Display All :\n");
        printf("Enter 3 for Display Reverse \n");
        /*
        printf("Enter 4 for Insert At Position\n");
        printf("Enter 5 for Delete at position\n");
        */

        printf("Enter 15 for exit: \n");
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter 1 to add in List1 : 2 for to add in List 2 : Enter 0 for exit: ");
            scanf("%d", &ListNo);
            printf("Enter the value : ");
            scanf("%d", &val);

            if (ListNo == 1)
            {
                insertAtBeginning(&head1, &tail1, val);
            }
            else if (ListNo == 2)
            {
                insertAtBeginning(&head2, &tail2, val);
            }
            else
            {
                printf("Enter the valid List no:");
            }

            break;
        }

        case 2:
        {
            printf("List 1 Elements are :\n");
            displayAll(&head1);
            printf("List 2 Elements are :\n");
            displayAll(&head2);
            break;
        }
        case 3:
        {
            printf("Reverse List - 1 Elements are : \n");
            displayRev(&tail1);
            printf("Reverse List - 2 Elements are : \n");
            displayRev(&tail2);
            break;
        }

        case 4:
        {
            printf("Enter 1 to add in List1 : 2 for to add in List 2 : Enter 0 for exit: ");
            scanf("%d", &ListNo);
            printf("Enter the position : ");
            scanf("%d", &pos);
            printf("Enter the value : ");
            scanf("%d", &val);

            if (ListNo == 1)
            {
                insAtPos(&head1, &tail1, val, pos);
            }
            else if (ListNo == 2)
            {
                insAtPos(&head2, &tail2, val, pos);
            }
            else
            {
                printf("Enter the valid List no:");
            }

            break;
        }

        case 5:
        {
            int pos;
            printf("Enter 1 to add in List1 : 2 for to add in List 2 : Enter 0 for exit: ");
            scanf("%d", &ListNo);
            printf("Enter the position:");
            scanf("%d", &pos);

            if (ListNo == 1)
            {
                delAtPos(&head1, &tail1, pos);
            }
            else if (ListNo == 2)
            {
                delAtPos(&head2, &tail2, pos);
            }
            else
            {
                printf("Enter the valid List no:");
            }
            break;
        }

        case 15:
        {
            exit(0);
            break;
        }
        }
    }
}
/*





         case 5:
         {

         }



         default:
         {
             printf("Enter the valid input");
         }
         }
     }

     */