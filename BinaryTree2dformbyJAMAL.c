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

    else
    {
        printf("Duplicate value exists\n");
    }

    return ptr;
}

void print2dUtil(struct node *root, int space)
{
    int i;
    if (root == NULL)
    {
        return;
    }
    space += COUNT;
    print2dUtil(root->rchild, space);
    printf("\n");

    for (i = COUNT; i < space; i++)
    {
        printf(" ");
    }

    printf("%d", root->data);
    print2dUtil(root->lchild, space);
}

void preorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    printf("%d ", ptr->data);
    preorder(ptr->lchild);
    preorder(ptr->rchild);
}

void inorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    inorder(ptr->lchild);
    printf("%d ", ptr->data);
    inorder(ptr->rchild);
}

void postorder(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }

    postorder(ptr->lchild);
    postorder(ptr->rchild);
    printf("%d ", ptr->data);
}

void print2d(struct node *root)
{
    print2dUtil(root, 0);
}

int main()
{
    int choice, val;
    struct node *ptr, *root = NULL;
    while (1)
    {
        printf("Enter the choice : 1.Insert 2.Print 2D Tree  3.Traversal Methods 4.exit : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            printf("Enter the value to insert in tree : ");
            scanf("%d", &val);
            root = insert(root, val);
            break;
        }

        case 2:
        {
            printf("Tree in 2D form: ");
            print2d(root);
            printf("\n");
            break;
        }
        case 3:
        {
            printf("***Traversal Methods***");
            printf("Preorder Travesal");
            preorder(root);
            printf("Inorder Traversal");
            inorder(root);
            printf("Postorder Traversal");
            postorder(root);
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