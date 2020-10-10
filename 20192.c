#include <stdio.h>
#include <stdbool.h>
#define N 7

int count = 0;

const int a [ N ][ N ] = {
    {0 , 1 , 1 , 0 , 0 , 0, 0} ,
    {1 , 0 , 1 , 1 , 0 , 0, 0} ,
    {1 , 1 , 0 , 0 , 1 , 0, 0} ,
    {0 , 1 , 0 , 0 , 1 , 1, 0} ,
    {0 , 0 , 1 , 1 , 0 , 0, 1} ,
    {0 , 0 , 0 , 1 , 0 , 0, 0} ,
    {0 , 0 , 0 , 0 , 1 , 0, 0} ,
};

void print_path(int n, int path[]){
    for(int i = 0; i < n; i++){
        printf("%d ", path[i]);
    }

    printf("\n");
}

void dfs(int step, int goal, int path[], bool visited[]){
    count++;
    int x = path[step-1];
    if(x == goal){
        print_path(step, path);
    }else{
        for(int i = 0; i < N; i++){
            if(a[x][i] == 0){
                continue;
            }

            if(!visited[i]){
                path[step] = i;
                visited[i] = true;
                dfs(step+1, goal, path, visited);
                visited[i] = false;
            }
        }
    }
}

void traverse(int start, int goal){
    int path[N];
    bool visited[N];

    for(int i = 0; i < N; i++){
        visited[i] = false;
    }

    path[0] = start;
    visited[start] = true;
    dfs(1, goal, path, visited);

}

int main(){
    traverse(0, 6);

    printf("%d\n", count);

    return 0;
}