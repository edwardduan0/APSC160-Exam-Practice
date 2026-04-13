/**
 * @file template.h
 * @brief Game of Life Template
 * @author Daylen Chun
 */

void gameOfLife(int NUMROWS, int NUMCOLS, int board[][NUMCOLS]);

/**
 * @brief Update the board to the next state according to the Game of Life rules
 * @param[in] NUMROWS    Number of rows in the board
 * @param[in] NUMCOLS    Number of columns in the board
 * @param     board      The game board
 * @modifies board to its next state
 */
void gameOfLife(int NUMROWS, int NUMCOLS, int board[][NUMCOLS]) {
    int isAlive;
    int liveCount;
    int info[NUMROWS][NUMCOLS];
    for (int i = 0; i < NUMROWS; i++){
        for (int j = 0; j < NUMCOLS; j++){
            liveCount = 0;
            if (board[i][j] == 1){
                isAlive = 1;
            }
            else {
                isAlive = 0;
            }
            if (board[i][j+1] == 1 && j != NUMCOLS - 1){ //right is alive
                liveCount++;
            }
            if (board[i][j-1] == 1 && j != 0){ //left is alive
                liveCount++;
            }
            if (board[i-1][j] == 1 && i != 0){ //above is alive
                liveCount++;
            }
            if (board[i+1][j] == 1 && i != NUMROWS - 1){ //below is alive
                liveCount++;
            }
            if (board[i-1][j+1] == 1 && i != 0 && j != NUMCOLS - 1){ //Northeast is alive
                liveCount++;
            }
            if (board[i-1][j-1] == 1 && i != 0 && j != 0){ //Northwest is alive
                liveCount++;
            }
            if (board[i+1][j-1] == 1 && j != 0 && i != NUMROWS - 1){ //Southwest is alive
                liveCount++;
            }
            if (board[i+1][j+1] == 1 && i != NUMROWS - 1 && j != NUMCOLS - 1){ //Southeast is alive
                liveCount++;
            }
            if (isAlive == 1 && liveCount < 2){
                isAlive = 0;
            }
            else if (isAlive == 1 && liveCount == 2 || isAlive == 1 && liveCount == 3){
                isAlive = 1;
            }
            else if (isAlive == 1 && liveCount > 3){
                isAlive = 0;
            }
            if (isAlive == 0 && liveCount == 3){
                isAlive = 1;
            }
            if (isAlive == 1){
                info[i][j] = 1;
            }
            else if (isAlive == 0){
                info[i][j] = 0;
            }

        }
    }
    for (int i = 0; i < NUMROWS; i++){
        for (int j = 0; j < NUMCOLS; j++){
            board[i][j] = info[i][j];
        }
    }
}