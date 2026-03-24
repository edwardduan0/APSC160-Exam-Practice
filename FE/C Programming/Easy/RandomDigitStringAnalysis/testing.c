#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// HIJACK MACROS
int portable_rand(void);
void fake_srand(unsigned int seed);
#undef rand
#undef srand
#define rand portable_rand
#define srand fake_srand
#define main student_main

/* ============ DO NOT CHANGE ANYTHING ABOVE THIS LINE ============ */
// Change this to either "template.h" or "solution.h" to test
#include "template.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static unsigned long int next = 1;

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void fake_srand(unsigned int seed) {
    next = 123456789; // Fixed seed for deterministic testing
}

int main(void) {
    // Prepare input mocking
    // We'll test looking for digit '3'
    FILE *finput = fopen("input.txt", "w");
    if (!finput) { perror("Failed to create input.txt"); return 1; }
    fprintf(finput, "3\n"); 
    fclose(finput);

    if (!freopen("input.txt", "r", stdin)) { perror("freopen stdin failed"); return 1; }
    
    // Capture output
    if (!freopen("output.txt", "w", stdout)) { perror("freopen stdout failed"); return 1; }

    // Run student code with fixed seed
    // We don't call srand because student code calls it. 
    // We assume student calls srand(time(NULL)), which maps to fake_srand.
    // However, fake_srand sets 'next'. We want 'next' to be deterministic.
    // So we rely on student calling srand to reset 'next' or not.
    // Ideally we force 'next' to a known state AFTER student calls srand?
    // No, fake_srand sets next=seed. 'time(NULL)' varies. 
    // We should probably hijack time() too? Or make fake_srand ignore the seed?
    // Let's modify fake_srand to ignore the seed and set a FIXED seed.
    
    // Reset next first in case student DOESN'T call srand (though they should)
    next = 12345;
    
    student_main();
    
    // Now verify output
    // Since we are capturing stdout, we can't print test results easily to console.
    // We usually write to stderr for test results.
    
    fflush(stdout);
    
    // Read output
    FILE *foutput = fopen("output.txt", "r");
    if (!foutput) { fprintf(stderr, "Failed to read output.txt\n"); return 1; }
    
    char buffer[1024];
    char fullOutput[4096] = "";
    while (fgets(buffer, sizeof(buffer), foutput)) {
        strcat(fullOutput, buffer);
    }
    fclose(foutput);
    
    // Check if '3' string matches what we expect from seed 12345
    // With seed 12345 (if student calls srand(12345))?
    // Student calls srand(time(NULL)). We need to make sure that results in a known sequence.
    // We'll change fake_srand to always set seed to 1.
    
    fprintf(stderr, "--- Test Output ---\n%s\n-------------------\n", fullOutput);
    
    // Check for "Digit 3 appears"
    if (strstr(fullOutput, "Digit 3 appears")) {
        fprintf(stderr, "SUCCESS: Output format correct.\n");
    } else {
        fprintf(stderr, "FAILURE: Output format incorrect or missing.\n");
    }
    
    return 0;
}
