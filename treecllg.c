#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}ND;

ND* create(){
    int x;
    ND *newnode=(ND*)malloc(sizeof(ND));
    scanf("%d", &x);
    if(x==-1){
        return NULL;
    }
    newnode->data=x;
    printf("Enter the left child of %d\n", x);
    newnode->left=create();
    printf("Enter the right child of %d\n", x);
    newnode->right=create();
    return newnode;  // as newnode is a pointer so it will return the address of the node
}

void pre_order(ND *root){
    if(root==NULL){
        return;
    }
    else{
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(ND *root){
    if(root==NULL){
        return;
    }
    else{
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

void post_order(ND *root){
    if(root==NULL){
        return;
    }
    else{
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}
int main(){
    ND *root;
    root=NULL;
    printf("Enter the element in the tree: ");
    root=create();
    printf("\nThe pre-order is: ");
    pre_order(root);
    printf("\nThe in-order is: ");
    in_order(root);
    printf("\nThe post-order is: ");
    post_order(root);
    return 0;
}