#include <stdio.h>

int main() {
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("%ld\n", nc);

    /* Another way to do it might be */

    for(nc = 0; getchar() != EOF; ++nc)
        ;
    printf("%ld\n", nc);
}
