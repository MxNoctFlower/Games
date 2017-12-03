//Completed solely and entirely by Malik Schkoor and Nigel Jacobs.
//Game is not complete. Glitches with moving pieces and keeping score.
//If you have any suggestions, please contribute.

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

//Function Prototypes
void player1(string [][8], char[], char[], int&);
void player2(string [][8], char[], char[]);
void rSelect(string [][8]);
void init_Rboard(string [][8]);
bool is_Rwin(string [][8], int&);
char winner(int&);

int main()
{
	bool did_win;
	char again, toMove[10], moveTo[10];;
	int selection, theWinner, f = 0, n = 0;
	string rBoard[8][8], lBoard[10][10];
	
	cout << "Welcome to Checkers! To start, you'll need two players.\n" << endl;
	system("PAUSE");
	while(again != 'N')
	{
		rSelect(rBoard);
		while(did_win != true)
		{
			if(did_win == false)
			{
				init_Rboard(rBoard);
				player1(rBoard, toMove, moveTo, f);
			}
			did_win = is_Rwin(rBoard, theWinner);
			if(did_win == false)
			{
				init_Rboard(rBoard);
				player2(rBoard, toMove, moveTo);
			}
			did_win = is_Rwin(rBoard, theWinner);
		}
		again = winner(theWinner);
		did_win = false;
	}
	cout << "Goodbye!" << endl;
	return 0;
}

void player1(string rBoard[][8], char toMove[], char moveTo[], int& f)
{
	char a, b;
	int u = 0, v = 0, x = 0, y = 0, test = 0;
	
	//The toMove array is used as a medium to convert the board positions into the rBoard array positions
	cout << "\nPlayer One's Turn\n\n";
	while(test == 0)
	{
	cout << "Select which piece you would like to move, letter first followed by the number: ";
	cin.getline(toMove, 11);
	toMove[0] = toupper(toMove[0]);
	x = 8 - (toMove[1] - '0');
	
	//Ensures the User doesn't input anything other than A-H and 1-8
	while(toMove[0] != 'A' && toMove[0] != 'B' && toMove[0] != 'C' && toMove[0] != 'D' && toMove[0] != 'E' && toMove[0] != 'F' && toMove[0] != 'G' && toMove[0] != 'H' || x < 0 || x > 7)
	{
		cout << "This position is not on the board, please select another. Again, the letter comes first followed by the number: ";
		cin.getline(toMove, 11);
		toMove[0] = toupper(toMove[0]);
		x = 8 - (toMove[1] - '0');
	}
	a = toMove[0];
	switch(a){
		case 'A':
			y = 0;
			break;
		case 'B':
			y = 1;
			break;
		case 'C':
			y = 2;
			break;
		case 'D':
			y = 3;
			break;
		case 'E':
			y = 4;
			break;
		case 'F':
			y = 5;
			break;
		case 'G':
			y = 6;
			break;
		case 'H':
			y = 7;
			break;
	}
	while(rBoard[x][y] != " X " && rBoard[x][y] != "(X)")
	{
		cout << "It appears you don't have a piece in this location...\n\nPlease select a piece to move: ";
		cin.getline(toMove, 11);
		toMove[0] = toupper(toMove[0]);
		a = toMove[0];
		switch(a){
			case 'A':
				y = 0;
				break;
			case 'B':
				y = 1;
				break;
			case 'C':
				y = 2;
				break;
			case 'D':
				y = 3;
				break;
			case 'E':
				y = 4;
				break;
			case 'F':
				y = 5;
				break;
			case 'G':
				y = 6;
				break;
			case 'H':
				y = 7;
				break;
		}
		x = 8 - (toMove[1] - '0');
	}
	
	cout << "Enter where you would like that piece to move: ";
	cin.getline(moveTo, 11);
	moveTo[0] = toupper(moveTo[0]);
	u = 8 - (moveTo[1] - '0');
	while(moveTo[0] != 'A' && moveTo[0] != 'B' && moveTo[0] != 'C' && moveTo[0] != 'D' && moveTo[0] != 'E' && moveTo[0] != 'F' && moveTo[0] != 'G' && moveTo[0] != 'H' || u < 0 || u > 7)
	{
		cout << "This position is not on the board, please select another. Again, the letter comes first followed by the number: ";
		cin.getline(moveTo, 11);
		moveTo[0] = toupper(moveTo[0]);
		u = 8 - (moveTo[1] - '0');
	}
	b = moveTo[0];
	switch(b){
		case 'A':
			v = 0;
			break;
		case 'B':
			v = 1;
			break;
		case 'C':
			v = 2;
			break;
		case 'D':
			v = 3;
			break;
		case 'E':
			v = 4;
			break;
		case 'F':
			v = 5;
			break;
		case 'G':
			v = 6;
			break;
		case 'H':
			v = 7;
			break;
	}
	if(rBoard[x][y] != "(X)" && (u-x) == 2 && (v-y) == 2 && rBoard[x+1][y+1] == "   " || rBoard[x+1][y+1] == " X " || rBoard[x+1][y+1] == "(X)")
			cout << "This move is not allowed. ";
	else if(rBoard[x][y] != "(X)" && (u-x) == 2 && (v-y) == -2 && rBoard[x+1][y-1] == "   " || rBoard[x+1][y-1] == " X " || rBoard[x+1][y-1] == "(X)")
		cout << "This move is not allowed.. ";
	else if(rBoard[x][y] == "(X)" && (u-x) == -2 && (v-y) == 2 && rBoard[x-1][y+1] == "   " || rBoard[x-1][y+1] == " X " || rBoard[x-1][y+1] == "(X)")
		cout << "This move is not allowed... ";
	else if(rBoard[x][y] == "(X)" && (u-x) == -2 && (v-y) == -2 && rBoard[x-1][y-1] == "   " || rBoard[x-1][y-1] == " X " || rBoard[x-1][y-1] == "(X)")
		cout << "This move is not allowed.... ";
	else if((u+v) % 2 == 0 || u == x || v == y || abs(u-x) > 2 || abs(v-y) > 2)
		cout << "This move is not allowed. ";
	else if(rBoard[x][y] == rBoard[u][v])
		cout << "You must actually move your piece. ";
	else if(rBoard[u][v] == " O " || rBoard[u][v] == "(O)" || rBoard[u][v] == " X " || rBoard[u][v] == "(X)")
		cout << "This spot is occupied. ";
	else if(rBoard[x][y] == " X " && u < x)
		cout << "Your piece must be kinged to move backwards. ";
	else
	{
		if(u == 7 || rBoard[x][y] == "(X)")
			rBoard[u][v] = "(X)";
		else
			rBoard[u][v] = " X ";
		
		rBoard[x][y] = "   ";
		
		//Down Right
		if(u > x && v > y && rBoard[u-1][v-1] == " O " || rBoard[u-1][v-1] == "(O)")
			rBoard[u-1][v-1] = "   ";
		//Down Left
		else if(u > x && v < y && rBoard[u-1][v+1] == " O " || rBoard[u-1][v+1] == "(O)")
			rBoard[u-1][v+1] = "   ";
		//Up Right
		else if(u < x && v > y && rBoard[u+1][v-1] == " O " || rBoard[u+1][v-1] == "(O)")
			rBoard[u+1][v-1] = "   ";
		//Up Left
		else if(u < x && v < y && rBoard[u+1][v+1] == " O " || rBoard[u+1][v+1] == "(O)")
			rBoard[u+1][v+1] = "   ";
		test++;
	}
	}
}

void player2(string rBoard[][8], char toMove[], char moveTo[])
{
	char a, b;
	int u, v, x, y, test = 0;
	
	//The toMove array is used as a medium to convert the board positions into the rBoard array positions
	cout << "\nPlayer Two's Turn\n\n";
	while(test == 0)
	{
	cout << "Select which piece you would like to move, letter first followed by the number: ";
	cin.getline(toMove, 11);
	toMove[0] = toupper(toMove[0]);
	x = 8 - (toMove[1] - '0');
	
	//Ensures the User doesn't input anything other than A-H and 1-8
	while(toMove[0] != 'A' && toMove[0] != 'B' && toMove[0] != 'C' && toMove[0] != 'D' && toMove[0] != 'E' && toMove[0] != 'F' && toMove[0] != 'G' && toMove[0] != 'H' || x < 1 || x > 8)
	{
		cout << "This position is not on the board, please select another. Again, the letter comes first followed by the number: ";
		cin.getline(toMove, 11);
		toMove[0] = toupper(toMove[0]);
		x = 8 - (toMove[1] - '0');
	}
	a = toMove[0];
	switch(a){
		case 'A':
			y = 0;
			break;
		case 'B':
			y = 1;
			break;
		case 'C':
			y = 2;
			break;
		case 'D':
			y = 3;
			break;
		case 'E':
			y = 4;
			break;
		case 'F':
			y = 5;
			break;
		case 'G':
			y = 6;
			break;
		case 'H':
			y = 7;
			break;
	}
	while(rBoard[x][y] != " O " && rBoard[x][y] != "(O)")
	{
		cout << "It appears you don't have a piece in this location...\n\nPlease select a piece to move: ";
		cin.getline(toMove, 11);
		toMove[0] = toupper(toMove[0]);
		a = toMove[0];
		switch(a){
			case 'A':
				y = 0;
				break;
			case 'B':
				y = 1;
				break;
			case 'C':
				y = 2;
				break;
			case 'D':
				y = 3;
				break;
			case 'E':
				y = 4;
				break;
			case 'F':
				y = 5;
				break;
			case 'G':
				y = 6;
				break;
			case 'H':
				y = 7;
				break;
		}
		x = 8 - (toMove[1] - '0');
	}
	
	cout << "Enter where you would like that piece to move: ";
	cin.getline(moveTo, 11);
	moveTo[0] = toupper(moveTo[0]);
	u = 8 - (moveTo[1] - '0');
	while(moveTo[0] != 'A' && moveTo[0] != 'B' && moveTo[0] != 'C' && moveTo[0] != 'D' && moveTo[0] != 'E' && moveTo[0] != 'F' && moveTo[0] != 'G' && moveTo[0] != 'H' || u < 1 || u > 8)
	{
		cout << "This position is not on the board, please select another. Again, the letter comes first followed by the number: ";
		cin.getline(moveTo, 11);
		moveTo[0] = toupper(moveTo[0]);
		u = 8 - (moveTo[1] - '0');
	}
	b = moveTo[0];
	switch(b){
		case 'A':
			v = 0;
			break;
		case 'B':
			v = 1;
			break;
		case 'C':
			v = 2;
			break;
		case 'D':
			v = 3;
			break;
		case 'E':
			v = 4;
			break;
		case 'F':
			v = 5;
			break;
		case 'G':
			v = 6;
			break;
		case 'H':
			v = 7;
			break;
	}
	if((u+v) % 2 == 0 || u == x || v == y || abs(u-x) > 2 || abs(v-y) > 2)
		cout << "Your piece must move diagnoally, try to make your move again. ";
	else if(rBoard[x][y] == rBoard[u][v])
		cout << "You must actually move your piece. ";
	else if(rBoard[u][v] == " O " || rBoard[u][v] == "(O)" || rBoard[u][v] == " X " || rBoard[u][v] == "(X)")
		cout << "This spot is occupied. ";
	else if(rBoard[x][y] == " O " && u > x)
		cout << "Your piece must be kinged to move backwards. ";
	else
	{
		
		if(u == 0 || rBoard[x][y] == "(O)")
			rBoard[u][v] = "(O)";
		else
			rBoard[u][v] = " O ";
		rBoard[x][y] = "   ";
		//Down Right
		if(u > x && v > y && rBoard[u-1][v-1] == " X " || rBoard[u-1][v-1] == "(X)")
			rBoard[u-1][v-1] = "   ";
		//Down Left
		else if(u > x && v < y && rBoard[u-1][v+1] == " X " || rBoard[u-1][v+1] == "(X)")
			rBoard[u-1][v+1] = "   ";
		//Up Right
		else if(u < x && v > y && rBoard[u+1][v-1] == " X " || rBoard[u+1][v-1] == "(X)")
			rBoard[u+1][v-1] = "   ";
		//Up Left
		else if(u < x && v < y && rBoard[u+1][v+1] == " X " || rBoard[u+1][v+1] == "(X)")
			rBoard[u+1][v+1] = "   ";
		test++;
	}
	}
}

void rSelect(string rBoard[][8])
{
	rBoard[0][0] = "   ";
	rBoard[0][1] = " X ";
	rBoard[0][2] = "   ";
	rBoard[0][3] = " X ";
	rBoard[0][4] = "   ";
	rBoard[0][5] = " X ";
	rBoard[0][6] = "   ";
	rBoard[0][7] = " X ";
	rBoard[1][0] = " X ";
	rBoard[1][1] = "   ";
	rBoard[1][2] = " X ";
	rBoard[1][3] = "   ";
	rBoard[1][4] = " X ";
	rBoard[1][5] = "   ";
	rBoard[1][6] = " X ";
	rBoard[1][7] = "   ";
	rBoard[2][0] = "   ";
	rBoard[2][1] = " X ";
	rBoard[2][2] = "   ";
	rBoard[2][3] = " X ";
	rBoard[2][4] = "   ";
	rBoard[2][5] = " X ";
	rBoard[2][6] = "   ";
	rBoard[2][7] = " X ";
	rBoard[3][0] = "   ";
	rBoard[3][1] = "   ";
	rBoard[3][2] = "   ";
	rBoard[3][3] = "   ";
	rBoard[3][4] = "   ";
	rBoard[3][5] = "   ";
	rBoard[3][6] = "   ";
	rBoard[3][7] = "   ";
	rBoard[4][0] = "   ";
	rBoard[4][1] = "   ";
	rBoard[4][2] = "   ";
	rBoard[4][3] = "   ";
	rBoard[4][4] = "   ";
	rBoard[4][5] = "   ";
	rBoard[4][6] = "   ";
	rBoard[4][7] = "   ";
	rBoard[5][0] = " O ";
	rBoard[5][1] = "   ";
	rBoard[5][2] = " O ";
	rBoard[5][3] = "   ";
	rBoard[5][4] = " O ";
	rBoard[5][5] = "   ";
	rBoard[5][6] = " O ";
	rBoard[5][7] = "   ";
	rBoard[6][0] = "   ";
	rBoard[6][1] = " O ";
	rBoard[6][2] = "   ";
	rBoard[6][3] = " O ";
	rBoard[6][4] = "   ";
	rBoard[6][5] = " O ";
	rBoard[6][6] = "   ";
	rBoard[6][7] = " O ";
	rBoard[7][0] = " O ";
	rBoard[7][1] = "   ";
	rBoard[7][2] = " O ";
	rBoard[7][3] = "   ";
	rBoard[7][4] = " O ";
	rBoard[7][5] = "   ";
	rBoard[7][6] = " O ";
	rBoard[7][7] = "   ";
}

void init_Rboard(string rBoard[][8])
{
	cout << "   ---------------------------------\n 8 |" << rBoard[0][0] << "|" << rBoard[0][1] << "|" << rBoard[0][2] << "|" << rBoard[0][3] << "|" << rBoard[0][4] << "|" << rBoard[0][5] << "|" << rBoard[0][6] << "|" << rBoard[0][7] << "|" << endl;
	cout << "   ---------------------------------\n 7 |" << rBoard[1][0] << "|" << rBoard[1][1] << "|" << rBoard[1][2] << "|" << rBoard[1][3] << "|" << rBoard[1][4] << "|" << rBoard[1][5] << "|" << rBoard[1][6] << "|" << rBoard[1][7] << "|" << endl;
	cout << "   ---------------------------------\n 6 |" << rBoard[2][0] << "|" << rBoard[2][1] << "|" << rBoard[2][2] << "|" << rBoard[2][3] << "|" << rBoard[2][4] << "|" << rBoard[2][5] << "|" << rBoard[2][6] << "|" << rBoard[2][7] << "|" << endl;
	cout << "   ---------------------------------\n 5 |" << rBoard[3][0] << "|" << rBoard[3][1] << "|" << rBoard[3][2] << "|" << rBoard[3][3] << "|" << rBoard[3][4] << "|" << rBoard[3][5] << "|" << rBoard[3][6] << "|" << rBoard[3][7] << "|" << endl;
	cout << "   ---------------------------------\n 4 |" << rBoard[4][0] << "|" << rBoard[4][1] << "|" << rBoard[4][2] << "|" << rBoard[4][3] << "|" << rBoard[4][4] << "|" << rBoard[4][5] << "|" << rBoard[4][6] << "|" << rBoard[4][7] << "|" << endl;
	cout << "   ---------------------------------\n 3 |" << rBoard[5][0] << "|" << rBoard[5][1] << "|" << rBoard[5][2] << "|" << rBoard[5][3] << "|" << rBoard[5][4] << "|" << rBoard[5][5] << "|" << rBoard[5][6] << "|" << rBoard[5][7] << "|" << endl;
	cout << "   ---------------------------------\n 2 |" << rBoard[6][0] << "|" << rBoard[6][1] << "|" << rBoard[6][2] << "|" << rBoard[6][3] << "|" << rBoard[6][4] << "|" << rBoard[6][5] << "|" << rBoard[6][6] << "|" << rBoard[6][7] << "|" << endl;
	cout << "   ---------------------------------\n 1 |" << rBoard[7][0] << "|" << rBoard[7][1] << "|" << rBoard[7][2] << "|" << rBoard[7][3] << "|" << rBoard[7][4] << "|" << rBoard[7][5] << "|" << rBoard[7][6] << "|" << rBoard[7][7] << "|" << endl;
	cout << "   ---------------------------------\n     a   b   c   d   e   f   g   h" << endl;
}

bool is_Rwin(string rBoard[][8], int& theWinner)
{
	int row, col, P1, P2;
	
	for(row = 0; row < 8; row++)
	{
		for(col = 0; col < 8; col++)
		{
			if(rBoard[row][col] == " X " || rBoard[row][col] == "(X)")
				P1++;
			if(rBoard[row][col] == " X " || rBoard[row][col] == "(X)")
				P2++;
		}
	}
	if(P1 == 0)
	{
		theWinner = 2;
		return true;
	}
	else if(P2 == 0)
	{
		theWinner = 1;
		return true;
	}
	else 
		return false;
}

char winner(int& theWinner)
{
	char again, a;
	
	if(theWinner = 1)
		cout << "Player 1 wins!" << '\n' << '\n' << "Play again?" << endl;
	else if(theWinner = 2)
		cout << "Player 2 wins!" << '\n' << '\n' << "Play again?" << endl;
	cout << "Enter Y if you would like to play again, if not enter N: ";
	cin >> again;
	a = toupper(again);
	while(a != 'Y' && a != 'N')
	{
		cout << "Invalid input, please enter Y or N: ";
		cin >> again;
		a = toupper(again);
	}
	return a;
