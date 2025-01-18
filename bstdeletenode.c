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

ND *in_orderpredecessor(ND* root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;    
}

ND *deletenode(ND *root, int value){
    ND* iPre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    //Search for the node to be deleted
    if(value<root->data){
        root->left=deletenode(root->left,value);
    }
    else if(value>root->data){
        root->right=deletenode(root->right, value);
    }
    //Deletion strategy when the node is found
    else{
        iPre=in_orderpredecessor(root);
        root->data=iPre->data;
        root->left=deletenode(root->left,iPre->data);
    }
    return root;
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
    deletenode(root,56);
    printf("\nThe new in-order is: "); 
    in_order(root);
    return 0;
}