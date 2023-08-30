#include <stdio.h>

struct lnode
{
    int data;
    struct lnode *next;
};

typedef struct lnode node;

struct queue
{
    node *front;
    node *rear;
};

struct node *Queue enqueue(int pos, int val)
{
    malloc(sizeod(Queue))
}

int main()
{
    int choice, val, qno;

    while (1)
    {
        printf("Enter the choice 1.Enqueue 2.Dequeue 3.Display 4.Exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("Enter the Queue Number : ");
            scanf("%d", &qno);
            printf("Enter the value to enqueue :");
            scanf("%d", &val);
            enqueue(qno, val);
            break;
        }

        case 2:
        {
            // dequeue();
            break;
        }

        case 3:
        {
            // display;
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        }
    }
}