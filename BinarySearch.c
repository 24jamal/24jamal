#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

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

    return ptr;
}

struct node *search(struct node *ptr, int val)
{
    if (ptr == NULL)
    {
        return NULL;
    }

    else if (val < ptr->data)
    {
        return search(ptr->lchild, val);
    }

    else if (val > ptr->data)
    {
        return search(ptr->rchild, val);
    }

    return ptr;
}

int main()
{
    int choice, val;
    struct node *ptr, *root = NULL;

    while (1)
    {
        printf("Enter the choice 1. Insert 2.Search 3.Exit :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value : ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        }

        case 2:
        {
            printf("Enter the value to search : ");
            scanf("%d", &val);
            ptr = search(root, val);
            if (ptr == NULL)
            {
                printf("Value is not present :");
            }

            else
            {
                printf("Value is present :");
            }
        }
        }
    }
}