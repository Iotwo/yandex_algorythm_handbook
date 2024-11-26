#include <stdio.h>
#include <stdlib.h>


void clear_input(void);


void clear_input(void) {
    char c;

    while ((c = getchar()) != '\n' && c != EOF);

    return ;
}


int main(int argc, char** argv) {
    const short unsigned int IN_MIN = 1;
    const short unsigned int IN_MAX = 10;

    short unsigned int n, m;

    scanf("%hu %hu", &n, &m);
    clear_input();

    if (n % 2 == 0 && m % 2 == 0) { printf("Loose"); }
    else { printf("Win"); }

    return 0;
}