#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} ND;

ND* create() {
    int x;
    ND *newnode = (ND*)malloc(sizeof(ND));
    scanf("%d", &x);
    if(x == -1) {
        return NULL;
    }
    newnode->data = x;
    printf("Enter the left child of %d\n", x);
    newnode->left = create();
    printf("Enter the right child of %d\n", x);
    newnode->right = create();
    return newnode;
}

void pre_order(ND *root) {
    if(root == NULL) {
        return;
    } else {
        printf("%d ", root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(ND *root) {
    if(root == NULL) {
        return;
    } else {
        in_order(root->left);
        printf("%d ", root->data);
        in_order(root->right);
    }
}

void post_order(ND *root) {
    if(root == NULL) {
        return;
    } else {
        post_order(root->left);
        post_order(root->right);
        printf("%d ", root->data);
    }
}

ND* searchiter(ND* root, int key) {
    while(root != NULL) {
        if(key == root->data) {
            return root;
        } else if(key < root->data) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return NULL;
}

void insert(ND *root, int key) {
    ND *prev = NULL;
    ND *current = root;

    // Search for the correct position
    while(current != NULL) {
        prev = current;
        if(key == current->data) {
            printf("You cannot insert the node. Duplicate values are not allowed.\n");
            return;
        } 
        else if(key < current->data) {
            current = current->left;
        } 
        else {
            current = current->right;
        }
    }

    // Create a new node for the key
    ND *newnode = (ND*)malloc(sizeof(ND));
    newnode->data = key;
    newnode->left = newnode->right = NULL;

    // Insert the new node in the appropriate position
    if(key < prev->data) {
        prev->left = newnode;
    } 
    else {
        prev->right = newnode;
    }

    printf("Node with value %d inserted.\n", key);
}

int main() {
    ND *root;
    root = NULL;
    printf("Enter the element in the tree: ");
    root = create();

    printf("\nThe pre-order is: ");
    pre_order(root);
    
    printf("\nThe in-order is: ");
    in_order(root);
    
    printf("\nThe post-order is: ");
    post_order(root);

    // Insert a new value into the tree
    insert(root, 18);

    // Print the tree after insertion
    printf("\nThe pre-order after insertion is: ");
    pre_order(root);
    printf("\nThe in-order after insertion is: ");
    in_order(root);
    printf("\nThe post-order after insertion is: ");
    post_order(root);

    return 0;
}
