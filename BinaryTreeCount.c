#include <stdio.h>
#include <stdlib.h>
#define COUNT 10
struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
};
struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = key;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (key < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, key);
    }
    else if (key > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, key);
    }
    else
        printf("\nDuplicate key:");
    return ptr;
}
int count(struct node *ptr)
{
    int x, y;
    if (ptr != NULL)
    {
        x = count(ptr->lchild);
        y = count(ptr->rchild);
        return x + y + 1;
    }
    return 0;
}
int main()
{
    struct node *ptr, *root = NULL;
    int choice, key;
    while (1)
    {
        printf("\n1.INSERT");
        printf("\n2.Count");
        printf("\nEnter your choice::");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter Key:");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Total Node is: %d", count(root));
            count(root);
            break;
        }
    }
}