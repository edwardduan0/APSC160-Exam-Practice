#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief Main entry point for the Jumbled Sentence Guessing game.
 * 
 * Selects a random sentence, shuffles its words, and prompts the user to guess the original sentence.
 * Continues until the correct sentence is guessed.
 * 
 * @return 0 upon successful execution.
 */
int main(void) {
    char *sentences[] = {
        "the children are playing outside",
        "the cat ate my homework",
        "i am reading a book",
        "please solve this simple puzzle"
    };
    int numSentences = 4;
    
    srand(time(NULL));
    int choice = rand() % numSentences;
    char target[100];
    strcpy(target, sentences[choice]);
    
    // Split
    char *words[5];
    char temp[100];
    strcpy(temp, target);
    char *token = strtok(temp, " ");
    int i=0;
    while(token && i<5) {
        words[i++] = token;
        token = strtok(NULL, " ");
    }
    
    // Shuffle words
    for(int k=0; k<5; k++) {
        int r = rand() % 5;
        char *t = words[k];
        words[k] = words[r];
        words[r] = t;
    }
    
    // Print jumbled
    printf("Jumbled: ");
    for(int k=0; k<5; k++) printf("%s ", words[k]);
    printf("\n");
    
    char guess[100];
    while(1) {
        printf("Guess: ");
        if (!fgets(guess, sizeof(guess), stdin)) break;
        guess[strcspn(guess, "\n")] = 0;
        
        if (strcmp(guess, target) == 0) {
            printf("Correct Guess: %s\n", target);
            break;
        } else {
            printf("Incorrect.\n");
        }
    }
    return 0;
}
