
	   
	 
	
/* 
Garret Fox March 2018 - Connect Four
*/

#include "iostream"
using namespace std;

//functions prototypes
bool four_connected(char game_arr[][7], char player_char);
void put_piece(char game_arr[][7], char player_char);
void display_board(char game_arr[][7]);
//variables
char player_one_char = 'R'; //for red pieces
char player_two_char = 'B'; //for black pieces
int player_one_score = 0;
int player_two_score = 0;
bool game_start      = 1;
bool player_won      = 0;
bool on		         = 1;
char player_answer;

char game_array[6][7] = //instantiate connect4array
{
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O'
};

void main() {
	while (on)
	{
		if (player_won == 1) // restart game after player has won
		{
			cout << "Play Again? (y/n)" << endl;
			cin >> player_answer;
			if (player_answer == 'y')
				game_start = 1;
			else if (player_answer = 'n')
				game_start = 0;
			else
				cout << "invalid answer\n";
		}
		while (game_start != 0)// game loop
		{

			display_board(game_array);
			cout << "Player 1 Turn (Pick a column 1-7)" << endl;
			put_piece(game_array, player_one_char);
			display_board(game_array);
			cout << "Player 2 Turn (Pick a column 1-7)" << endl;
			put_piece(game_array, player_two_char);
		
		}
	}
}


void put_piece(char game_arr[][7], char player_char)  //player puts a piece into a column
{
	int picked_column;
	cin >> picked_column;
	picked_column - 1;
	for (int i = 5; i >= 0; i--)					  //check if column is unoccupied 
	{
		if (game_arr[i][picked_column] == 'O')
		{
			game_arr[i][picked_column] = player_char; //place player piece into array
			break;
		}
	}
	four_connected(game_arr, player_char);            //Check if player has won after turn

}

void display_board(char game_arr[][7])
{
	for (int i = 0; i < 6; i++) {
		cout << endl;
		for (int j = 0; j < 7; j++)
			cout << game_arr[i][j] << ' ';
	}
	cout << endl;
}


bool four_connected(char game_arr[][7], char player_char)
{
	for (int j = 0; j < 4; j++) // check "\" and "/" diagonal connections across board
	{
		for (int i = 0; i < 3; i++)
		{
			if (game_arr[0 + i][0 + j] == player_char
				&& game_arr[1 + i][1 + j] == player_char
				&& game_arr[2 + i][2 + j] == player_char
				&& game_arr[3 + i][3 + j] == player_char)
			{
				game_start = 0;
				cout << player_char << " Won!" << endl;
				return true;
			}
			else if (game_arr[0 + i][6 - j] == player_char
				&& game_arr[1 + i][5 - j] == player_char
				&& game_arr[2 + i][4 - j] == player_char
				&& game_arr[3 + i][3 - j] == player_char)
			{
				game_start = 0;
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
	}



	for (int j = 0; j < 6; j++)  //check verticle "|" connections across board
	{
		for (int i = 0; i < 2; i++)
		{
			if (game_arr[0 + i][0 + j] == player_char
				&& game_arr[1 + i][0 + j] == player_char
				&& game_arr[2 + i][0 + j] == player_char
				&& game_arr[3 + i][0 + j] == player_char)
			{
				game_start = 0;
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
	}
	for (int i = 0; i < 6; i++)  //check horizontal "----" connections across board
	{
		for (int j = 0; j < 4; j++)
		{
			if (game_arr[0 + i][1 + j] == player_char
				&& game_arr[0 + i][2 + j] == player_char
				&& game_arr[0 + i][3 + j] == player_char
				&& game_arr[0 + i][4 + j] == player_char)
			{
				game_start = 0;
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
	}
	return false;
}
