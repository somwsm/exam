#include <stdio.h>
#include <stdlib.h>

typedef struct ilist{
    int *array;
    int size;
    int capacity;
} Ilist;

void free_ilist(Ilist *l){
    free(l);
    l = NULL;
}

Ilist *new_ilist(){
    Ilist *list;
    list = NULL;
    free_ilist(list);
    list = (Ilist*)malloc(sizeof(Ilist));
    list->array = (int*)malloc(10*sizeof(int));

    if(list != NULL){
        list->size = 0;
        list->capacity = 10;

        for(int i = 0; i < list->capacity; i++){
            list->array[i] = 0;
        }
    }

    return list;
}

void expand(Ilist *l){
    l->array = realloc(l->array, sizeof(int));
    l->capacity++;
}

void append(Ilist *l, int x){
    if(l->size == l->capacity){
        expand(l);
    }

    l->size++;
    l->array[l->size - 1] = x;
}

int find_pos(Ilist *l, int x){
    int lower, upper, i;
    lower = 0;
    upper = l->size;

    while(lower < upper){
        int i = (lower + upper)/2;
        if(l->array[i] == x){
            return i;
        }else if(l->array[i] > x){
            upper = i;
        }else{
            lower = i+1;
        }
    }

    return lower;
}

void insert(Ilist *l, int x){
    int i,j;
    if(l->size == l->capacity){
        expand(l);
    }

    i = find_pos(l, x);

    for(j = l->size-1; j >= i; j--){
        l->array[j+1] = l->array[j];
    }

    l->array[i] = x;
    l->size++;
}

Ilist *make_list(){
    Ilist *l;
    l = new_ilist();
    append(l, 20);
    insert(l, 10);
    append(l, 30);
    append(l, 50);
    append(l, 60);
    append(l, 70);
    insert(l, 40);

    return l;
}

Ilist *uniq(Ilist *l){
    Ilist *u;

    u = new_ilist();

    int x, i;

    if(l->size == 0){
        return u;
    }

    x = l->array[0];
    append(u, x);

    for(i = 1; i < l->size; i++){
        if(l->array[i] != l->array[i-1]){
            x = l->array[i];
            append(u, x);
        }
    }

    return u;
}

Ilist *make_listu(){
    Ilist *l;
    l = new_ilist();

    append(l, 10);
    append(l, 10);
    append(l, 10);
    append(l, 20);
    append(l, 30);
    append(l, 30);
    append(l, 40);

    return l;
}

Ilist *merge(Ilist *a, Ilist *b){
    Ilist *l;

    l = new_ilist();

    int i, j;

    i = 0;
    j = 0;

    while(i != a->size && j != b->size){
        if(a->array[i] < b->array[j]){
            append(l, a->array[i]);
            i++;
        }else{
            append(l, b->array[j]);
            j++;
        }
    }

    if(i != a->size){
        for(; i < a->size; i++){
            append(l, a->array[i]);
        }
    }else{
        for(; j < b->size; j++){
            append(l, b->array[j]);
        }
    }

    return l;
}

Ilist *make_listm1(){
    Ilist *l;
    l = new_ilist();

    append(l, 10);
    append(l, 30);
    append(l, 40);

    return l;
}

Ilist *make_listm2(){
    Ilist *l;
    l = new_ilist();

    append(l, 20);
    append(l, 50);
    append(l, 60);

    return l;
}

int main(){
    Ilist *l = make_list();

    for(int i = 0; i < l->size; i++){
        printf("%d ", l->array[i]);
    }
    printf("\n");

    free_ilist(l);

    /*Ilist *ul = make_listu();

    Ilist *u = uniq(ul);

    for(int i = 0; i < u->size; i++){
        printf("%d ", u->array[i]);
    }
    printf("\n");

    free_ilist(ul);

    Ilist *m1 = make_listm1();
    Ilist *m2 = make_listm2();

    Ilist *m = merge(m1, m2);

    for(int i = 0; i < m->size; i++){
        printf("%d ", m->array[i]);
    }
    printf("\n");

    free_ilist(m1);
    free_ilist(m2);
    free_ilist(m);*/

    return 0;
}