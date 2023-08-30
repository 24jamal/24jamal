#include <stdio.h>

struct lnode
{
    int data;
    struct lnode *next;
};

typedef struct lnode node;

node *head = NULL;

void insertAtBegin(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
    }

    newNode->data = val;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
    }

    else
    {
        newNode->next = head;
        head = newNode;
    }

    printf("Insertion at beginnnig Value: %d \n", val);
}

void DisplayAll()
{
    if (head == NULL)
    {
        printf("List is empty ");
        return;
    }

    node *temp = head;
    printf("Elements of list are:\n");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertAtPos(int pos, int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
    }

    newNode->data = val;
    node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Insertion at position %d as %d\n", pos, val);
}

void deleteAtPos(int pos)
{
    node *temp = head;
    node *prev = temp;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    if (pos == 0)
    {
        head = head->next;
        printf("Deleted at %d position is %d", pos, temp->data);
        free(temp);
    }

    for (int i = 1; i <= pos; i++)
    {
        prev = temp;
        temp = temp->next;
        if (temp == NULL)
        {
            printf("Invalid Position:\n");
            return;
        }
    }
    prev->next = temp->next;
    printf("Deleted at %d postion is %d", pos, temp->data);
    free(temp);
    return;
}

int main()
{
    int val, pos, choice;
    while (1)
    {
        printf("Enter the choice below: \n");
        printf("Enter 1 for - Insert at Beginning\n");
        printf("Enter 2 for - Display the list \n");
        printf("Enter 3 for - Insert at Position \n ");
        printf("Enter 4 for - Delete at Position \n");
        printf("Exit\n");
        printf("----------------------------------\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the data to insert:");
            scanf("%d", &val);
            insertAtBegin(val);
            break;
        }
        case 2:
        {
            DisplayAll();
            break;
        }

        case 3:
        {
            printf("Enter the position: (Starts from 0)");
            scanf("%d", &pos);
            if (pos < 0)
            {
                printf("Enter the valid position");
                break;
            }
            else if (pos == 0)
            {
                insertAtBegin(val);
            }
            else
            {
                printf("Enter the data to insert");
                scanf("%d", &val);
                insertAtPos(pos, val);
                break;
            }
        }

        case 4:
        {
            printf("Enter the postion to delete:");
            scanf("%d", &pos);
            deleteAtPos(pos);
            break;
        }

        case 5:

            exit(0);
            break;
        }
    }
}