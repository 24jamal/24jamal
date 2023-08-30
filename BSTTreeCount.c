// Done by jamal
#include <stdio.h>
#include <stdlib.h>

#define COUNT 10;

struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

struct node *insert(struct node *ptr, int val)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }

    else if (val < ptr->data)
    {
        ptr->lchild = insert(ptr->lchild, val);
    }

    else if (val > ptr->data)
    {
        ptr->rchild = insert(ptr->rchild, val);
    }

    else
    {
        printf("Duplicate value exixts: ");
        return 0;
    }
    return ptr;
}

int count(struct node *ptr)
{

    if (ptr != NULL)
    {
        int x, y;
        x = count(ptr->lchild);
        y = count(ptr->rchild);
        return x + y + 1;
    }
}

int main()
{
    struct node *ptr, *root = NULL;
    int choice, val;

    while (1)
    {
        printf("Enter choice 1. Insert 2.Count 3. Exit : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value :");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        }

        case 2:
        {
            printf("No of element in tree is : %d", count(root));
            break;
        }

        case 3:
        {
            exit(0);
            break;
        }

        default:
        {
            printf("Enter the valid input :");
            break;
        }
        }
    }
}