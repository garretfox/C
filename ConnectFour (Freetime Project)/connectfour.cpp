
#include "iostream"
using namespace std;

bool four_connected(char game_arr[][7], char player_char);
void put_piece(char game_arr[][7], char player_char);
void display_board(char game_arr[][7]);
char player_one_char = 'R'; //for red pieces
char player_two_char = 'B'; //for black pieces
int player_one_score = 0;
int player_two_score = 0;
bool game_start = 1;

char game_array[6][7] = //instantiate connect4array
{ 
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O',
	'O','O','O','O','O','O','O'
};

void main(){      


		cout << "start game?" << endl;
		cin >> game_start;
		while(game_start){  // game loop

			display_board(game_array);
			put_piece(game_array, player_one_char);
			four_connected(game_array,player_one_char);
			put_piece(game_array, player_two_char);
			four_connected(game_array, player_two_char);
		}
	
}


void put_piece(char game_arr[][7], char player_char)  //player puts a piece into a column
{ 
	int picked_column;
	cout << "pick a column ()" << endl;
	cin >> picked_column;
	for (int i = 5; i >= 0; i--)					  //check if column is unoccupied 
	{
		if (game_arr[i][picked_column] == 'O')
		{
			game_arr[i][picked_column] = player_char; //place player piece into array
			break;
		}
	}
}

void display_board(char game_arr[][7])
{
	for (int i = 0; i < 6; i++) {
		cout << endl;
		for (int j = 0; j < 7; j++)
			cout << game_arr[i][j] << ' ';
	}
}


bool four_connected(char game_arr[][7], char player_char)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (game_arr[0 + i][0 + j] == player_char
				&& game_arr[1 + i][1 + j] == player_char
				&& game_arr[2 + i][2 + j] == player_char
				&& game_arr[3 + i][3 + j] == player_char)
			{
				cout << player_char << " Won!" << endl;
				return true;
			}
			else if (game_arr[0 + i][6 - j] == player_char
				&& game_arr[1 + i][5 - j] == player_char
				&& game_arr[2 + i][4 - j] == player_char
				&& game_arr[3 + i][3 - j] == player_char)
			{
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
	}



	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (   game_arr[0 + i][0 + j] == player_char
				&& game_arr[1 + i][0 + j] == player_char
				&& game_arr[2 + i][0 + j] == player_char
				&& game_arr[3 + i][0 + j] == player_char)
			{
				cout << player_char << " Won!" << endl;
				return true;
			}
			else;
		}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (game_arr[0 + i][1 + j] == player_char
						&& game_arr[0 + i][2 + j] == player_char
						&& game_arr[0 + i][3 + j] == player_char
						&& game_arr[0 + i][4 + j] == player_char)
					{
						cout << player_char << " Won!" << endl;
						return true;
					}
					else;
				}
			}	
	}
	return false;
}
	   
	   
	 
	
