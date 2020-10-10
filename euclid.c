#include <stdio.h>

//log_n
int euclid(int i, int j){
    int r,n,m;

    if(i < j){
        n = j;
        m = i;
    }else{
        n = i;
        m = j;
    }

    while(m != 0){
        r = n%m;
        n = m;
        m = r;
    }

    return n;
}

int main(){
    printf("%d\n", euclid(126, 70));

    return 0;
}