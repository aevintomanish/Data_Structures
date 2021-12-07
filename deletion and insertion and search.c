#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
int flag = 0;
int countloop = 0;
struct node *create()
{
    int x, ch, c = 0;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\n enter -1 for exiting");
    scanf("%d", &ch);
    if (ch == -1)
    {
        return 0;
    }
    else
    {
        printf("\n enter the data");
        scanf("%d", &x);
        newnode->data = x;
    }
    printf("\n enter the left child of %d", x);
    newnode->left = create();
    printf("\n enter the right child of %d", x);
    newnode->right = create();
    return newnode;
}
void search(struct node *root, int value)
{
    if (root == NULL)
    {
        printf("^^^^Tree is empty ^^^^\n");
    }
    else
    {
        if (root->data == value)
        {
            flag = 1;
            return;
        }
        if (flag == 0 && root->left != NULL)
        {
            search(root->left, value);
        }
        if (flag == 0 && root->right != NULL)
        {
            search(root->right, value);
        }
    }
}
void insertion(struct node *root, int value, int element);
void deletion(struct node *root, int value);
void main()
{
    int ch, a, b, c, d;
    struct node *root;

    root = 0;

    root = create();
    while (1)
    {
        printf("\n MENU  \n 1.SEARCH \n 2.INSERTION\n 3.DELETION \n4.EXIT");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            flag = 0;
            printf("Enter The Element to be Search For:-");
            scanf("%d", &a);
            search(root, a);
            if (flag == 1)
            {
                printf("The value %d do exist ", a);
            }
            else
            {
                printf("The value %d do not exist ", a);
            }
            break;
        case 2:
            flag = 0;
            printf("Enter the element where to be added:-");
            scanf("%d", &b);
            printf("Enter the element to added to that :-");
            scanf("%d", &c);
            insertion(root, b, c);
            if (flag == 0)
            {
                printf("The value %d donot exist ", b);
            }
            break;
        case 3:
            flag = 0;
            printf("Enter the element which to be deleted:-");
            scanf("%d", &d);
            countloop = 0;
            deletion(root, d);
            if (flag == 0)
            {
                printf("The value %d donot exist ", d);
            }
            break;
        case 4:
            printf("\\EXIT\\");
            exit(0);
            break;
        }
    }
}

void insertion(struct node *root, int value, int element)
{
    struct node *temp;
    char x;

    if (root == NULL)
    {
        printf("^^^^Tree is empty ^^^^\n");
    }
    else
    {
        if (root->data == value)
        {
            flag = 1;
            printf("\nFOR LEFT:-\n Press l or L");
            printf("\nFOR RIGHT:-\n Press r or R");
            scanf("%s", &x);
            if (x == 'l' || x == 'L')
            {
                if (root->left == NULL)

                {
                    temp = (struct node *)malloc(sizeof(struct node));

                    temp->data = element;
                    temp->left=NULL;
                     temp->right=NULL;
                    root->left = temp;
                    printf("\n-----INSERTION DONE -----\ninsertion of %d is done as %d left child ", element, value);
                }

                else if (root->left != NULL)
                {
                    printf("\n--------POSITION ERROR-------\nsuch position cant be find out");
                }
            }
            if (x == 'r' || x == 'R')
            {
                if (root->right == NULL)

                {
                    temp = (struct node *)malloc(sizeof(struct node));

                    temp->data = element;
                     temp->left=NULL;

                     temp->right=NULL;
                    root->right = temp;
                    printf("\n-----INSERTION DONE -----\nInsertion Of %d is Done As %d Right Child ", element, value);

                }
                else if (root->right != NULL)
                {
                    printf("\n--------POSITION ERROR-------\n Such Position Cant Be Find Out");
                }
            }
        }
    }

    if (flag == 0 && root->left != NULL)
    {
        insertion(root->left, value, element);
    }

    if (flag == 0 && root->right != NULL)
    {
        insertion(root->right, value, element);
    }
}

void deletion(struct node *root, int value)
{
    countloop++;
    struct node *temp;
    char x;
    if (root == NULL)
    {
        printf("^^^^Tree is empty ^^^^\n");
    }
    else
    {

        if ((root->data == value) && countloop == 1)
        {
            flag = 1;
            if ((root->left == NULL) && (root->right == NULL))
            {
                temp = root;
                root = 0;
                printf("\n ------DELETION DONE----- \n Deleting %d\n", temp->data);
                free(temp);
                return;
            }
            else
            {
                printf("\n ---------!!!!Deletion is only possible at leaf nodes !!!!!---------\n");
                return;
            }
        }
        if (root->left != NULL)
        {
            if (root->left->data == value)
            {
                flag = 1;
                temp = root->left;
                if (temp->left == NULL && temp->right == NULL)
                {

                    root->left = NULL;
                    printf("---------!!!!Deletion %d is done Successfully!!!!---------", temp->data);
                    free(temp);
                    return;
                }
                else
                {
                    printf("-----$$$\nDeletion is not possible  !\n$$$--- ");
                    return;
                }
            }
        }

        if (root->right != NULL)
        {
            if (root->right->data == value)
            {
                flag = 1;
                temp = root->right;
                if (temp->right == NULL && temp->right == NULL)
                {
                    root->right = NULL;
                    printf("---------!!!!Deletion %d is done Successfully!!!!---------", temp->data);
                    free(temp);
                    return;
                }
                else
                {
                    printf("-----$$$\nDeletion is only possible at leaf nodes !\n$$$--- ");
                    return;
                }
            }
        }

        if (flag == 0 && root->left != NULL)
        {
            deletion(root->left, value);
        }
        if (flag == 0 && root->right != NULL)
        {
            deletion(root->right, value);
        }
    }
}
