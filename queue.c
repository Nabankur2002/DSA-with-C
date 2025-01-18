#include <stdio.h>
#include<stdlib.h>
#define MAX 50
int array[MAX];
int rear = - 1;
int front = - 1;
void insert(){
   int add_item;
   if (rear == MAX - 1)
      printf("Queue Overflow ");
   else{
      if (front == - 1)
      front = 0;
      printf("Inset the element in queue : ");
      scanf("%d", &add_item);
      rear = rear + 1;
      array[rear] = add_item;
   }
}
void display(){
   int i;
   if (front == - 1)
      printf("Queue is empty ");
   else{
      printf("Queue is : ");
      for (i = front; i <= rear; i++)
         printf("%d ", array[i]);
   }
}
void delete(){
   if (front == - 1 || front > rear){
      printf("Queue Underflow ");
      return ;
   }
   else{
      printf("Element deleted from queue is : %d",array[front]);
      front = front + 1;
   }
}
int main(){
   int add_item;
   int choice;
   while (1){
      printf("\n1.Insert element to queue ");
      printf("\n2.Delete an element from queue");
      printf("\n3.Display elements of queue ");
      printf("\n4.Quit ");
      printf("\nEnter your choice : ");
      scanf("%d", &choice);
      switch (choice){
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
         printf("Wrong choice ");
      }
   }
}
