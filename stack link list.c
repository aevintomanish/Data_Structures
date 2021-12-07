#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node*link;
};
struct node*top=0;
void pop();
void push();
void peek();
void display();
void check();

void main()
{
int ch,a;
printf(" !!WELCOME TO STACK FUNCTION!! ");
while(1)
{
printf("\n MENU \n 1.Push \n 2.Pop \n 3.Peek \n 4.display  \n 5.Check Empty Or Not \n 6.Exit");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("enter the number to be pushed");
scanf("%d",&a);
push(a);
break;

case 2:
pop();
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
printf("WRONG ENTERY TRY AGAIN");
}
}
}

void push(int x)
{

struct node*newnode;
newnode = (struct node*)malloc(sizeof(struct node));

newnode->data=x;
newnode->link=top;
top=newnode;
}
void pop()
{
    struct node*temp;
    temp=top;
    if(temp==0)
       {
            printf("stack is empty");
       }
    else
        {
             printf("%d is going to pop out",top->data);
             top=temp->link;
             free(temp);

        }
}

void display()
{
     struct node*temp;
    temp=top;
    if(temp==0)
       {
            printf("stack is empty");
       }
    else
        {
            while(temp!=0)
            {
            printf("%d",temp->data);
            printf("\n");
            temp=temp->link;
            }
        }
}
void peek()
{
    if(top==0)
       {
            printf("stack is empty");
       }
    else
        {
            printf("%d is the peek of the given data",top->data);
        }
}
void check()
{
    if(top==0)
       {
            printf("stack is empty");
       }
       else
       {
           printf("stack is not full or empty");
       }
}
