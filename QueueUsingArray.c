#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int arr[MAX];
int front = -1;
int rear = -1;

void enqueue(int val)
{
    if (front == -1)
    {
        front = 1;
    }
    if (rear == MAX - 1)
    {
        printf("Queue is Full");
    }

    arr[rear] = val;
    rear++;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
        return;
    }
    printf("Dequeued element is %d", arr[front]);
    front++;
    return;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty");
        return;
    }

    for (int i = front; i <= rear; i++)
    {
        printf("%d", arr[i]);
    }
    return;
}

void count()
{
    int count = 0;
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
        return;
    }
    for (int i = front; i <= rear; i++)
    {
        count = count + 1;
    }
    printf("Number of Elements in Queue is %d", count + 1);
    return;
}

int main()
{
    int choice, val;
    while (1)
    {
        printf("Enter choice : 1.Enqueue 2.Dequeue 3.display 4.Count 5.Exit : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value");
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
            exit(0);
            break;
        }

        default:
        {
            printf("Error !! Enter the valid Input");
            break;
        }
        }
    }
    return 0;
}