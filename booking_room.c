/*
 *Бронирование переговорки
 *Задано n интервалов. Требуется найти максимальное количество взаимно непересекающихся интервалов.
 *Два интервала пересекаются, если они имеют хотя бы одну общую точку.
 *Формат ввода: В первой строке задано одно число n (1≤n≤100)(1≤n≤100) — количество интервалов.
 *              В следующих nn строках заданы интервалы li,rili​,ri​ (1≤li≤ri≤50)(1≤li​≤ri​≤50).
 *Формат вывода: Выведите ответ на задачу
*/

#include <stdio.h>
#include <stdlib.h>


unsigned short int count_uncrossing_intervals(unsigned short int coll_size, unsigned short int coll[][3]);
void clear_input(void);
void mark_crossing_intervals(unsigned short int coll_size, unsigned short int coll[][3]);
void sort_collection_asc(unsigned short int coll_size, unsigned short int coll[][3]);


unsigned short int count_uncrossing_intervals(unsigned short int coll_size, unsigned short int coll[][3]) {
	unsigned short int total = 0;

	for (int i = 0; i< coll_size; i++) {
		total += coll[i][2];
	}

	return total;
}

void clear_input(void) {
	char c;

	while ((c = getchar()) != '\n' && c != EOF);

	return;
}

void mark_crossing_intervals(unsigned short int coll_size, unsigned short int coll[][3]) {
	/*
	 Mark crossing intervals placing 0 in third position of every interval block
	*/

	unsigned short int i, j;

	if (coll_size == 1) { return; }
	for (i = 0; i < coll_size - 1; i++) {
		if (coll[i][2] == 1) {
			for (j = i + 1; j < coll_size; j++) {
				if (coll[j][0] <= coll[i][1]) {
					coll[j][2] = 0;
				} 
			}
		}
	}

	return;
}

void sort_collection_asc(unsigned short int coll_size, unsigned short int coll[][3]) {
	/*
	 Sort given collection in ascending order of right bound
	*/

	unsigned short int i, j, sw;

	if (coll_size == 1) { return; }
	for (i = 0; i < coll_size - 1; i++) {
		for (j = i + 1; j < coll_size; j++) {
			if (coll[i][1] > coll[j][1]) {
				sw = coll[j][0];
				coll[j][0] = coll[i][0];
				coll[i][0] = sw;
				sw = coll[j][1];
				coll[j][1] = coll[i][1];
				coll[i][1] = sw;
			}
		}
	}

	return;
}


int main(int argc, char* argv[]) {
	unsigned short int i_cnt, i;
	scanf("%hu", &i_cnt);
	(void)clear_input();

	unsigned short int intervals[i_cnt][3];
	for (i = 0; i< i_cnt; i++) { 
		scanf("%hu %hu", &intervals[i][0], &intervals[i][1]);
		(void)clear_input();
		intervals[i][2] = 1;  // interval not excluded from list
	}
	(void)sort_collection_asc(i_cnt, intervals);
	(void)mark_crossing_intervals(i_cnt, intervals);
	printf("%hu", count_uncrossing_intervals(i_cnt, intervals));

	return 0;
}
