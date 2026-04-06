/**
 * @file template.h
 * @brief Read and Equalize Template
 * @author Daylen Chun
 */

#include <stdio.h>

int readAndEqualize(char fileName[], int fileRows, int evenOrOdd);
int calculateModeValue(int nums[], int numsSize);

/**
 * @brief Read values from file and calculate minimum removals needed for equalization
 * @param[in] fileName   The name of the file to read from
 * @param[in] fileRows   The number of rows in the file
 * @param[in] evenOrOdd  Column selector (even/odd determines which column to read)
 * @return The minimum number of values to remove to equalize the array
 */
int readAndEqualize(char fileName[], int fileRows, int evenOrOdd) {
    FILE* inFile = fopen(fileName, "r");
    if (inFile == NULL) return -1;

    int nums[fileRows];
    int i = 0;

    if (evenOrOdd % 2) {
        while (fscanf(inFile, "%d %*d", &nums[i]) == 1) i++;
    } else {
        while (fscanf(inFile, "%*d %d", &nums[i]) == 1) i++;
    }

    fclose(inFile);

    return fileRows - calculateModeValue(nums, fileRows);
    
}

int calculateModeValue(int nums[], int numsSize) {
    int greatestModeValue = 0;
    for (int i = 0; i < numsSize; i++) {
        int currentValue = nums[i];
        int currentValueCount = 0;

        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == currentValue) currentValueCount++;
        }
            
        if (currentValueCount > greatestModeValue) greatestModeValue = currentValueCount;
    }
    return greatestModeValue;
}