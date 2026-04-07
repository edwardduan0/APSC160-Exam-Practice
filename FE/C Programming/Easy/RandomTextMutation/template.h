/**
 * @file template.h
 * @brief Random Text Mutation Template
 * @author Daylen Chun
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 50
#define NUM_MUTATIONS 3

int main(void) {
    int indexModified;
    int mutationChosen;
    srand(time(NULL));

    char randomString[MAX_STRING_LENGTH];

    scanf("%99[^\n]", randomString);

    while (strlen(randomString) > 50 || randomString == 0) {
        printf("Error. Please try again.\n");
        scanf("%99[^\n]", randomString);
    }

    indexModified = rand() % strlen(randomString);
    mutationChosen = rand() % NUM_MUTATIONS;

    if (mutationChosen == 0) {
        randomString[indexModified] = toupper(randomString[indexModified]);
    }

    else if (mutationChosen == 1) {
        randomString[indexModified] = '*';
    }

    else {
        char temp = randomString[0];
        randomString[0] = randomString[strlen(randomString) - 1];
        randomString[strlen(randomString) - 1] = temp;
    }

    printf("%s", randomString);

    return 0;
}