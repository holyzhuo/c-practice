#include <stdio.h>
#include<stdlib.h>

#define CLENGTH 4

int chessboard[CLENGTH][CLENGTH];
int randInt [2] = {2, 4};

void printChessBoard() {
	for(int i = 0; i < CLENGTH; ++i){
		printf("%d line:", i);
		for (int j = 0; j < CLENGTH; ++j)
		{
			printf("%d ", chessboard[i][j]);
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

bool operate() {
	int row;
	int line;
	int direction;
	int movedValue;
	int afterRow;
	int afterLine;

	printf("Please begin your row:\n");
    scanf("%d",&row);

    if (row == -1) {
    	return false;
    }

	printf("Please begin your line:\n");
    scanf("%d",&line);

	printf("Please select direction(1,2,3,4 => up，down, left, right):\n");
    scanf("%d",&direction);	

	 switch (direction){
	        case 1:
	        	afterLine = line;
	        	afterRow = row-1;
	        	break;
	        case 2:
	        	afterLine = line;
	        	afterRow = row+1;
	        	break;
	        case 3:
	        	afterLine = line-1;
	        	afterRow = row;
	        	break;
	        case 4:
	        	afterLine = line+1;
	        	afterRow = row;
	        	break;
	        default:printf("error\n");
    }

    if (afterRow < 0 or afterRow > CLENGTH or afterLine < 0 or afterLine > CLENGTH)
    {
		printf("cross the border");
		return false;
    }

	chessboard[afterRow][afterLine] = chessboard[row][line] + chessboard[afterRow][afterLine];
	chessboard[row][line] = 0;

	if ((chessboard[afterRow][afterLine] & chessboard[afterRow][afterLine] - 1) != 0)
		{
			printf("can't move");
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

