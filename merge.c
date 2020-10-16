#include <stdio.h>
#include <stdlib.h>

void merge(int *l, int left, int mid, int right){
    int i = left;
    int j = mid+1;
    int k = 0;

    int *m;
    m = (int*)malloc((right-left+1)*sizeof(int));

    while(i <= mid && j <= right){
        if(l[i] < l[j]){
            m[k] = l[i];
            i++;
        }else{
            m[k] = l[j];
            j++;
        }

        k++;
    }

    if(i == mid+1){
        while(j <= right){
            m[k] = l[j];
            j++;
            k++;
        }
    }else{
        while(i <= mid){
            m[k] = l[i];
            i++;
            k++;
        }
    }

    for(int i = 0; i < k; i++){
        l[left+i] = m[i];
    }

    for(int i = 0; i < right-left+1; i++){
        printf("%d ", m[i]);
    }

    printf("\n");

    free(m);
}

void merge_sort(int *l, int left, int right){
    if(left == right){
        return;
    }

    int mid = (left+right)/2;

    merge_sort(l, left, mid);
    merge_sort(l, mid+1, right);
    merge(l, left, mid, right);
}

int main(){
    int *list;
    list = (int*)malloc(8*sizeof(int));

    list[0] = 4;
    list[1] = 8;
    list[2] = 3;
    list[3] = 9;
    list[4] = 5;
    list[5] = 2;
    list[6] = 7;
    list[7] = 6;

    merge_sort(list, 0, 7);
    
    return 0;
}