#include<stdio.h>
#include<stdlib.h>
int linear_search(int arr[], int n) {
    int key;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    for(int i=0; i<n; i++) {
        if(arr[i]==key) {
            return i;
        }
    }
    return -1;
}
int binary_search(int arr[], int n) {
    int key;
    printf("Enter the element you want to search: ");
    scanf("%d", &key);
    int start=0, end = n-1;
    while (start<=end) {
        int mid=(start+end)/2;
        if(arr[mid]==key) {
            return mid;
        }
        else if(arr[mid]<=key) {
            start=mid+1;
        }
        else {
            end=mid-1;
        }
    }
    return -1;
}
void print_arr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d\n", arr[i]);
    }
}
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void bubblesort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    print_arr(arr,n);
}
void selectionsort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        int minIdx=i;
        for(int j=i+1; j<n; j++) {
            if(arr[j]<arr[minIdx]) {
                minIdx=j;
            }
        }
        swap(&arr[minIdx], &arr[i]);
    }
    print_arr(arr,n);
}
void insertionsort(int arr[], int n) {
    for(int i=1;i<n;i++){
        int temp=arr[i]; // storing the value which needs to be compared
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];            
            j--;
        }
        arr[j+1]=temp;
    }
    printf("Sorted array is\n");
    print_arr(arr,n);
}
void reverse (int arr[],int n)
{
    int i,temp;
    for(i=0; i<n/2; i++)
    {
        temp = arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    printf ("After reversing the array: ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
}
int main() {
    int arr[30];
    int n, i,operation, keyIdx;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements in the array\n");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Your array is \n");
    print_arr(arr,n);
    while(1) {
        printf("\nEnter the choices: \n 1. Linear search  2. Binary Search  3. Bubble Sort  4. Selection Sort  5. Insertion Sort  6. Reverse an array  7.Exit\n");
        scanf("%d", &operation);
        switch(operation) {
        case 1:
            keyIdx=linear_search(arr,n);
            if(keyIdx==-1) {
                printf("Element is not present\n");
            }
            else {
                printf("Element is present\n");
            }
            break;
        case 2:
            keyIdx=binary_search(arr,n);
            if(keyIdx==-1) {
                printf("Element is not present\n");
            }
            else {
                printf("Element is present at %d\n", keyIdx+1);
            }
            break;
        case 3:
            bubblesort(arr,n);
            break;
        case 4:
            selectionsort(arr,n);
            break;
        case 5:
            insertionsort(arr,n);
            break;
        case 6:
            reverse(arr,n);
            break;
        case 7:
            printf("Thank You\n");
            exit(1);
        default:
            printf("Invalid operation\n");
        }
    }
}