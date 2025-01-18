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

int delete_first(){
    int item;
    ND *p=start;
    item=start->data;
    start=start->next;
    free(p);
    printf("First Node deleted\n");
    return item;
}

int delete_last(){
    int item;
    ND *temp=start;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    item=temp->next->data;
    free(temp->next);
    temp->next=NULL;
    printf("Last Node deleted\n");
    return item;
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
        printf("Enter the choice\n 1. Delete first node\n 2. Delete Last Node\n 3. Insert after a value\n 4. Insert before a value\n 5. Search an element\n 6. Display\n 7.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:printf("Deleted item from the node: %d\n", delete_first());
                    break;
            case 2:printf("Deleted item from the node: %d\n", delete_last());
                    break;       
            case 3: printf("Enter the value before which you want to insert: ");
                    scanf("%d", &value);
                    printf("Enter the item you want to insert after the value: ");
                    scanf("%d", &newItem);
                    insert_after_value(newItem,value);
                    break;
            case 4: printf("Enter the value after which you want to insert: ");
                    scanf("%d", &value);
                    printf("Enter the item you want to insert before the value: ");
                    scanf("%d", &newItem);
                    insert_before_value(newItem,value);
                    break;
            case 5: printf("Enter the value you want to search: ");
                    scanf("%d", &key);  
                    if (search(key)!=-1){
                    printf("The element found at %d\n", search(key)+1);
                    }
                    break;   
            case 6:
                    display();
                    break;
            case 7: exit(0);
        }
    }
    return 0;
}