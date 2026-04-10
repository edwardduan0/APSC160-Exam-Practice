/**
 * @file template.h
 * @brief Two Sum Template
 * @author Daylen Chun
 */

#include <stdio.h>
int twoSum(int[], int, int);

/**
 * @brief Find the smallest sum of indices where two values equal target
 * @param[in] nums       Array of integers
 * @param[in] numsSize   Size of the array
 * @param[in] target     The target sum value
 * @return The sum of indices where nums[i] + nums[j] == target, or -1 if not found
 */
int twoSum (int nums[], int numsSize, int target) {
    int sum = 10000;
    for (int i = 0; i < numsSize; i++){
        for (int j = 1; j < numsSize; j++){
            if (nums[i] + nums[j] == target && i != j && nums[i] + nums[j] < sum){
                sum = i + j;
            }
        }
    }
    if (sum == 10000){
        return(-1);
    }
    else{
        return(sum);
    }
}