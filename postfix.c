#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
void push(long int symbol);
long int pop();
long int eval_post();
int priority(char symbol);
char infix[100], postfix[100];
long int stack[100];
int top;
void main()
{
long int value;
top=-1;
printf("Enter infix expression: ");
scanf("%s",infix);
int i,p=0;
char symbol;
char next;
for(i=0;i<strlen(infix);i++)
{
symbol=infix[i];
if(symbol!=' ')
{
switch(symbol)
{
case '(':
push(symbol);
break;
case ')':
while((next=pop())!='(')
postfix[p++] = next;
break;
case '+':
case '-':
case '*':
case '/':
case '%':
case '^':
while( top!=-1 && priority(stack[top])>= priority(symbol) )
postfix[p++]=pop();
push(symbol);
break;
default:
postfix[p++]=symbol;
}
}
}
while(top!=-1)
{
postfix[p++]=pop();
}
printf("Postfix expression obtained is: %s\n",postfix);
value=eval_post();
printf("Evaluated postfix expression : %ld\n",value);
}
int priority(char symbol)
{
switch(symbol)
{
case '(':
return 0;
case '+':
case '-':
return 1;
case '*':
case '/':
case '%':
return 2;
case '^':
return 3;
default :
return 0;
}
}
void push(long int symbol)
{
stack[++top]=symbol;
}
long int pop()
{
if(top==-1)
{
printf("Stack underflow\n");
exit(1);
}
return (stack[top--]);
}
long int eval_post()
{
long int a,b,temp,result;
unsigned int i;
float val;
char ch;
for(i=0;i<strlen(postfix);i++)
{
ch=postfix[i];
if (isalpha (ch))
{
printf ("\nEnter the value of %c=", ch);
scanf ("%f", &val);
push(val);
}
else
if(ch<='9' && ch>='0')
push(ch-'0');
else
{
a=pop();
b=pop();
switch(ch)
{
case '+':
temp=b+a; break;
case '-':
temp=b-a;break;
case '*':
temp=b*a;break;
case '/':
temp=b/a;break;
case '%':
temp=b%a;break;
case '^':
temp=pow(b,a);
}
push(temp);
}
}
result=pop();
return result;
}
