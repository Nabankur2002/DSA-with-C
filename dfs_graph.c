#include<stdio.h>
#include<stdlib.h>

int visited[7]={0,0,0,0,0,0,0};
int a[7][7]={
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void DFS(int i){
    printf("%d ", i);
    visited[i]=1;
    for(int j=0; j<7; j++){
        if(a[i][j]==1 && !visited[j]){ // Here i is where I am rignt now and j is cheking if there is 1 in that row, the 2nd condition not visited i.e that node is not visited
            DFS(j);
        }
    }
}

int main(){
    //DFS implementation
    DFS(1);
    return 0;
}