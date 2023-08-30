// DOne by Jamal itself
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
        printf("Memory id full");
    }

    newNode->data = val;
    newNode->next = NULL;
    if (rear == NULL) // Its run only for empty queue;
    {
        rear = newNode;
        front = newNode;
    }

    else
    {
        rear->next = newNode;
        rear = newNode;
        printf("Enqueued element is %d", val);
    }
}

void dequeue()
{

    if (rear == NULL)
    {
        printf("Queue is Empty");
    }

    node *temp = front;
    front = front->next;
    printf("Dequeued elemnt is %d", temp->data);
    free(temp);
}

void display()
{
    if (rear == NULL)
    {
        printf("Queue is Empty");
    }

    node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void count()
{
    int count = 0;
    if (rear == NULL)
    {
        printf("Queue is Empty");
        return;
    }

    node *temp = front;
    while (temp != NULL)
    {
        count = count + 1;
        temp = temp->next;
    }

    printf("No of Elements in Queue : %d\n ", count);
}

void showfirst()
{
    if (rear == NULL)
    {
        printf("Queue is Empty");
        return;
    }

    node *temp = front;
    printf("First Element in the queue is : %d\n", temp->data);
}

void showlast()
{
    if (rear == NULL)
    {
        printf("Queue is Empty");
        return;
    }

    node *temp = rear;

    printf("Last Element in the queue is: %d", temp->data);
}

int main()
{
    int choice, val;
    while (1)
    {
        printf("Enter choice 1.Enqueue 2.Dequeue 3.Display 4. Count 5.Show First 6.Show Last 10. Exit : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the elemeny to enqueue :");
            scanf("%d", &val);
            enqueue(val);
            break;
        }

        case 2:
        {
            dequeue();
            break;
        }

        case 3:
        {
            display();
            break;
        }

        case 4:
        {
            count();
            break;
        }
        case 5:
        {
            showfirst();
            break;
        }
        case 6:
        {
            showlast();
            break;
        }
        case 10:
        {
            exit(0);
            break;
        }
        }
    }
}