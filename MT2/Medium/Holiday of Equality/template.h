/**
 * @file template.h
 * @brief Holiday of Equality Template
 * @author Daylen Chun
 */

#include <stdio.h>

int minimumBurlesToSpend(int[], int);

/**
 * @brief Calculate minimum cost to equalize citizens' welfare
 * @param[in] citizens     Array of integers representing each citizen's welfare
 * @param[in] citizensSize Size of the citizens array
 * @return The minimum number of burles to spend to equalize welfare
 */
int minimumBurlesToSpend(int citizens[], int citizensSize) {
	int max = 0;
	int spend = 0;
	for (int i = 0; i < citizensSize - 1; i++){ //find the richest citizen
		if (citizens[i+1] > citizens[i] && citizens[i+1] > max){
			max = citizens[i+1];
		}
		else if (citizens[i]>citizens[i+1]){
			max = citizens[i];
		}
	}
	for (int i = 0; i < citizensSize; i++){
		if (citizens[i] <= max){
			spend += max - citizens[i];
		}
	}
	return(spend);
}