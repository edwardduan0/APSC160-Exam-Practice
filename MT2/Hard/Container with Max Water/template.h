/**
 * @file template.h
 * @brief Container with Max Water Template
 * @author Daylen Chun
 */

#include <math.h> // Contains fmax(double num1, double num2) and fmin (double num1, double num2)

int containerWithMaxWater(int heights[], int heightSize);

/**
 * @brief Find the maximum water that can be contained between two heights
 * @param[in] heights    Array of height values
 * @param[in] heightSize Size of the heights array
 * @return The maximum water that can be contained by two heights
 */
int containerWithMaxWater(int height[], int heightSize) {
    int area;
    int max = 0;
    for (int i = 0; i < heightSize - 1; i++){
        for (int j = i + 1; j < heightSize; j++){
            area = fmin(height[i], height[j]) * (j-i);
            if (area > max){
                max = area;
            }
        }
    }
    return(max);
}