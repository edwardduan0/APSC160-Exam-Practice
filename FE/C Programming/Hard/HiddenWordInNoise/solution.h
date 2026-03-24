#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define STR_LEN 30

/**
 * @brief Main entry point for the Hidden Word in Noise game.
 * 
 * Embeds a hidden target word into a generated string of random noise characters.
 * Prompts the user to find and guess the hidden word.
 * 
 * @return 0 upon successful execution.
 */
int main(void) {
    char *words[] = {"tree", "cat", "fly", "dog"};
    int numWords = 4;
    
    srand(time(NULL));
    int choice = rand() % numWords;
    char *target = words[choice];
    int targetLen = strlen(target);
    
    char puzzle[STR_LEN + 1];
    
    // Fill with noise
    for(int i=0; i<STR_LEN; i++) puzzle[i] = 'a' + rand() % 26;
    puzzle[STR_LEN] = '\0';
    
    // Insert target
    // Max index to insert = STR_LEN - targetLen
    int pos = rand() % (STR_LEN - targetLen + 1);
    for(int i=0; i<targetLen; i++) {
        puzzle[pos + i] = target[i];
    }
    
    printf("Hidden Word Puzzle: %s\n", puzzle);
    
    char guess[100];
    while(1) {
        printf("Guess the hidden word: ");
        if(scanf("%s", guess) != 1) break;
        
        if(strcmp(guess, target) == 0) {
            printf("Correct Guess: %s\n", target);
            break;
        } else {
            printf("Try again.\n");
        }
    }
    
    return 0;
}
