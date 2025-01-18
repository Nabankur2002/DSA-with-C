#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int arr[50];
int front=-1;
int rear=-1;

void insert(){
    int item;
    if(rear==MAX-1){
        printf("Queue overflow");
    }
    else{
        if(front==-1)
        front=0;
        printf("Insert the element you want to enter ");
        scanf("%d", &item);
        rear=rear+1;
        arr[rear]=item;
    }
}

void display(){
    if(front==-1){
        printf("Queue is empty");
    }
    else{
        printf("Queue is: ");
        for(int i=front; i<=rear; i++){
            printf("%d ",arr[i]);
        }
    }
}

void delete(){
    if(front==-1 || front>rear){
        printf("Stack is empty");
        return;
    }
    else{
        printf("Element to be deleted from the array is: %d", arr[front]);
        front=front+1;
    }
}
int main(){
    int item;
    int choices;
    while(1){
        printf("\nThe choices you want to perform: \n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit");
        scanf("%d", &choices);
        switch (choices)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
        printf("Wrong Choices");
        }
    }
}
