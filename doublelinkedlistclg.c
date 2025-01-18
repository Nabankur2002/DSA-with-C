#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}ND;

ND *start=NULL;
void create(int item){
    ND *P=(ND*)malloc(sizeof(ND));
    P->data=item;
    P->next=NULL;
    P->prev=NULL;
    if(start==NULL){
        start=P;
    }
    else{
        ND *temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=P;
        P->prev=temp;
    }
}

void display(){
    ND *temp;
    temp=start;
    printf("Double linked list items are: \n");
    while(temp!=NULL){
        printf("%d->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insert_at_first(int item){
    ND *P=(ND*)malloc(sizeof(ND));
    P->data=item;
    P->prev=NULL;
    P->next=start;
    start->prev=P;
    start=P;
}

int del_first(){
    int item;
    ND *P=start;
    item=start->data;
    (start->next)->prev=NULL;
    start=start->next;
    free(P);
    printf("First Node deleted\n");
    return item;
}

int del_last(){
    int item;
    ND *temp=start;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    item=temp->next->data;
    free(temp->next);
    temp->next=NULL;
    printf("Last Node deleted\n");
    return item;
}

void insert_after_value(int item, int value){
   ND *P = (ND*)malloc(sizeof(ND));
    P->data = item;
    ND *temp = start;
    while (temp != NULL) {
        if (temp->data == value) {
            P->next = temp->next;
            P->prev = temp;
            if (temp->next != NULL) {
                temp->next->prev = P;
            }
            temp->next = P;
            return; // Insertion successful
        }
        temp = temp->next;
    }
}


void insert_before_value(int item, int value){
    ND *P=(ND*)malloc(sizeof(ND));
    P->data=item;
    ND *temp=start;
    while(temp->next->next!=NULL){
        if(temp->next->data==value){
            break;
        }
        temp=temp->next;
    }
    P->next=temp->next;
    P->prev=temp;
    temp->next->prev=P;
    temp->next=P;
}

int search(int value){
    ND *temp=start;
    int pos=0;
    while (temp!=NULL)
    {
        if(temp->data==value){
            return pos;
        }
        temp=temp->next;
        pos++;
    }
    printf("Element not present\n");
    return -1;
}

int main(){
    ND *P;
    int n, item, choice, newItem, value, key;
    printf("\n How many node?");
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        printf("Enter item ");
        scanf("%d", &item);
        create(item);
    }
    while(1){
        printf("\n1. Insert at first\n 2. Display\n 3. Delete first node\n 4. Delete Last node\n 5. Insert after a given value\n 6. Insert before a given value\n 7. Search\n 8. Exit\n");
        printf("Your Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the item you want to insert: ");
                scanf("%d", &newItem);
                insert_at_first(newItem);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Deleted item from the node: %d\n", del_first());
                break;
            case 4:
                printf("Deleted item from the node: %d\n", del_last());
                break;
            case 5:
                printf("Enter the value after which you want to insert: ");
                scanf("%d", &value);
                printf("Enter the item you want to insert after the value: ");
                scanf("%d", &newItem);
                insert_after_value(newItem,value);
                break;
            case 6:
                printf("Enter the value before which you want to insert: ");
                scanf("%d", &value);
                printf("Enter the item you want to insert before the value: ");
                scanf("%d", &newItem);
                insert_before_value(newItem,value);
                break; 
            case 7:
                printf("Enter the value you want to search: ");
                scanf("%d", &key);
                if(search(key)!=-1){
                    printf("The element pressent at %d\n", search(key)+1);
                }
                break;
            case 8: exit(0);
        }
    }
}

