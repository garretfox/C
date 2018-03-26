/*
Garret Fox March 2018 - Connect Four
*/

#include <iostream>
#include <string>
#include <stdio.h>
#include <memory>
using namespace std;
/*******functions prototypes*******/
void clear_board   (char game_arr[][7]);
//void testing_func(char game_arr[][7]);
bool four_connected(char game_arr[][7], char player_char);
void put_piece     (char game_arr[][7], char player_char);
void display_board (char game_arr[][7]);
/********variables*********/
char player_one_char = 'R';                            //for red pieces  (player one)
char player_two_char = 'B';                            //for black pieces(player two)
int player_one_score = 0;
int player_two_score = 0;
bool player_won = 0;
bool game_on = 1;
char player_answer;

char game_array[6][7];                               

void main()
{
	clear_board(game_array);								//clear board 
	while (game_on)
	{
		if (player_won == 1)								// restart game after player has won
		{
			cout << "Play Again? (y/n)" << endl;
			cin >> player_answer;
			if (player_answer == 'y')
			{
				player_won = 0;
				clear_board(game_array);
			}
			else if (player_answer = 'n')
			{
				game_on = 0;
			}
		}

		while (player_won != 1)									// game loop
		{
			display_board(game_array);
			cout << "Player 1 Turn (Pick a column 1-7)" << endl;
			put_piece(game_array, player_one_char);
			display_board(game_array);
			if (player_won)
			{ 
																//skip player two
			}
			else
			{
				cout << "Player 2 Turn (Pick a column 1-7)" << endl;
				put_piece(game_array, player_two_char);
			}

		}
	}
}


void put_piece(char game_arr[][7], char player_char)  //player puts a piece into a column
{
	int picked_column = 0;
	
	do 
	{
		cin >> picked_column;
	  if(picked_column > 7 || picked_column < 1)
       {
		cout << "invalid column, choose 1-7 please" << endl;
       }
	}while (picked_column > 7 || picked_column < 1);

	picked_column--;									//account for array indexing

	for (int i = 5; i >= 0; i--)					    //loop through column
	{
		if (game_arr[i][picked_column] == 'O')
		{
			game_arr[i][picked_column] = player_char;   //place player piece into array
			i = 0;                                        //only place 1 player_char
		}
	}
	if (four_connected(game_arr, player_char))			//Check if player has won after turn
		player_won = 1;

}

void display_board(char game_arr[][7])
{
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		for (int j = 0; j < 7; j++)
		{
			cout << game_arr[i][j] << ' ';
		}
	}
	cout << endl;
	cout << "Player One Score is: " << player_one_score << endl;
	cout << "Player Two Score is: " << player_two_score << endl;
}


bool four_connected(char game_arr[][7], char player_char)
{
	for (int j = 0; j < 4; j++)                          // check "\" and "/" diagonal connections across board
	{
		for (int i = 0; i < 3; i++)
		{
			if (game_arr[0 + i][0 + j] == player_char
				&& game_arr[1 + i][1 + j] == player_char
				&& game_arr[2 + i][2 + j] == player_char
				&& game_arr[3 + i][3 + j] == player_char)
			{
				cout << player_char << " Won!" << endl;
				if (player_char == 'R')
				{
					player_one_score++;
				}
				else
				{
					player_two_score++;
				}
				return true;
			}
			else if (game_arr[0 + i][6 - j] == player_char
				&& game_arr[1 + i][5 - j] == player_char
				&& game_arr[2 + i][4 - j] == player_char
				&& game_arr[3 + i][3 - j] == player_char)
			{

				cout << player_char << " Won!" << endl;
				if (player_char == 'R')
				{
					player_one_score++;
				}
				else
				{
					player_two_score++;
				}
				return true;
			}
			else;
		}
	}

	for (int j = 0; j < 7; j++)                        //check verticle "|" connections across board
	{
		for (int i = 0; i < 3; i++)
		{
			if (game_arr[0 + i][0 + j] == player_char
				&& game_arr[1 + i][0 + j] == player_char
				&& game_arr[2 + i][0 + j] == player_char
				&& game_arr[3 + i][0 + j] == player_char)
			{
				if (player_char == 'R')
				{
					player_one_score++;
				}
				else
				{
					player_two_score++;
				}
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
	}

	for (int i = 0; i < 6; i++)                          //check horizontal "----" connections across board
	{
		for (int j = 0; j < 4; j++)
		{
			if (game_arr[0 + i][0 + j] == player_char
				&& game_arr[0 + i][1 + j] == player_char
				&& game_arr[0 + i][2 + j] == player_char
				&& game_arr[0 + i][3 + j] == player_char)
			{
				if (player_char == 'R')
				{
					player_one_score++;
				}
				else
				{
					player_two_score++;
				}
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
	}
	return false;
}

/*void testing_func(char game_arr[][7])                    //making sure logic for verticle check works
{
char testchars[7] = { 'A','B','C','D','E','F','G'};
for (int j = 0; j < 7; j++)
{
for (int i = 0; i < 3; i++)
{
game_arr[0 + i][0 + j] = testchars[j],
game_arr[1 + i][0 + j] = testchars[j],
game_arr[2 + i][0 + j] = testchars[j],
game_arr[3 + i][0 + j] = testchars[j];
}
}
}
*/
void clear_board(char game_arr[][7])  //clears board
{
	memset(game_arr, 'O', sizeof(game_arr[0][0]) * 6 * 7);
}
