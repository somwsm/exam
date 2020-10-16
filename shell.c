#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *l, int size){
    int h[] = {4, 3, 1};
    
    for(int i = 0; i < 3; i++){
        for(int j = h[i]; j < size; j++){
            int d = l[j];
            int k = j-h[i];
            while(k >= 0 && d < l[k]){
                l[k+h[i]] = l[k];
                k -=h[i];
            }

            l[k+h[i]] = d; 
        }

        for(int t = 0; t < 5; t++){
            printf("%d ", l[t]);
        }

        printf("\n"); 
    }
}

int main(){
    int *list;
    list = (int*)malloc(5*sizeof(int));

    list[0] = 8;
    list[1] = 3;
    list[2] = 2;
    list[3] = 7;
    list[4] = 5;

    shell_sort(list, 5);

    free(list);

    return 0;

}