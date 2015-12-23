/*
Hai Tu
Sudoku.c
*/

#include <stdlib.h>
#include <stdio.h>

#define SIZE 9

int horzDupe (int num, int *lastnine, int lap);
int colDupeCheck (int board[SIZE][SIZE], int *lastnine, int lap);
void zeroLastNine (int *lastnine);

int main(void) 
{
	int i, j, n, l, userNum, isDupe, lap;
	char row;
	char line[SIZE];
	int board[SIZE][SIZE];
	int lastnine[SIZE];
	
	scanf("%d", &n);
	
	while (n != 0)
	{
		lap = 0;
		isDupe = 0;
		
		//Nested loop to create rows & col for 2d array representing game board
		for (i = 0; i<9; i++)
		{
			
            //Set array to all zeros
			zeroLastNine(lastnine);
			for (j = 0; j < 9; j++)
			{
				scanf("%d", &userNum);
				
				//Call checkDupe to check if userNum is a duplicate in a horizontal row
				isDupe = checkDupe(userNum, lastnine, lap);
				
				//Add userNum to lastnine set and board
				lastnine[j] = userNum;
				board[i][j] = userNum;
			}
		}
		
		//If there isn't a dupe num in any horizontal rows, check duplicates in cols with colDupeCheck function
		if (isDupe == 0)
		{
			lap++; //lap >= 1, signifies there were no duplicates in rows
			isDupe = colDupeCheck(board, lastnine, lap);
		}
		
		//Print out if puzzle is valid(YES) or invalid(NO)
		if (isDupe == 0) 
			printf("YES\n");
		else
			printf("NO\n");
			
		n--;
	}
	
	return 0;
}

//Returns int representing if there's a duplicate by comparing num against lastnine array 
int checkDupe (int num, int *lastnine, int lap) 
{
	int i, tracker = 0;
	
	for (i = 0; i<9; i++)
	   if (lastnine[i] == num)
			tracker++;
			
	if ( (tracker == 1) && (lap == 0) )//Return if there's a duplicate on our rows
		return 1;
	else if (tracker >= 2)//Return if there's a duplicate on our columns
		return 2;
	else
		return 0;//Return if there's no duplicate
}

//Returns int representing if there's a duplicate in each col of the board
int colDupeCheck (int board[SIZE][SIZE], int *lastnine, int lap)
{
	int i, j, x, temp, isDupe = 0;
	
	//Nested loop to create column array and check if there's a duplicate in it
	for (i = 0; i<9; i++)
	{
		zeroLastNine(lastnine);
		
		for (j=0; j<9; j++)
			lastnine[j] = board[j][i];
			
		//duplicate check and returns int representing if there's a duplicate
		for (x=0; x < 9; x++)
			{
			temp = board[x][i];
			isDupe = checkDupe(temp, lastnine, lap);
			if (isDupe == 2)
				return 1;
			}
	}
	
	return 0;
}

//Zero out lastnine array
void zeroLastNine (int *lastnine)
{
	int i;
	
	for (i = 0; i < 9; i++)
		lastnine[i] = 0;
}
