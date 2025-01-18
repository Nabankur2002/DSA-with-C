#include<stdio.h>
#include<stdlib.h>
#define MAXSTK 4
int Top = -1;
int stack[MAXSTK];

void push(int item)
{
    if(Top == MAXSTK- 1) {
        printf("stack overflow\n");
    }
    else {
        Top = Top + 1;
        stack[Top] = item;
    }
}
void pop(int item)
{
    if(Top == -1) {
        printf("stack underflow\n");
    }
    else {
        stack[Top] = item;
        Top = Top - 1;
        printf("Item poped");
    }
}

void display()
{
    printf("The stack is:\n");
    for(int i=0; i<=Top; i++)
        printf("%d ",stack[i]);
    printf("\n");
}

int main()
{
    int ch,item;

    while(1)
    {
        printf("\n1.Push:\n2.Pop:\n3.Display:\n4.Exit:\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch) {
        case 1:
            printf("Enter item to push:");
            scanf("%d",&item);
            push(item);
            break;
        case 2:
            pop(item);

            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        }
    }
    return 0;
}