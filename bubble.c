#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubble_sort(int *l, int size){
    bool check = true;

    for(int i = 0; i < size; i++){
        for(int j = size-1; j > i; j--){
            if(l[j] < l[j-1]){
                int tmp = l[j-1];
                l[j-1] = l[j];
                l[j] = tmp;
                check = false;

                for(int i = 0; i < 8; i++){
                    printf("%d ", l[i]);
                }

                printf("\n");   
            }
        }

        if(check){
            return;
        }else{
            check = true;
        }
    }
}

int main(){
    int *list;
    list = (int*)malloc(8*sizeof(int));

    list[0] = 4;
    list[1] = 8;
    list[2] = 9;
    list[3] = 5;
    list[4] = 2;
    list[5] = 6;
    list[6] = 7;
    list[7] = 3;

    bubble_sort(list, 8);

    free(list);

    return 0;
}