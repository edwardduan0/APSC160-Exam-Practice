#include <stdbool.h>
#include <string.h>

bool isPalindrome(char word[]);

/**
 * @brief Checks if a given word is a palindrome.
 * @param[in] word The input string to check.
 * @return true if the word is a palindrome, false otherwise.
 */
bool isPalindrome(char word[]) {
    bool isPalin = true;
    for (int i = 0; i < strlen(word) / 2; i++) {
        if (word[i] != word[strlen(word) - 1 - i]) {
            isPalin = false;
        }
    }
    return isPalin;
}