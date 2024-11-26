#include <stdio.h>
#include <stdlib.h>


void clear_input(void);
unsigned int move_list_len(unsigned int power);
void append_value_to_printer(char **printer, unsigned int prt_len);
void print_printer(char **printer, unsigned int prt_len);
void hanoi_tower(unsigned int disks_cnt, unsigned int from_p, unsigned int to_p, unsigned int *counter, unsigned int print_moves);


void clear_input(void) {
    char c;

    while ((c = getchar()) != '\n' && c != EOF);

    return;
}

void hanoi_tower(unsigned int disks_cnt, unsigned int from_p, unsigned int to_p, unsigned int *counter, unsigned int print_moves) {
    unsigned int unused_p;

    if (disks_cnt == 1) {
        if (print_moves == 1) {
            printf("%u %u\n", from_p, to_p);
        } 
    }
    else {
        unused_p = 6 - from_p - to_p;
        hanoi_tower(disks_cnt - 1, from_p, unused_p, counter, print_moves);
        if (print_moves == 1) {
            printf("%u %u\n", from_p, to_p);
        }
        hanoi_tower(disks_cnt - 1, unused_p, to_p, counter, print_moves);
    }
    (*counter)++;

    return;
}


int main(int argc, char **argv) {
    const unsigned short int N_MIN = 3;
    const unsigned short int N_MAX = 10;

    unsigned int n;
    unsigned int moves_cnt = 0;

    scanf("%u", &n);
    (void)clear_input();
    
    hanoi_tower(n, 1, 3, &moves_cnt, 0);
    printf("%u\n", moves_cnt);
    hanoi_tower(n, 1, 3, &moves_cnt, 1); 
    
    exit(0);
}