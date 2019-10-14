#include <stdio.h>
#include<stdlib.h>

#define CLENGTH 4

int chessboard[CLENGTH][CLENGTH];
int randInt [2] = {2, 4};

bool canMove = false;

void printChessBoard() {
	printf("  ");
	for (int i = 0; i < CLENGTH; ++i)
	{
		printf("%d    ", i);
	}
	printf("\n");

	for(int i = 0; i < CLENGTH; ++i){
		printf("%d:", i);
		for (int j = 0; j < CLENGTH; ++j)
		{
			printf("%d    ", chessboard[i][j]);
		}

		printf("\n");
	}
}

void initChessBoard() {
	for(int i = 0; i < 2; ++i){
		for (int j = 0; j < 4; ++j)
		{
			chessboard[i][j] = randInt[rand() % 2];
		}
	}
}

void randGenerate() {
	bool haveEmpty = false;
	for(int i = 0; i < CLENGTH; ++i){
		for (int j = 0; j < CLENGTH; ++j)
		{
			if (chessboard[i][j] == 0)
			{
				haveEmpty = true;
			}		
		}
	}

	if (!haveEmpty)
	{
		return;
	}

	while(1)
	{
		int l = rand() % 4;
		int r = rand() % 4;
		if (chessboard[r][l] == 0){
		  chessboard[r][l]  = randInt[rand() % 2];
		  return;
		}
	}
}

void moveUp(int board[4][4]) {
	for(int j = 0; j < 4; ++j){
		for (int i = 3; i >= 0; --i)
		{
			if (i != 0)
			{
				if (board[i-1][j] == 0 && board[i][j] != 0) {
					board[i-1][j]	= board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i-1][j] == board[i][j]) {
					board[i-1][j] = board[i-1][j] + board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i][j] == 0) {
					canMove = true;	
				}
			}
		}
	}
}

void moveDown(int board[4][4]) {
	for(int j = 0; j < 4; ++j){
		for (int i = 0; i < 4; ++i)
		{
			if (i != 3)
			{
				if (board[i+1][j] == 0 && board[i][j] != 0) {
					board[i+1][j]	= board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i+1][j] == board[i][j]) {
					board[i+1][j] = board[i+1][j] + board[i][j];
					board[i][j] = 0;
					canMove = true;	
				} else if (board[i][j] == 0) {
					canMove = true;	
				}
			}
		}
	}
}

void moveLeft(int board[4][4]) {
	for (int i = 0; i < 4; ++i){
		for(int j = 3; j >= 0; --j){
			if (j != 0)
			{
				if (board[i][j-1] == 0 && board[i][j] != 0) {
					board[i][j-1]	= board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i][j-1] == board[i][j]) {
					board[i][j-1] = board[i][j-1] + board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i][j] == 0) {
					canMove = true;	
				}
			}
		}
	}
}

void moveRight(int board[4][4]) {
	for (int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			if (j != 3)
			{
				if (board[i][j+1] == 0 && board[i][j] != 0) {
					board[i][j+1]	= board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i][j+1] == board[i][j]) {
					board[i][j+1] = board[i][j+1] + board[i][j];
					board[i][j] = 0;
					canMove = true;
				} else if (board[i][j] == 0) {
					canMove = true;	
				}
			}
		}
	}
}


bool gameOver() {
    int copy_board[4][4],i,j;
    /*为了避免直接把board[][]传进move函数判断的时候改变board，所以把board复制给
    另一个数组,然后判断，这样就不会改变board数组了
    */
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            copy_board[i][j]=chessboard[i][j];
        }
    }

	canMove = false;

	moveDown(copy_board);
	moveUp(copy_board);
	moveLeft(copy_board);
	moveRight(copy_board);

    if (!canMove)
	{
        return true;
	}

	return false;
}

bool checkWin() {
	for(int i = 0; i < CLENGTH; ++i){
		for (int j = 0; j < CLENGTH; ++j)
		{
			if (chessboard[i][j] == 2048)
			{
				return true;
			}
		}
	}
	return false;
}

bool operate() {
	int direction;

	printf("Please select direction(1,2,3,4 => up，down, left, right):\n");
    scanf("%d",&direction);	

	 switch (direction){
	        case 1:
	        	moveUp(chessboard);
	        	break;
	        case 2:
	        	moveDown(chessboard);				
	        	break;
	        case 3:
	        	moveLeft(chessboard);	
	        	break;
	        case 4:
	        	moveRight(chessboard);
	        	break;
	        default:printf("error\n");
    }

    if (checkWin()) {
    	printf("you win");
    	return false;
    }

    if (gameOver())
    {
    	printf("you lose");
    	return false;
    }

	randGenerate();	

    return true;
}

int main() {
	initChessBoard();
	printChessBoard();

	while(operate()){
		printChessBoard();
	};
}

