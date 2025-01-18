#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    int *ptr;
    printf("Enter the size: ");
    scanf("%d", &n);
    ptr=(int*)malloc(n* sizeof(int));
    if(ptr==NULL){
    printf("\n Memory Allocation failed");
    exit(0);
    }
    for(int i=0; i<n; i++) {
        printf("Enter the values in array: ");
        scanf("%d", &ptr[i]);
    }
    printf("The values are: ");
    for (int i=0; i<n; i++) {
        printf("%d ", ptr[i]);
    }
    return 0;
}
