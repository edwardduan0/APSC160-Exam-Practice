#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int isValidPassword(const char *pwd);

/**
 * @brief Main entry point for the Random Password Generator program.
 * 
 * Generates a random 10-character password containing at least one uppercase letter,
 * lowercase letter, digit, and symbol. Ensures validity before printing.
 * 
 * @return 0 upon successful execution.
 */
int main(void) {
    char pwd[11]; // 10 chars + null
    const char *symbols = "!@#$%^&*";
    
    srand(time(NULL));

    do {
        // Generate potential password
        for (int i=0; i<10; i++) {
            int type = rand() % 4;
            if (type == 0) pwd[i] = 'A' + rand() % 26;
            else if (type == 1) pwd[i] = 'a' + rand() % 26;
            else if (type == 2) pwd[i] = '0' + rand() % 10;
            else pwd[i] = symbols[rand() % strlen(symbols)];
        }
        pwd[10] = '\0';
    } while (!isValidPassword(pwd));

    printf("Output: %s\n", pwd);
    return 0;
}

/**
 * @brief Checks if a generated password meets all criteria.
 * 
 * @param[in] pwd The null-terminated password string to check.
 * @return 1 (true) if the password contains at least one uppercase letter, lowercase letter, digit, and symbol; 0 (false) otherwise.
 */
int isValidPassword(const char *pwd) {
    int hasUpper=0, hasLower=0, hasDigit=0, hasSymbol=0;
    const char *symbols = "!@#$%^&*";
    for (int i=0; pwd[i]; i++) {
        if (isupper(pwd[i])) hasUpper=1;
        else if (islower(pwd[i])) hasLower=1;
        else if (isdigit(pwd[i])) hasDigit=1;
        else if (strchr(symbols, pwd[i])) hasSymbol=1;
    }
    return hasUpper && hasLower && hasDigit && hasSymbol;
}
