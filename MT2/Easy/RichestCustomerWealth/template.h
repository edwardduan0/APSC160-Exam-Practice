/**
 * @file template.h
 * @brief Richest Customer Wealth Template
 * @author Daylen Chun
 */

int richestCustomerWealth(int NUMROWS, int NUMCOLS, int accounts[][NUMCOLS]);

/**
 * @brief Find the richest customer's wealth from a 2D array of accounts
 * @param[in] NUMROWS    Number of customers (rows)
 * @param[in] NUMCOLS    Number of accounts per customer (columns)
 * @param[in] accounts   2D array representing the wealth of each customer in each account
 * @return The maximum wealth among all customers
 */
int richestCustomerWealth(int NUMROWS, int NUMCOLS, int accounts[][NUMCOLS]) {
    int wealth[NUMROWS];
    int richestIndex = 0;
    for (int i = 0; i < NUMROWS; i++){
        wealth[i] = 0; // RESET GARBAGE VALUES
        for (int j = 0; j < NUMCOLS; j++){
            wealth[i] += accounts[i][j];
        }
    }
    for (int i = 0; i < NUMROWS; i++){
        if (wealth[i+1] > wealth[i] && wealth[i+1] > wealth[richestIndex] && i+1 < NUMROWS){
            richestIndex = i+1;
        }
    }
    return(wealth[richestIndex]);
}