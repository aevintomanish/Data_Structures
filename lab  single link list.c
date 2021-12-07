/*
*Programmed By Aevin Tom Anish
*S3 IT
*Singly Linked list Program
*/


#include <stdio.h>
#include <stdlib.h>
void main()
{

struct node
{
    int data;
    struct node*link;
};
struct node*head,*newnode,*temp;

head=0;
int choice=1;
int ch;
int search;
int a=1;
int b;
int c;
int count=0;
while(choice)
{
newnode=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&newnode->data);
newnode->link=0;
if(head==0)
{
head=temp=newnode;
}
else{
temp->link=newnode;
temp=newnode;
}
printf("do u want to continue press 1 or to exit 0..?");
scanf("%d",&choice);

}
while(a){
printf("\n MENU \n 1 for printing full data\n 2 search an element \n3.insertion \n4.deletion\n 5 for exiting ");
scanf("%d",&ch);
switch(ch)
{


case 1:
    temp=head;
    while(temp!=0)
    {
        printf("\n %d",temp->data);
        temp=temp->link;
    }

break;

case 2:

 printf("enter the element to be search");
 scanf("%d",&search);
    temp=head;
    while(temp!=0)
    {
        if(temp->data==search){
        printf("yes  %d exist",temp->data);
        break;

        }
        else if(temp->data!=search)
        {
        temp=temp->link;
        }
    }
    if(temp==0)
    {
    printf("no such number founded");
    }
break;
case 3:
    printf("menu \n 1 for the beginning\n 2 for the end\n 3 for  a specified node.");
    scanf("%d",&b);

    if(b==1)
        {
          newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter the data that u want to enter");
            scanf("%d",&newnode->data);
            newnode->link=head;
            head=newnode;
        }
    if(b==2)
        {
          newnode=(struct node*)malloc(sizeof(struct node));
            printf("enter the data that u want to enter");
            scanf("%d",&newnode->data);
            newnode->link=0;
            temp=head;
            while(temp->link!=0)
            {
                temp=temp->link;
            }
            temp->link=newnode;
            }

    if(b==3)
        {   int pos;
            int i;
             temp=head;
          while(temp!=0)
         {
        printf("\n elements are:\n %d",temp->data);
        temp=temp->link;

                count++;
            }
          newnode=(struct node*)malloc(sizeof(struct node));
            printf("\n enter the postion");
            scanf("%d",&pos);
            if (pos>count)
            {
                printf("invalid count current count is %d",count);
            }
            else{
                temp=head;
                while(i<pos)
                    {
                        temp=temp->link;
                        i++;
                    }
            printf("enter the data");
            scanf("%d",&newnode->data);
            newnode->link=temp->link;
            temp->link=newnode;
}
}

break;

case 4:
printf("menu \n 1 for the beginning\n 2 for the end\n 3 for  a specified node.");
    scanf("%d",&c);

    if(c==1){
        if (head==0)
        {
            printf("link is empty");
        }
        else
        {
            struct node*temp;
            temp=head;
            head=head->link;
            free(temp);
        }
    }
     if(c==2){
        if (head==0)
        {
            printf("link is empty");
        }
        else
        {
            struct node*prev;
            temp=head;
             while(temp->link!=0)
            {
                prev=temp;
                temp=temp->link;
            }
            if(temp==head)
            {
                head=0;
                free(temp);
            }
            else{
                prev->link=0;
                free(temp);
            }
        }
    }
    if(c==3){
        if (head==0)
        {
            printf("link is empty");
        }
        else
        {
            struct node*linknode;
            int pos;
            int i=1;
            temp=head;
            printf("enter the postion");
            scanf("%d",&pos);
             while(i<pos-1)
            {
                temp=temp->link;
                i++;
            }
            linknode=temp->link;
            temp->link=linknode->link;
            free(linknode);
        }
    }
break;
case 5:
a=0;
printf("exit!!");
default:
{
 printf("!! Invalid!! \n");
break;
}
}}}
