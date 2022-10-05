#ifndef CONNECT4_HEADER_H
#define CONNECT4_HEADER_H

#define ROWS 6
#define COLS 7
#include <stdbool.h>

int display_board ( int board [COLS][ROWS] ) {
printf("---------------\n");
  for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("|%d",board[i][j]);
        }
        printf("|\n");
}
printf("---------------\n");
return 0;
}
int setup_board ( int board[COLS][ROWS] ) {
  for(int i=0;i<ROWS;i++)
     {
         for(int j=0;j<COLS;j++)
         {
             board[i][j]=0;
         }
     }
     return board;
}
// Returns TRUE if the specified column in the board is completely full
// FALSE otherwise
// col should be between 1 and COLS
int column_full ( int board[COLS][ROWS], int col ) {
for( int j = 1 ; j < COLS ; j++){
    if(j== col){
        for(int i = 0 ; i < ROWS ; i ++){
            if(board[col][i]==0) return 0 ; // 0 means its false ( teh board is not completely full)
            
        }return 1 ; // 1 means its true the board is completely full
    }
} 
}
// hone alulna eno badun boolean true or false fa hone 3mletla copy w hatet true w false
bool column_full2 ( int board[COLS][ROWS], int col ) {
for( int j = 1 ; j < COLS ; j++){
    if(j== col){
        for(int i = 0 ; i < ROWS ; i ++){
            if(board[col][i]==0) return false ; // 0 means its false ( teh board is not completely full)
            
        }return true ; // 1 means its true the board is completely full
    }
} 
}

// prompts the user to enter a move, and checks that it is valid
// for the supplied board and board size
// Returns the column that the user has entered, once it is valid (1-COLS)
int get_move ( int board[COLS][ROWS] ) {
int n;
printf("enter a move\n");
scanf("%c",&n); 
if(n > 0 && n < COLS){ // move valid
    if( column_full(board[COLS][ROWS] , n) == 0) { // the col is not full
    return n ;
    }
    else return -1 ; // move invalid
} 
}

// adds a token of the given value (1 or 2) to the board at the
// given column (col between 1 and COLS inclusive)
// Returns 0 if successful, -1 otherwise
int add_move ( int b[COLS][ROWS], int col, int colour ) {
    for(int j=1;j<=COLS;j++){
        if( j == col ) {
            for(int i = ROWS ; i > 0 ; i-- ) {
                if( b[i][j] == 0 ){
                    b[i][j] = colour;
                    return 0;
                }
                if (i == 0) return -1;
            }
        }
}
}

// determines if the board is completely full or not
int board_full ( int board[COLS][ROWS] ) {
    for(int i = 0 ; i < ROWS ; i ++){
        for(int j = 0 ; j < COLS ; j ++){
            if (board[i][j] == 0)  return 1; // if 1 that means the board is not full yet
        }
    }
}

// determines who (if anybody) has won.  Returns the player id of the
// winner, otherwise 0
int winner ( int[COLS][ROWS] ) ;

#endif //CONNECT4_HEADER_H
