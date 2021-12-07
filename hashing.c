#include<stdio.h>
#include<stdlib.h>

#define size 100
int n,m,o;
int bit;
int h[size];
struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void chaininsert(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    int key=value%bit;
    if(chain[key] == NULL)
        chain[key] = newNode;

    else
    {
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void chainprint()
{
    int i;
    printf("\n");
    for(i = 0; i < bit; i++)
    {
        struct node *temp = chain[i];
        printf("Chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void linproinsert()
{

 int index,element,i;

 for(i=0;i < m;i++)
    {
      printf("\n  \t \t  \t Enter a value to insert into hash table :\n");
      scanf("%d",&element);
      int key1=element%bit;
     while(h[key1]!=0)
        {
            if(h[key1]==bit)
            break;
            key1=(key1+1)%m;
        }
        h[key1]=element;


    }


}
void proprint()
{

  int i;


  for(i=0;i< bit; i++)
  {
   printf("Chain[%d]-->",i);
   if (h[i] != NULL )
   {
     printf("%d \n",h[i]);
     h[i]=NULL;
   }
  else
  {
      printf("NULL\n");
  }
  }

}
void quadratic()
{

 int index,element,i,ext=0;

 for(i=0;i < m;i++)
    {
      printf("\n  \t \t  \t Enter a value to insert into hash table :\n");
      scanf("%d",&element);
      int key2=element%bit;
     while(h[key2]!=0)
        {
            if(h[key2]==bit)
            break;
            key2=(key2+(ext*ext))%m;
            ext++;
        }
        h[key2]=element;


    }


}

int main()
{
    init();

    int ch;


    printf("\n ------------------------Welcome To Hash collision resolution techniques---------------------------------------\n");
    printf("\n \t \t  \t Enter the maximum size of Hash Table :\n");
    scanf("%d",&bit);
    while(1)
    {


    printf("\n \t 1.Chaining Resolution Techniques \n \n \t 2.Linear Probing Resolution Techniques \n \n \t 3.Quadratic Probing Resolution Techniques \n\n \t  4.Exiting The Hashing \t");
    scanf ("%d", &ch);
    switch(ch)
    {


    case 1:
    printf("\n  \t \t  \t Number of Elements in this Hash table ..... :\n");
    scanf ("%d", &n);
    for(int i=0 ;i < n;i++)
    {
     int exam;

     printf("\n \t \t  \t Enter a value to insert into hash table :\n");
     scanf("%d",&exam);
     chaininsert(exam);
    }
      chainprint();
      break;
    case 2:

    printf("\n  \t \t  \t Number of Elements in this Hash table .....:\n");
    scanf ("%d", &m);
     linproinsert();
     proprint();
     break;
    case 3:

    printf("\n  \t \t  \t Number of Elements in this Hash table .....:\n");
    scanf ("%d", &m);
     quadratic();
     proprint();
     break;

    case 4:
        printf("\n --------------------Exiting---------------------- \n");
        exit(0);
        break;
    default:
      printf("@@@@@@@@@@@@@@@Invalid@@@@@@@@@@@@@@@@");
      break;
    }
    }

return 0;
}



