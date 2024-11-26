#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    char n;
    char k;
    scanf("%d %d", &n, &k);
    char n_k = n + k - 1;

    short int op1 = 1;
    short int op2 = 1;
    short int op3 = 1;

    while (n > 0 || k > 0 || n_k > 0) {
        op1 = (n_k > 0 ? op1 * n_k : op1 * 1);
        op2 = (n - 1 > 0 ? op2 * (n - 1) : op2 * 1);
        op3 = (k > 0 ? op3 * k : op3 * 1);
        n--;
        k--;
        n_k--;
    }

    short int c = op1 / op2 / op3;

    printf("%d", c);

    return 0;
}