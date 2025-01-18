#include<stdio.h>
#include<stdlib.h>
int insertion(int a[20], int n, int insert_element, int location_insert, int i){
    for(i=n; i>location_insert; i--){
        a[i]=a[i-1];
    }
    a[location_insert]= insert_element;
    printf("Array after insertion:\n");
    for(i=0;i<n+1;i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

int deletion(int a[20], int n, int location_delete, int i){
    for(i=location_delete; i<n; i++){
        a[i]=a[i+1];
    }
    printf("Array after deletion:\n");
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
    n=n-1;
    return 0;
}

int main(){
    int n;
    int i;
    int insert_element;
    int a[20];
    int b;
    int location_insert;
    int location_delete;

    printf("Enter no. of elements in an array: ");
    scanf("%d", &n);
    for(i=0;i<n; i++){
        printf("Enter value for location arr[%d]", i);
        scanf("%d", &a[i]);
    }
    printf("Array elements are: \n");
    for(i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
    while(1){
        printf("Choose the operation to perform:\n 1. Insert an element \n 2. Delete an element 3. Exit\n ");
        scanf("%d", &b);

        switch(b){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &insert_element);
                printf("Enter location to insert at: ");
                scanf("%d", &location_insert);
                insertion(a,n,insert_element,location_insert,i);
                break;
            case 2: 
                printf("Enter location to Delete: ");
                scanf("%d", &location_delete);
                deletion(a,n,location_delete,i);
                break;
            case 3:
                printf("Thank You\n");
                exit(1);

        }
    }
return 0;
}