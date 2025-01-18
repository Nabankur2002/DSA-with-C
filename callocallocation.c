#include<stdio.h>
#include<stdlib.h>
int main() {
    int n;
    int *ptr;
    printf("Enter the size: ");
    scanf("%d", &n);
    ptr=(int*)calloc(n,4);
    if(ptr==NULL) {
        printf("\nMemory Allocation failed");
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
    