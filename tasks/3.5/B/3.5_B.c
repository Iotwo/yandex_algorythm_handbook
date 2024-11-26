#include <stdio.h>
#include <stdlib.h>


unsigned int all_iters_reached_end(unsigned int* iters_col, unsigned int* iters_limits, unsigned int coll_width);
unsigned int get_sum_of_collection(unsigned int* collection, unsigned int coll_len);
unsigned int search_index_of_min(long int* collection, unsigned int coll_len, unsigned int search_start);
long int* search_least_elem_in_collection(long int** collection, unsigned int coll_width, unsigned int* colls_i, unsigned int* colls_lims);

void clear_input(void);
void print_1d_collection(unsigned int* collection, unsigned int coll_len);
void move_elem_from_colls_to_merge(long int* merge_vec, unsigned int merge_v_len, long int* moved_elem);
void swap_elements(unsigned int* collection, unsigned int pos_a, unsigned int pos_b);


unsigned int all_iters_reached_end(unsigned int* iters_col, unsigned int* iters_limits, unsigned int coll_width) {
    unsigned int counter = 0;
    for (unsigned int i = 0; i < coll_width; i++) {
        if (*(iters_col + i) == *(iters_limits + i)) { counter++; }
    }

    if (counter == coll_width) { return 1; }
    else { return 0; }
}
unsigned int get_sum_of_collection(unsigned int* collection, unsigned int coll_len) {
    unsigned int total_value = 0;
    for (unsigned int i = 0; i< coll_len; i++) { total_value += *(collection + i); }

    return total_value;
}
unsigned int search_index_of_min(long int* collection, unsigned int coll_len, unsigned int search_start) {
    unsigned int current_min;
    current_min = search_start;
    for (unsigned int i = search_start; i < coll_len; i++) {
        if (collection[current_min] > collection[i]) { current_min = i; }
    }

    return current_min;
}
long int* search_least_elem_in_collection(long int** collection, unsigned int coll_width, unsigned int* colls_i, unsigned int* colls_lims) {
    const long int MAX = 1000000001;
    long int* least_elem = (long int*)malloc(sizeof(long int));; 
    long int* curr_slice;
    unsigned int i, current_min_idx;

    *least_elem = MAX;  // more than available maximum for that task
    curr_slice = (long int*)malloc(coll_width * sizeof(long int));
    for (i = 0; i < coll_width; i++) { 
        if (*(*(collection + i) + *(colls_i + i)) != 0 && *(colls_i + i) < *(colls_lims + i)) { 
            *(curr_slice + i) = *(*(collection + i) + *(colls_i + i)); 
        }
        else { *(curr_slice + i) = MAX; }
    }
    current_min_idx = search_index_of_min(curr_slice, coll_width, 0);
    least_elem = (*(collection + current_min_idx) + *(colls_i + current_min_idx));
    (*(colls_i + current_min_idx))++;

    return least_elem;
}

void clear_input(void) {
  char c;

  while ((c = getchar()) != '\n' && c != EOF);

  return;
}
void print_1d_collection(long int *collection, unsigned int coll_len) {
    for(unsigned int i = 0; i < coll_len; i++){ printf("%u ", collection[i]); }
    printf("\n");

    return;
}
void move_elem_from_colls_to_merge(long int* merge_vec, unsigned int merge_curr_pos, long int* moved_elem) {
    *(merge_vec + merge_curr_pos) = *moved_elem;
    *moved_elem = 0;
    moved_elem = 0;

    return;
}
void swap_elements(unsigned int *collection, unsigned int pos_a, unsigned int pos_b) {
    if (pos_a != pos_b) {
        collection[pos_b] = collection[pos_a] + collection[pos_b];
        collection[pos_a] = collection[pos_b] - collection[pos_a];
        collection[pos_b] = collection[pos_b] - collection[pos_a];
    }

    return;
}


int main(int argc, char **argv) {
    unsigned int coll_cnt, total_len;  // collections count
    unsigned int i, j;
    scanf("%u", &coll_cnt);
    (void)clear_input();
    unsigned int* colls_lens = (unsigned int*)malloc(coll_cnt * sizeof(unsigned int));
    long int* curr_least;
    unsigned int* coll_iters = (unsigned int*)malloc(coll_cnt * sizeof(unsigned int));
    long int** colls = (long int**)malloc(coll_cnt * sizeof(long int*));  // collections

    for (i = 0; i < coll_cnt; i++) {
        scanf("%u", (colls_lens + i));
        (void)clear_input();
        *(coll_iters+i) = 0;
        *(colls+i) = (long int *)malloc(colls_lens[i] * sizeof(long int));
        for (j = 0; j < *(colls_lens + i); j++) { scanf("%u", (*(colls + i) + j)); }
        (void)clear_input();  
    }

    total_len = get_sum_of_collection(colls_lens, coll_cnt);
    long int* total_col = (long int*)malloc(total_len * sizeof(long int));
    i = 0;
    while (all_iters_reached_end(coll_iters, colls_lens, coll_cnt) != 1 && i < total_len) {
        curr_least = search_least_elem_in_collection(colls, coll_cnt, coll_iters, colls_lens);
        (void)move_elem_from_colls_to_merge(total_col, i, curr_least);
        i++;
    }
    (void)print_1d_collection(total_col, total_len);

    return 0;
}