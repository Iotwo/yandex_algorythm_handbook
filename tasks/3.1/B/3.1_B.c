#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    char n;
    char k;
    char n_k;
    scanf("%d %d", &n, &k);
    n_k = n - k;

    short int fact_n = 1;
    short int fact_k = 1;
    short int fact_n_k = 1;

    while (n > 0 || k > 0 || n_k > 0) {
        fact_n = (n > 0? fact_n * n : fact_n * 1);
        fact_k = (k > 0? fact_k * k : fact_k * 1);
        fact_n_k = (n_k > 0? fact_n_k * n_k : fact_n_k * 1);
        n--;
        k--;
        n_k--;
    }

    short int c = fact_n / fact_k / fact_n_k;

    printf("%d", c);

    return 0;
}