
//A simple game of tic-tac-toe.
#include<iostream>
using namespace std;
void init_board(char[][4],int);
void display_board(char[][4], int);
void playerOne(char[][4], int);
void playerTwo(char[][4], int);
bool checkGame(char[][4], int, bool);
int main()
{
  const int cols = 4, rows = 4;
  char board[rows][cols];
  bool game = false;
  int player;
  
  init_board(board, rows);
  display_board(board, rows);
  while(!game)
  {
    if(!game)
    {
      player = 1;
      playerOne(board, rows);
      game = checkGame(board, rows, game);
      
    }
    if(!game)
    {
      player = 2;
      playerTwo(board, rows);
      game = checkGame(board, rows, game);
    }
  }
  cout << "Congratulations! Player " << player << " has won the game!" << endl;
  return 0;
}
void init_board(char board[][4], int rows = 4)
{
  int cols = 4;
  board[0][0] = '1';
  board[0][1] = '2';
  board[0][2] = '3';
  board[1][0] = '4';
  board[1][1] = '5';
  board[1][2] = '6';
  board[2][0] = '7';
  board[2][1] = '8';
  board[2][2] = '9';
  
  
}

void display_board(char board[][4], int rows = 4)
{
  for(int rows = 0; rows < 3; rows++)
  {
    for(int cols = 0; cols < 3; cols++)
    {
      if(cols == 2)
      {
        cout << board[rows][cols];
      }
      else
      {
        cout << board[rows][cols] << " | ";
      }
      
    }
    if(rows == 0 ||rows == 1)
    {
      cout << endl << "----------" << endl;
    }
    else
    {
      cout << endl;
    }
  }
}
void playerOne(char board[][4], int rows = 4)
{
  char temp;
  char place;
  cout << "Please enter the number where you want to put an X: ";
  cin >> place;
  if( place == '1'&& board[0][0] == '1')
  {
    temp = board[0][0];
    board[0][0] = 'X';
  }
  else if(place == '2'&& board[0][1] == '2')
  {
    temp = board[0][1];
    board[0][1] = 'X';
  }
  else if(place == '3'&& board[0][2] == '3')
  {
    temp = board[0][2];
    board[0][2] = 'X';
  }
  else if(place == '4'&& board[1][0] == '4')
  {
    temp = board[1][0];
    board[1][0] = 'X';
  }
  else if(place == '5'&& board[1][1] == '5')
  {
    temp = board[1][1];
    board[1][1] = 'X';
  }
  else if(place == '6'&& board[1][2] == '6')
  {
    temp = board[1][2];
    board[1][2] = 'X';
  }
  else if(place == '7'&& board[2][0] == '7')
  {
    temp = board[2][0];
    board[2][0] = 'X';
  }
  else if(place == '8'&& board[2][1] == '8')
  {
    temp = board[2][1];
    board[2][1] = 'X';
  }
  else if(place == '9'&& board[2][2] == '9')
  {
    temp = board[2][2];
    board[2][2] = 'X';
  }
  else
  {
    cout << "Invaild Input!" << endl;
  }
  display_board(board, rows);
}
void playerTwo(char board[][4], int rows = 4)
{
  char temp;
  char place;
  cout << "Please enter the number where you want to put an O: ";
  cin >> place;
  if( place == '1'&& board[0][0] == '1')
  {
    temp = board[0][0];
    board[0][0] = 'O';
  }
  else if(place == '2'&& board[0][1] == '2')
  {
    temp = board[0][1];
    board[0][1] = 'O';
  }
  else if(place == '3'&& board[0][2] == '3')
  {
    temp = board[0][2];
    board[0][2] = 'O';
  }
  else if(place == '4'&& board[1][0] == '4')
  {
    temp = board[1][0];
    board[1][0] = 'O';
  }
  else if(place == '5'&& board[1][1] == '5')
  {
    temp = board[1][1];
    board[1][1] = 'O';
  }
  else if(place == '6'&& board[1][2] == '6')
  {
    temp = board[1][2];
    board[1][2] = 'O';
  }
  else if(place == '7'&& board[2][0] == '7')
  {
    temp = board[2][0];
    board[2][0] = 'O';
  }
  else if(place == '8'&& board[2][1] == '8')
  {
    temp = board[2][1];
    board[2][1] = 'O';
  }
  else if(place == '9'&& board[2][2] == '9')
  {
    temp = board[2][2];
    board[2][2] = 'O';
  }
  else
  {
    cout << "Invalid Input!" << endl;
  }
  display_board(board, rows);
  
}
bool checkGame(char board[][4],int rows = 4,bool game = false)
{
  if(board[0][0]==board[0][1]&& board[0][1]==board[0][2])
  {
    game = true;
    return game;
  }
  else if(board[1][0]==board[1][1]&&board[1][1]==board[1][2])
  {
    game = true;
    return game;
  }
  else if(board[2][0]==board[2][1]&&board[2][1]==board[2][2])
  {
    game = true;
    return game;
  }
  else if(board[0][0]==board[1][0]&&board[1][0]==board[2][0])
  {
    game = true;
    return game;
  }
  else if(board[0][1]==board[2][1]&&board[2][1]==board[3][1])
  {
    game = true;
    return game;
  }
  else if(board[0][2]==board[1][2]&&board[1][2]==board[2][2])
  {
    game = true;
    return game;
  }
  else if(board[2][0]==board[1][1]&&board[1][1]==board[0][2])
  {
    game = true;
    return game;
  }
  else if(board[2][2]==board[1][1]&&board[1][1]==board[0][0])
  {
    game = true;
    return game;
  }
  else if(board[0][0]!='1'&&board[0][1]!='2'&&board[0][2]!='3'&&board[1][0]!='4'&&board[1][1]!='5'&&board[1][2]!='6'&&board[2][0]!='7'&&board[2][1]!='8'&&board[2][2]!='9')
  {
    game = true;
    cout << "This game has ended in a CAT!" << endl;
    return game;
  }
  else
  {
    return game;
  }
}
