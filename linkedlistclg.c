#include<stdio.h>
#include<stdlib.h>
typedef struct  node
{
    int data;
    struct node *next;
}ND;
ND *start=NULL;
void create(int item){
    ND *P=(ND*)malloc(sizeof(ND));
    P->data=item;
    P->next=NULL;
    if(start==NULL){
        start=P;
    }
    else{
        ND *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=P;
    }
}

void display(){
    ND *temp;
    temp=start;
    printf("Linked Lits items are: \n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

void insert_at_first(int item){
    ND *P=(ND*)malloc(sizeof(ND));
    P->data=item;
    P->next=start;
    start=P;
}

int main(){
    ND *P;
    int n, item, choice, newItem;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        printf("Enter the item: ");
        scanf("%d", &item);
        create(item);
    }
    while(1){
        printf("Enter the choice\n 1. Insert at first\n 2. Display\n 3. Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the item you want to insert: ");
            scanf("%d", &newItem);
            insert_at_first(newItem);
            break;
            case 2: display();
            break;
            case 3: exit(0);
        }
    }
    return 0;
}