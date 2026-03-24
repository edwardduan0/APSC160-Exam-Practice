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
void fake_srand(unsigned int seed) { next = 12345; }

int main(void) {
    // Feed all potential answers
    FILE *finput = fopen("input.txt", "w");
    fprintf(finput, "tree\ncat\nfly\ndog\n");
    fclose(finput);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    next = 12345;
    student_main();
    fflush(stdout);

    FILE *fout = fopen("output.txt", "r");
    char full[4096] = "";
    char buf[256];
    while(fgets(buf, sizeof(buf), fout)) strcat(full, buf);
    fclose(fout);

    if (strstr(full, "Correct Guess")) {
        fprintf(stderr, "SUCCESS: Found hidden word.\n");
    } else {
        fprintf(stderr, "FAILURE: Did not solve puzzle.\n");
    }
    return 0;
}
