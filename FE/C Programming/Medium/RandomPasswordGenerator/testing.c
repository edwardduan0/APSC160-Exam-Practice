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
    next = 12345;
}

// Re-implement validation for testing purposes
int test_isValid(const char *pwd) {
    int hasUpper=0, hasLower=0, hasDigit=0, hasSymbol=0;
    const char *symbols = "!@#$%^&*";
    if (strlen(pwd) != 10) return 0;
    for (int i=0; pwd[i]; i++) {
        if (isupper(pwd[i])) hasUpper=1;
        else if (islower(pwd[i])) hasLower=1;
        else if (isdigit(pwd[i])) hasDigit=1;
        else if (strchr(symbols, pwd[i])) hasSymbol=1;
    }
    return hasUpper && hasLower && hasDigit && hasSymbol;
}

int main(void) {
    // Capture stdout
    freopen("output.txt", "w", stdout);
    student_main();
    fflush(stdout);

    // Verify
    FILE *f = fopen("output.txt", "r");
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), f)) {
        // Expected "Output: <pwd>"
        char *pwd = strchr(buffer, ':');
        if (pwd) {
            pwd += 2; // Skip ": "
            // Trim newline
            pwd[strcspn(pwd, "\n")] = 0;
            if (test_isValid(pwd)) {
                fprintf(stderr, "SUCCESS: Password '%s' is valid.\n", pwd);
            } else {
                fprintf(stderr, "FAILURE: Password '%s' is invalid.\n", pwd);
            }
        }
    }
    fclose(f);
    return 0;
}
