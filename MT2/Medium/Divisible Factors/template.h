/**
 * @file template.h
 * @brief Divisible Factors Template
 * @author Daylen Chun
 */

#include <stdio.h>

#define fileName "factors.txt"

int divisible_factors(int n, int d, int output_array[]);

/**
 * @brief Find divisible factors of n and write them to a file
 * @param[in] n             Number to find factors of
 * @param[in] d             Divisor
 * @param[out] output_array Array to be filled with divisible factors
 * @modifies Creates a file "factors.txt" with the factors of n
 * @modifies output_array to be filled with divisible factors
 * @return The size of output_array
 */
int divisible_factors(int n, int d, int output_array[]) {
    FILE* inFile; 
    inFile = fopen(fileName, "w");
    int i = 1;
    int count = 0;
    for (i; i <= n; i++){
        if (n % i == 0){
            fprintf(inFile, "%d ", i);
            if (i % d == 0){ 
                output_array[count] = i;
                count++;
            }
        }
        
    }
    fclose(inFile);
    return(count);
}