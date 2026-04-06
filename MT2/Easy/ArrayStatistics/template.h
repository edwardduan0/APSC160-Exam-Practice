/**
 * @file template.h
 * @brief Array Statistics Template
 * @author Daylen Chun
 */

int calculateSum(int nums[], int numsSize);
double calculateAverage(int nums[], int numsSize);
int calculateAboveOrEqualsAverage(int nums[], int numsSize);

/**
 * @brief Calculate the sum of integers in an array
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @return The sum of all integers in the array
 */
int calculateSum(int nums[], int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    return total;
}

/**
 * @brief Calculate the average of integers in an array
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @return The average of all integers in the array
 */
double calculateAverage(int nums[], int numsSize) {
    return (double) calculateSum(nums, numsSize) / numsSize;
}

/**
 * @brief Count elements at or above the average
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @return The number of elements greater than or equal to the average
 */
int calculateAboveOrEqualsAverage(int nums[], int numsSize) {
    int count = 0;
    double average = calculateAverage(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= average) count++;
    }
    return count;
}