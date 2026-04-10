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
    int sum = 0;
    for (int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    return(sum);
}

/**
 * @brief Calculate the average of integers in an array
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @return The average of all integers in the array
 */
double calculateAverage(int nums[], int numsSize) {
    double average = 0.0;
    for (int i = 0; i < numsSize; i++){
        average += nums[i];
    }
    average = average/numsSize;
    return(average);
}

/**
 * @brief Count elements at or above the average
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @return The number of elements greater than or equal to the average
 */
int calculateAboveOrEqualsAverage(int nums[], int numsSize) {
    int count = 0;
    double average = 0.0;
    for (int i = 0; i < numsSize; i++){
        average += nums[i];
    }
    average = average/numsSize;
    for (int i = 0; i < numsSize; i++){
        if (nums[i] >= average){
            count++;
        }
    }
    return(count);
}