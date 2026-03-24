#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/**
 * @brief Main entry point for the Random Digit String Analysis program.
 * 
 * Generates a random string of 20 digits, prompts the user to search for a digit,
 * counts the occurrences, and displays the result.
 * 
 * @return 0 upon successful execution.
 */
int main(void) {
    char str[21];
    int i;
    int count = 0;
    char target;

    srand(time(NULL));

    // 1. Generate random string of 20 digits
    for (i = 0; i < 20; i++) {
        str[i] = (rand() % 10) + '0';
    }
    str[20] = '\0';

    // 2. Display sequence
    printf("Generated Sequence: %s\n", str);

    // 3. Prompt user
    printf("Enter a digit to search for: ");
    scanf(" %c", &target);

    // 4. Count occurrences
    for (i = 0; i < 20; i++) {
        if (str[i] == target) {
            count++;
        }
    }

    // 5. Output result
    printf("Digit %c appears %d times.\n", target, count);

    return 0;
}
