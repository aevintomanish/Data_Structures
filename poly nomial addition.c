#include <stdio.h>
#include <stdlib.h>
struct poly
{
    int coeff;
    int pow;
    struct poly *link;
};
struct poly *head=NULL,*head1=NULL,*head2=NULL;
void create(struct poly *a)
{
 int ch=1;
 while(ch)
 {

  printf("\n Enter coefficient :");
  scanf("%d",&a->coeff);
  printf("\n Enter power:\t");
  scanf("%d",&a->pow);
  a->link=(struct poly*)malloc(sizeof(struct poly));
  a=a->link;
  a->link=NULL;
  printf("\n enter 0 to exit else to contiue: \n");
  scanf("%d",&ch);
 }

}


void display(struct poly *a)
{
 while(a->link!=NULL)
 {
  printf("%dx^%d",a->coeff,a->pow);
  a=a->link;
  if(a->link!=NULL)
   printf("+");
 }
}

void polyadd(struct poly *head1,struct poly *head2,struct poly *head)
{
     while(head1->link &&  head2->link)
     {
      if(head1->pow > head2->pow)
      {
       head->pow=head1->pow;
       head->coeff=head1->coeff;
       head1=head1->link;
       }
      else if(head1->pow < head2->pow)
      {
       head->pow=head2->pow;
       head->coeff=head2->coeff;
       head2=head2->link;
       }
      else
      {
       head->pow=head1->pow;
       head->coeff=head1->coeff+head2->coeff;
       head1=head1->link;
       head2=head2->link;
       }
      head->link=(struct poly *)malloc(sizeof(struct poly));
      head=head->link;
      head->link=NULL;
     }
     while(head1->link || head2->link)
     {
      if(head1->link)
      {
       head->pow=head1->pow;
       head->coeff=head1->coeff;
       head1=head1->link;
       }
      if(head2->link)
      {
       head->pow=head2->pow;
       head->coeff=head2->coeff;
       head2=head2->link;
       }
       head->link=(struct poly *)malloc(sizeof(struct poly));
       head=head->link;
       head->link=NULL;
       }
}
void main()
{



head1=(struct poly *)malloc(sizeof(struct poly));
head2=(struct poly *)malloc(sizeof(struct poly));
head=(struct poly *)malloc(sizeof(struct poly));
printf("\n 1st polynomial \n");
create(head1);
printf("\n 2nd polynomial \n");
create(head2);
printf("\n 1st Polynomial:\n");
display(head1);
printf("\n 2nd Polynomial:\n");
display(head2);
polyadd(head1,head2,head);
printf("\n\n Added polynomial:\n");
display(head);

}
