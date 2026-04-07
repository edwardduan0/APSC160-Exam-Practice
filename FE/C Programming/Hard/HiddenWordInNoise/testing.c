/**
 * @file testing.c
 * @brief Autograder for Hidden Word in Noise
 * @author Daylen Chun
 */

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
#include "solution.h"
/* ============ DO NOT CHANGE ANYTHING BELOW THIS LINE ============ */

#undef main

static unsigned long int next = 1;

int portable_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void fake_srand(unsigned int seed) {
    (void)seed;
    next = 12345;
}

// ========== HELPER VALIDATION FUNCTIONS ==========

/**
 * Word list matching solution
 */
static const char *WORD_LIST[] = {"tree", "cat", "fly", "book", "sun"};
static const int WORD_LIST_SIZE = 5;

/**
 * Derive the expected target word based on deterministic RNG
 */
static const char *getTargetWord(void) {
    next = 12345;
    int wordIdx = portable_rand() % WORD_LIST_SIZE;
    return WORD_LIST[wordIdx];
}

/**
 * Extract the 30-character hidden string from output
 */
static int extractHiddenString(const char *output, char *hiddenStr) {
    const char *p = output;

    while (*p) {
        // Skip until we find a lowercase letter
        if (!islower(*p)) {
            p++;
            continue;
        }

        // Count consecutive lowercase letters
        int len = 0;
        char temp[50] = "";
        const char *start = p;
        while (*p && islower(*p) && len < 50) {
            temp[len++] = *p;
            p++;
        }

        // Check if this is a 30-char sequence
        if (len == 30) {
            strcpy(hiddenStr, temp);
            return 1;
        }

        // If we didn't find 30 but found significant length, reset
        if (len > 0 && len != 30) {
            p = start + 1;
        }
    }

    return 0;
}

/**
 * Verify the hidden string contains the target word
 */
static int verifyHiddenString(const char *hiddenStr, const char *targetWord) {
    if (strlen(hiddenStr) != 30) {
        return 0;
    }

    // Check if target word appears as a substring
    return (strstr(hiddenStr, targetWord) != NULL) ? 1 : 0;
}

/**
 * Check for "Correct Guess" message in output
 */
static int hasCorrectGuessMessage(const char *output, const char *word) {
    if (strstr(output, "Correct Guess") == NULL) {
        return 0;
    }
    return (strstr(output, word) != NULL) ? 1 : 0;
}

/**
 * Check for user interaction prompts
 */
static int hasInteraction(const char *output) {
    return (strstr(output, "Enter your guess") != NULL) ||
           (strstr(output, "guess") != NULL);
}

/**
 * Create input file with test guesses
 */
static int writeInputFile(const char *correctWord) {
    FILE *finput = fopen("input.txt", "w");
    if (finput == NULL) {
        fprintf(stderr, "Failed to create input.txt\n");
        return 0;
    }
    fprintf(finput, "wrong\n%s\n", correctWord);
    fclose(finput);
    return 1;
}

/**
 * Capture program output to buffer
 */
static int captureProgramOutput(const char *correctWord, char outputBuffer[], size_t bufferSize) {
    if (!writeInputFile(correctWord)) {
        return 0;
    }

    if (!freopen("input.txt", "r", stdin)) {
        perror("freopen stdin failed");
        return 0;
    }

    if (!freopen("output.txt", "w", stdout)) {
        perror("freopen stdout failed");
        return 0;
    }

    next = 12345;
    student_main();
    fflush(stdout);

    FILE *foutput = fopen("output.txt", "r");
    if (foutput == NULL) {
        fprintf(stderr, "Failed to read output.txt\n");
        return 0;
    }

    outputBuffer[0] = '\0';
    char chunk[1024];
    while (fgets(chunk, sizeof(chunk), foutput) != NULL) {
        strncat(outputBuffer, chunk, bufferSize - strlen(outputBuffer) - 1);
    }
    fclose(foutput);
    return 1;
}

// ========== TEST CASE RUNNER ==========

typedef struct {
    int caseNumber;
    bool passed;
    char hiddenString[35];
    char targetWord[20];
    bool foundString;
    bool stringValid;
    bool hasCorrectMessage;
    bool hasInteraction;
} TestResult;

static TestResult runTestCase(int caseNumber) {
    TestResult result;
    result.caseNumber = caseNumber;
    result.passed = false;
    result.foundString = false;
    result.stringValid = false;
    result.hasCorrectMessage = false;
    result.hasInteraction = false;
    strcpy(result.hiddenString, "");
    strcpy(result.targetWord, "");

    // Get expected target word
    const char *expectedTarget = getTargetWord();
    strcpy(result.targetWord, expectedTarget);

    // Capture program output
    char output[2048] = "";
    if (!captureProgramOutput(expectedTarget, output, sizeof(output))) {
        return result;
    }

    // Extract and validate hidden string
    result.foundString = extractHiddenString(output, result.hiddenString);
    if (result.foundString) {
        result.stringValid = verifyHiddenString(result.hiddenString, expectedTarget);
    }

    // Check for interaction and correct message
    result.hasInteraction = hasInteraction(output);
    result.hasCorrectMessage = hasCorrectGuessMessage(output, expectedTarget);

    // Pass if all conditions met
    result.passed = result.foundString && result.stringValid &&
                    result.hasInteraction && result.hasCorrectMessage;

    return result;
}

// ========== MAIN TEST HARNESS ==========

int main(void) {
    fprintf(stderr, "=== Hidden Word in Noise Autograder ===\n");
    fprintf(stderr, "Testing hidden word generation and guessing...\n\n");

    int totalTests = 5;
    int passedTests = 0;

    for (int i = 1; i <= totalTests; i++) {
        TestResult result = runTestCase(i);

        if (result.passed) {
            fprintf(stderr, "Test Case %d: PASS\n", result.caseNumber);
            fprintf(stderr, "  Hidden string (30 chars): %s\n", result.hiddenString);
            fprintf(stderr, "  Target word: '%s'\n", result.targetWord);
            fprintf(stderr, "  Word found in string: yes\n");
            fprintf(stderr, "  Accepts user input: yes\n");
            fprintf(stderr, "  Correct guess message: yes\n\n");
            passedTests++;
        } else {
            fprintf(stderr, "Test Case %d: FAIL\n", result.caseNumber);

            if (!result.foundString) {
                fprintf(stderr, "  ERROR: Could not extract a 30-character hidden string from output\n");
            } else if (!result.stringValid) {
                fprintf(stderr, "  ERROR: Hidden string does not contain target word '%s'\n",
                        result.targetWord);
                fprintf(stderr, "  String found: %s\n", result.hiddenString);
            } else if (!result.hasInteraction) {
                fprintf(stderr, "  ERROR: Program does not prompt for user input\n");
            } else if (!result.hasCorrectMessage) {
                fprintf(stderr, "  ERROR: Program does not output 'Correct Guess' message\n");
            }

            fprintf(stderr, "\n");
        }
    }

    fprintf(stderr, "=== Summary ===\n");
    fprintf(stderr, "Passed: %d/%d tests\n\n", passedTests, totalTests);

    if (passedTests == totalTests) {
        fprintf(stderr, "✓ All tests passed! Solution is correct.\n");
    } else {
        fprintf(stderr, "✗ Some tests failed. Review the errors above.\n");
    }

    return 0;
}
