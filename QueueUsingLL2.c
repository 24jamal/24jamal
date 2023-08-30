#include <stdio.h>
#include <stdlib.h>

struct lnode
{
    int data;
    struct lnode *next;
};

typedef struct lnode node;

node *front = NULL;
node *rear = NULL;

void enqueue(int val)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        printf("Out of Memory");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL)
    {
        rear = newNode;
        front = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued Element is %d", val);
}

void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    node *temp = front;
    front = front->next;

    if (front == NULL)
    {
        rear = NULL; // Update rear pointer if the queue is now empty
    }

    printf("Dequeued an element is %d\n", temp->data);
    free(temp); // Free memory of the dequeued node
}

void display()
{
    node *temp = front;
    while (temp != NULL)
    {

        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

int main()
{
    int choice, val;
    while (1)
    {
        printf("Enter the choice 1.Enqueue 2.Dequeue 3.Display 4.Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the value to insert");
            scanf("%d", &val);
            enqueue(val);
            break;
        }

        case 2:
        {
            display();
            break;
        }

        case 3:

        {
            dequeue();
            break;
        }

        case 4:
        {
            exit(0);
            break;
        }

        default:
        {
            printf("Error!! Enter valide input.\n");
        }
        }
    }
    return 0;
}