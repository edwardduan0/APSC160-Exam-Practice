#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LEN 50

/**
 * @brief Main entry point for the Random Text Mutation program.
 * 
 * Reads a string from the user, applies a random mutation (uppercase, replace, or swap ends),
 * and prints the result. Handles validation for empty input or excessive length.
 * 
 * @return 0 upon successful execution.
 */
int main(void) {
    char word[MAX_LEN + 2]; // +2 for newline and null
    int len;

    srand(time(NULL));

    while (1) {
        printf("Enter a word: ");
        if (fgets(word, sizeof(word), stdin) == NULL) {
            return 0; 
        }

        // Remove newline
        word[strcspn(word, "\n")] = 0;
        len = strlen(word);

        if (len == 0) {
            printf("No characters provided. Please try again.\n");
        } else if (len > MAX_LEN) {
            printf("String exceeds maximum character limit. Please try again.\n");
            // Clear input buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        } else {
            break;
        }
    }

    int choice = rand() % 3;
    int idx;

    switch (choice) {
        case 0: // Uppercase random char
            idx = rand() % len;
            word[idx] = toupper(word[idx]);
            break;
        case 1: // Replace random char with '*'
            idx = rand() % len;
            word[idx] = '*';
            break;
        case 2: // Swap ends
            if (len > 0) {
                char temp = word[0];
                word[0] = word[len - 1];
                word[len - 1] = temp;
            }
            break;
    }

    printf("%s\n", word);
    return 0;
}
