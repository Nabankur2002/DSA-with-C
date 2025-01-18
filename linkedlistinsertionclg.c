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
int search(int key){
    ND *temp=start;
    int idx=0;
    while(temp->next!=NULL){
        if(temp->data==key){
            return idx;
        }
        temp=temp->next;
        idx++;
    }
    printf("Element not present in the linked list \n");
    return -1;
}

void insert_after_value(int item, int value){
    ND *P =(ND*)malloc(sizeof(ND));
    P->data=item;
    ND *temp=start;
    while(temp->next!=NULL){
        if(temp->data==value){
            break;
        }
        temp=temp->next;
    }
    P->next=temp->next;
    temp->next=P;
}

void insert_before_value(int item, int value){
    ND *P =(ND*)malloc(sizeof(ND));
    P->data=item;
    ND *temp=start;
    int pos=search(value);
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    P->next=temp->next;
    temp->next=P;
}

int main(){
    ND *P;
    int n, item, choice, newItem,value, key;
    printf("Enter no. of nodes: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        printf("Enter the item: ");
        scanf("%d", &item);
        create(item);
    }
    while(1){
        printf("Enter the choice\n 1. Insert at first\n 2. Insert before a value\n 3. Insert after a value\n 4. Display\n 5.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("Enter the item you want to insert: ");
            scanf("%d", &newItem);
            insert_at_first(newItem);
            break;
            case 2: printf("Enter the value before which you want to insert: ");
                    scanf("%d", &value);
                    printf("Enter the item you want to insert before the value: ");
                    scanf("%d", &newItem);
                    insert_before_value(newItem,value);
                    break;
            case 3: printf("Enter the value after which you want to insert: ");
                    scanf("%d", &value);
                    printf("Enter the item you want to insert after the value: ");
                    scanf("%d", &newItem);
                    insert_after_value(newItem,value);
                    break;
            case 4:
                    display();
                    break;
            case 5: exit(0);
        }
    }
    return 0;
}