#include<stdio.h>
#include<stdlib.h>
struct node
{

int data;

struct node *left, *right;

};

struct node *create ()
{

int x, ch, c = 0;

struct node *newnode;

newnode = (struct node *) malloc (sizeof (struct node));

printf ("\n enter -1 for exiting");

scanf ("%d", &ch);

if (ch == -1)

    {

return 0;

}

  else

    {

printf ("\n enter the data");

scanf ("%d", &x);

newnode->data = x;

}

printf ("\n enter the left child of %d", x);


newnode->left = create ();

printf ("\n enter the right child of %d", x);

newnode->right = create ();

return newnode;

}
void preorder(struct node*root);
void inorder(struct node*root);
void postorder(struct node*root);
void main ()
{
int ch;
struct node *root;

root = 0;

root = create ();
while(1){
printf("\n MENU  \n 1.Preorder \n 2.Inorder\n 3.Postorder \n4.EXIT");
scanf("%d",&ch);

switch(ch)
{
    case 1:
        printf("preorder is:-");
        preorder(root);
        break;
    case 2:
        printf("inorder is:-");
        inorder(root);
        break;
    case 3:
        printf("postorder is:-");
        postorder(root);
        break;
    case 4:
        printf("\\EXIT\\");
        exit(0);
        break;
}
}
}
void preorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    else{
        printf(" \n %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    else{

        inorder(root->left);
        printf(" \n %d",root->data);
        inorder(root->right);
    }
}
void postorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    else{

        postorder(root->left);
        postorder(root->right);
        printf(" \n %d",root->data);
    }
}
