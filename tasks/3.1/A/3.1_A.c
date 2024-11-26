#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    char n;
    scanf("%d", &n);
    int perm = 1;

    while (n > 0) {
        perm *= n;
        n--;
    }

    printf("%d", perm);

    return 0;
}