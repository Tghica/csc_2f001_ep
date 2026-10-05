#include <stdio.h>

int sort_get_index(float tab[], int top, float val) {
    for (int index = 0; index < top; index++) {
        if (tab[index] > val) {
            return index;
        }
    }

    return top;
}

void sort_insert_at(float tab[], int i, int *top, float val){
    for( int j = *top; j >= i; j--){
    tab[j] = tab[j - 1];
  }
  tab[i] = val;
    (*top)++;
}

void sort_insert(float tab[], int *top, float val) {
    int index = sort_get_index(tab, *top, val);
        sort_insert_at(tab, index, top, val);
}

int main() {
    float tab[] = {1, 3, 5, 7, 0, 0, 0, 0, 0, 0};
    int top = 4;

    printf("Insert 0 at %d, 3.5 at %d, 10 at %d\n",
           sort_get_index(tab, top, 0),
           sort_get_index(tab, top, 3.5),
           sort_get_index(tab, top, 10));

    for (int index = 0; index < 5; index++) {
        printf("%f ", tab[index]);
    }
    printf("\n");

    return 0;
}