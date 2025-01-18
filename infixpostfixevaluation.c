#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 100
int stack[MAX],top=-1;
void push(int item)
{
    if(top == (MAX-1))
    {
        printf("\n stack overflow");
        return;
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
int pop()
{
    if(top==-1)
    {
        printf("\n stack underflow");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}
int evalpostfix(char exp[])
{
    int i=0,a=0,b=0,res;
    char ch;
    while(exp[i]!='\0')
    {
        ch=exp[i];
        if(isdigit(ch))
        {
            push(ch-'0');
        }
        else{
            b=pop();
            a=pop();
            switch(ch)
            {
                case '+':
                push(a+b);
                break;
                case '-':
                push(a-b);
                break;
                case'*':
                push(a * b);
                break;
                case '/':
                push(a/b);
                break;
                default:
                printf("\n Invalid");
                exit(1);
            }
        }
        i++;
    }
    res=pop();
    return(res);
}
int main()
{
    char exp[MAX];
    printf("Enter a postfix: \n");
    scanf("%s",exp);
    int res=evalpostfix(exp);
    printf("%d",res);
    return 0;
}