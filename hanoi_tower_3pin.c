/*
 *Ханойские башни
 *Головоломка <<Ханойские башни>> состоит из трёх стержней, пронумеруем их слева направо: 1, 2 и 3. 
 *Также в головоломке используется стопка дисков с отверстием посередине. 
 *Радиус дисков уменьшается снизу вверх. Изначально диски расположены на левом стержне (стержень 1), 
 *самый большой диск находится внизу. Диски в игре перемещаются по одному со стержня на стержень. 
 *Диск можно надеть на стержень, только если он пустой или верхний диск на нём большего размера, чем перемещаемый. 
 *Цель головоломки — перенести все диски со стержня 1 на стержень 3.
 *Требуется найти последовательность ходов, которая решает головоломку <<Ханойские башни>>.
 *Формат ввода: В первой строке задано одно число nn (3≤n≤10)(3≤n≤10) — количество дисков на первой башне.
 *Формат вывода: В первой строке выведите количество операций k.
                 В следующих k строках выведите по два числа в каждой 
                 xi,yixi​,yi​ (1≤xi,yi≤3)(1≤xi​,yi​≤3) — переместить верхний диск со стержня xixi​ на стержень yiyi​.
*/

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
