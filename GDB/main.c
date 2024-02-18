/*
* instructions:
* this code has a bug and our objective is to find it
*
* this program must be compiled with `gcc`.
* is important that we pass the flag `-g`
* to inform our compiler to generate it in 
* debug format.
*
* command:
* `gcc -o main main.c -g`.
*
* gdb useful commands:
* first execute the generated binary file with gdb:
* `gdb ./main`.
*
* - `layout next`
* - `break main`
* - `run`
* - `next`
* - `nexti`
* - `step`
* - `ref`
*
*/
#include <stdio.h>

int main(int argc, char **argv) {
    int d = 2;
    printf("Welcome to a program with a bug!\n");

    scanf("%d", d);

    printf("You gave me: %d\n", d);
    return 0;
}
