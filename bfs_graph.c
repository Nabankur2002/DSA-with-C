#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int *arr;
}ND;

int isEmpty(ND *q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(ND *q){
    if(q->r == q->size - 1){
        return 1;
    }
    return 0;
}

void enqueue(ND *q, int val){
    if(isFull(q)){
        printf("The queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
    }
}

int dqueue(ND *q){
    int a = -1;
    if(isEmpty(q)){
        printf("The queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f];
    }
    return a;  // Return the dequeued element
}

int main(){
    // initializing Queue (array representation)
    ND q;
    q.size = 400;
    q.f = -1;  // Change f to -1 initially
    q.r = -1;  // Change r to -1 initially
    q.arr = (int*)malloc(q.size * sizeof(int));

    // BFS implementation
    int node;
    int u;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    printf("BFS Traversal: ");
    visited[0] = 1;
    enqueue(&q, 0);  // Enqueue 0 for exploration

    while (!isEmpty(&q)){
        int node = dqueue(&q);  // Dequeue the next node for exploration
        printf("%d ", node);    // Print the node being visited

        for(int j = 0; j < 7; j++){
            if(a[node][j] == 1 && visited[j] == 0){
                visited[j] = 1;  // Mark the node as visited
                enqueue(&q, j);  // Enqueue the adjacent node
            }
        }
    }

    return 0;
}
