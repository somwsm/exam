#include <stdio.h>
#include <stdlib.h>

int partition(int *l, int pivot, int left, int right){
    int tmp = l[pivot];
    l[pivot] = l[right];
    l[right] = tmp;

    int lp = left;
    int rp = right-1;

    while(1){
        while(l[lp] < l[right]){
            lp++;
        }

        while(l[rp] >= l[right] && lp <= rp){
            rp--;
        }

        if(lp < rp){
            tmp = l[lp];
            l[lp] = l[rp];
            l[rp] = tmp;
        }else{
            break;
        }
    }

    for(int i = 0; i < 8; i++){
        printf("%d ", l[i]);
    }

    printf("\n"); 

    tmp = l[lp];
    l[lp] = l[right];
    l[right] = tmp;

    return lp;
}

void quick_sort(int *l, int size, int left, int right){
    if(left < right){
        int pivot = (left+right)/2;

        int p = partition(l, pivot, left, right);
        quick_sort(l, size, left, p-1);
        quick_sort(l, size, p+1, right);
    }
}

int main(){
    int *list;
    list = (int*)malloc(8*sizeof(int));

    list[0] = 2;
    list[1] = 7;
    list[2] = 8;
    list[3] = 3;
    list[4] = 4;
    list[5] = 5;
    list[6] = 6;
    list[7] = 5;

    quick_sort(list, 8, 0, 7);

    for(int i = 0; i < 8; i++){
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}