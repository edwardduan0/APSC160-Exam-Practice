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
	int greatestWealth = -1;
	for (int i = 0; i < citizensSize; i++) {
		if (citizens[i] > greatestWealth) greatestWealth = citizens[i];
	}

	int total = 0;
	for (int i = 0; i < citizensSize; i++) {
		total += greatestWealth - citizens[i];
	}
	return total;
}