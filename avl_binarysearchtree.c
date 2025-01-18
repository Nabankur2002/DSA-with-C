#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    int height; //BalanceFactor ka mode chaiye
}ND;

int getHeight(ND *n){
    if(n==NULL){
        return 0;
    }
    else{
        return n->height;
    }
}

ND *createNode(int key){
    ND *newnode=(ND*)malloc(sizeof(ND));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getBalanceFactor(ND *n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left)-getHeight(n->right);
}

int max(int a, int b){
    return a>b?a:b;
}

ND *rightRotate(ND *y){
    ND *x=y->left;
    ND *T2 = x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height=max(getHeight(y->right),getHeight(y->left)) + 1;

    return x; // Here I returned x because x is the root nodeafter LeftRotation 
}

ND *leftRotate(ND *x){
    ND *y=x->right;
    ND *T2 = y->right;

    y->left=x;
    x->right=T2;

    y->height=max(getHeight(y->right),getHeight(y->left)) + 1;
    x->height=max(getHeight(y->right),getHeight(y->left)) + 1;

    return y; // Here I returned y because x is the root nodeafter LeftRotation 
}

ND *insert(ND *node, int key){
    if(node==NULL){
        return(createNode(key));
    }
    if(key< node->data){
        node->left=insert(node->left, key);
    }
    if(key > node->data){
        node->right=insert(node->right,key);
        return node;
    }

    node->height=1+max(getHeight(node->left), getHeight(node->right));
    int bf= getBalanceFactor(node);

    //Left left case
        if(bf>1 && key < node->left->data){
            return rightRotate(node);
        }
    //rightright case
        if(bf<-1 && key > node->right->data){
            return leftRotate(node);
        }
    //left right case
        if(bf>1 && key > node->left->data){
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
    //right left case
        if(bf<-1 && key < node->right->data){
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
}

void preOrder(ND *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(){
    ND *root=NULL;
    root=insert(root, 1);
    root=insert(root, 2);
    root=insert(root, 4);
    root=insert(root, 5);
    root=insert(root, 6);
    root=insert(root, 3);
    preOrder(root);
    return 0;
}
