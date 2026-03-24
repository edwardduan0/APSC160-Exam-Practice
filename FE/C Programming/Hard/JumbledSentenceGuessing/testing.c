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
    // Replicate logic to find the correct answer for the fixed seed
    next = 12345;
    int choice = portable_rand() % 4; // 0..3
    // We assume student uses same set of sentences?
    // Problem says "Store a list of at least four short sentences...". 
    // This is hard to test if student uses different sentences!
    // But Example 1, 2, 3 give specific sentences.
    // If student uses different order, 'choice' index might map to different sentence.
    // Since we can't force the student's data structure, we can verify the output roughly.
    // OR we just provide the input "the children are playing outside" and see if it works?
    // What if the student picks a different sentence?
    // Testing RANDOM scenarios with USER-DEFINED data is very hard in this setup.
    // However, if we feed the correct answer to ALL 4 possibilities, one should hit?
    
    // Actually, we can just print the sentences in the problem description and expect the student to use those.
    // The "Example 1" uses "the children are playing outside".
    // Let's assume the student handles Example 1 as one of the cases.
    
    // For robust testing, we might need to parse the "Jumbled: ..." output to reconstruct the words? 
    // And try all permutations to find the original sentence?
    // That's too complex for `testing.c`.
    
    // Compromise: We feed ALL example sentences as guesses.
    FILE *f = fopen("input.txt", "w");
    fprintf(f, "the children are playing outside\n");
    fprintf(f, "the cat ate my homework\n");
    fprintf(f, "i am reading a book\n");
    fprintf(f, "please solve this simple puzzle\n");
    fclose(f);
    
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
        fprintf(stderr, "SUCCESS: Found winning condition.\n");
    } else {
        fprintf(stderr, "FAILURE: Did not solve puzzle.\n");
    }
    return 0;
}
