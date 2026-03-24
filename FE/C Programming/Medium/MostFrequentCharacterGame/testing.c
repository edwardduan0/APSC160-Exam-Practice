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
    // With fixed seed, we know the sequence.
    // However, it's easier to just run a solution logic here to find the answer to feed as input.
    // Re-generate sequence with same logic
    next = 12345; // Reset
    char str[21];
    int freqs[26] = {0};
    int maxFreq = 0;
    for(int i=0; i<20; i++) {
        str[i] = 'a' + portable_rand() % 26;
        freqs[str[i]-'a']++;
    }
    for(int i=0; i<26; i++) {
        if(freqs[i] > maxFreq) maxFreq = freqs[i];
    }
    // Find first winning char
    char winner = 'a';
    for(int i=0; i<26; i++) {
        if(freqs[i] == maxFreq) { winner = 'a'+i; break; }
    }
    
    // Prepare input
    FILE *f = fopen("input.txt", "w");
    fprintf(f, "%c\n%d\n", winner, maxFreq);
    fclose(f);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    // Reset seed for student
    next = 12345;
    student_main();
    fflush(stdout);
    
    // Verify
    FILE *fout = fopen("output.txt", "r");
    char full[4096] = "";
    char buf[256];
    while(fgets(buf, sizeof(buf), fout)) strcat(full, buf);
    fclose(fout);
    
    if (strstr(full, "You Win!")) {
        fprintf(stderr, "SUCCESS: Game won with correct input.\n");
    } else {
        fprintf(stderr, "FAILURE: Did not detect win message.\n");
    }
    return 0;
}
