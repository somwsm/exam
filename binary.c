#include <stdio.h>

//log_n
int binary_search(int *a, int size, int d){
    int l = 0;
    int r = size-1;

    while(l < r){
        int now = (l+r)/2;
        if(a[now] == d){
            return now;
        }
        
        if(a[now] > d){
            r = now-1;
        }else{
            l = now+1;
        }
    }

    if(a[l] == d){
        return l;
    }

    return -1;
}

int main(){
    int a[] = {1, 2, 3, 4};
    int size = (int)(sizeof(a) / sizeof(a[0]));

    printf("%d\n", binary_search(a, size, 4));

    return 0;
}