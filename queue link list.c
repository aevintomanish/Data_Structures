#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*link;
};
struct node*front=0;
struct node*rear=0;

void enqueue();
void dequeue();
void peek();
void display();
void check();

void main()
{
int ch,a;
printf(" !!WELCOME TO QUEUE FUNCTION!! ");
while(1)
{
printf("\n MENU \n 1.enqueue \n 2.dequeue \n 3.Peek \n 4.display \n 5.Check Empty Or Not \n 6.Exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter the number to be enqueueed");
scanf("%d",&a);
enqueue(a);
break;

case 2:
dequeue();
break;
case 3:
peek();
break;
case 4:
display();
break;
case 5:
check();
break;
case 6:

 printf("###EXIT####");
 exit(0);
break;
default:
printf("WRONG ENTRY TRY AGAIN");
}
}
}

void enqueue(int x)
{

struct node*newnode;
newnode = (struct node*)malloc(sizeof(struct node));

newnode->data=x;
newnode->link=0;
if (front!=0&&rear!=0)
{
    rear->link=newnode;
rear=newnode;

}
else{
front=rear=newnode;
}
}
void dequeue()
{
    struct node*temp;

    if(front!=0&&rear!=0)
       {
           temp=front;
             printf("%d is going to dequeue out",temp->data);
             front=front->link;
             free(temp);

       }
    else
        {
          printf("queue is empty");
        }
}

void display()
{
     struct node*temp;
    if(front!=0&&rear!=0)
       {
            temp=front;
            while(temp!=0)
            {
            printf("%d",temp->data);
            printf("\n");
            temp=temp->link;

       }
       }
    else
        {
            printf("queue is empty");
            }
        }

void peek()
{
    if (front!=0&&rear!=0)
    {
         printf("%d is the peek of the given queue",front->data);

       }
    else
        {
            printf("queue is empty");
        }
}
void check()
{
    if(front!=0&&rear!=0)
       {
            printf("queue is not full or empty");
       }
       else
       {
           printf("queue is empty");
       }
}
