#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * @brief Main entry point for the Most Frequent Character Game.
 * 
 * Generates a random string of 20 lowercase letters, determines the most frequent character(s),
 * and prompts the user to guess correctly in a loop until they win.
 * 
 * @return 0 upon successful execution.
 */
int main(void) {
    char str[21];
    int freqs[26] = {0};
    int maxFreq = 0;
    
    srand(time(NULL));
    
    // Generate
    for(int i=0; i<20; i++) {
        str[i] = 'a' + rand() % 26;
        freqs[str[i]-'a']++;
    }
    str[20] = '\0';
    
    printf("Sequence: %s\n", str);
    
    // Find max
    for(int i=0; i<26; i++) {
        if (freqs[i] > maxFreq) maxFreq = freqs[i];
    }
    
    char guessChar;
    int guessFreq;
    
    while(1) {
        printf("Guess character: ");
        scanf(" %c", &guessChar);
        printf("Guess frequency: ");
        scanf("%d", &guessFreq);
        
        if (guessFreq == maxFreq && freqs[guessChar-'a'] == maxFreq) {
            printf("You Win!\n");
            break;
        } else {
            printf("Try again.\n");
        }
    }
    
    return 0;
}
