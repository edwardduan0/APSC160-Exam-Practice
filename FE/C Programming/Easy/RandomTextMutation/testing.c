#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int portable_rand();
void fake_srand(unsigned int seed);
#undef rand
#undef srand
#define rand portable_rand
#define srand fake_srand
#define main student_main
#include "template.h"
#undef main

static unsigned long int next = 1;
int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}
void fake_srand(unsigned int seed) {
    next = 12345; // Fixed seed
}

int main(void) {
    FILE *finput = fopen("input.txt", "w");
    fprintf(finput, "hello\n");
    fclose(finput);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    student_main();

    fflush(stdout);
    fprintf(stderr, "Test completed. Check output.txt for mutated string.\n");
    return 0;
}
