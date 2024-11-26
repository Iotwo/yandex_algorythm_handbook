#include <stdio.h>
#include <stdlib.h>


unsigned int search_index_of_min(unsigned int *collection, unsigned int coll_len, unsigned int search_start);
void clear_input(void);
void print_1d_collection(unsigned int *collection, unsigned int coll_len);
void swap_elements(unsigned int *collection, unsigned int pos_a, unsigned int pos_b);


void clear_input(void) {
    char c;

    while ((c = getchar()) != '\n' && c != EOF);

    return;
}

void print_1d_collection(unsigned int *collection, unsigned int coll_len) {
    for(unsigned int i = 0; i < coll_len; i++){ printf("%u ", collection[i]); }
    printf("\n");

    return;
}

unsigned int search_index_of_min(unsigned int *collection, unsigned int coll_len, unsigned int search_start) {
    unsigned int i, current_min;
    current_min = search_start;

    for (i = search_start + 1; i < coll_len; i++) {
        if (collection[current_min] > collection[i]) { current_min = i; }
    }

    return current_min;
}

void swap_elements(unsigned int *collection, unsigned int pos_a, unsigned int pos_b) {
    if (pos_a != pos_b) {
        //(void)printf("0:%hu %hu : %p %p\n",collection[pos_a], collection[pos_b]);
        collection[pos_b] = collection[pos_a] + collection[pos_b];
        //(void)printf("1:%hu %hu : %p %p\n", collection[pos_a], collection[pos_b]);
        collection[pos_a] = collection[pos_b] - collection[pos_a];
        //(void)printf("2:%hu %hu : %p %p\n", collection[pos_a], collection[pos_b]);
        collection[pos_b] = collection[pos_b] - collection[pos_a];
        //(void)printf("3:%hu %hu : %p %p\n", collection[pos_a], collection[pos_b]);
    }

    return;
}


int main(int argc, char **argv) {
    unsigned int curr_pos, curr_min;
    unsigned int n = 0;
    unsigned int *line;

    scanf("%u", &n);
    (void)clear_input();
    line = (unsigned int*)malloc(n * sizeof(unsigned int));
    for(curr_pos = 0; curr_pos < n; curr_pos++) { scanf("%u", &(line[curr_pos])); }
    (void)clear_input();
    //(void)print_1d_collection(line, n);
    
    for(curr_pos = 0; curr_pos < n; curr_pos++) {
        curr_min = search_index_of_min(line, n, curr_pos);
        (void)swap_elements(line, curr_min, curr_pos);
    }
    (void)print_1d_collection(line, n);
    (void)free(line);
    (void)getchar();

    return 0;
}