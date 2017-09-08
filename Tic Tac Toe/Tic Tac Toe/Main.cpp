#include <iostream>
using namespace std;
#include <vector>

const int iGridSize = 3; // constand is 3
char acGrid[iGridSize][iGridSize]; // the max size of the board which is 9

void displayGrid() // drawing the game board
{
	cout<<endl<<" | 1 | 2 | 3 |"<<endl; // gameboard
	cout<<"--------------";
	for (int y=0; y<iGridSize; y++)
	{
		cout<<endl<<y+1<<"|";
		for(int x=0; x<iGridSize; x++)
		{
			if (acGrid[x][y] == 'O') // prints O
				cout<<" O |";
			else if (acGrid[x][y] == 'X') // prints X
				cout<<" X |"; 
			else 
				cout<<"   |";
		}
		cout<<endl<<"--------------";
	}
}


void placeCounter(int iPlayer) // places the player on the game board. parameter iplayer determines the players turn
{
	int iX,iY;
	
	cout << endl << "enter 1,2 or 3 for the column" << endl;
	cin >> iX; // input number out of 3 for column
	cout << "enter 1,2 or 3 for the row" << endl;
	cin >> iY; // input number out of 3 for row
	
	if (iPlayer==1)
	{
		if (acGrid[iX-1][iY-1]!='X' && acGrid[iX-1][iY-1]!='O')
			acGrid[iX-1][iY-1]='O'; // player 1 input
		else
		{
			cout << endl << " a Player has already placed in here! you'll skip a turn!" << endl << endl;
			system("pause");
		}
	}
	else
	{
		if (acGrid[iX-1][iY-1]!='O' && acGrid[iX-1][iY-1]!='X' )
			acGrid[iX-1][iY-1]='X'; // player 2 input
		else
		{
			cout << endl << " a Player has already placed in here! you'll skip a turn!" << endl << endl;
			system("pause");
		}


	}
}

bool win()
{
	//This section contains the winning condition of the game

	//top row
	if ((acGrid[0][0] == acGrid [1][0]) && (acGrid [1][0] == acGrid [2][0]))
	{
		//checks for O and X
		if (acGrid[1][0] == 'O')
		{
			cout << endl << "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[1][0] == 'X')
		{
			cout << endl << "player 2 wins" << endl;
			return true;
		}
	}
	
	//middle row
	if ((acGrid[0][1] == acGrid [1][1]) && (acGrid [1][1] == acGrid [2][1]))
	{
		//checks for O and X
		if (acGrid[1][1] == 'O')
		{
			cout << endl << "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[1][1] == 'X')
		{
			cout << endl << "player 2 wins" << endl;
			return true;
		}
	}
	
	//bottom row
	if ((acGrid[0][2] == acGrid [1][2]) && (acGrid [1][2] == acGrid [2][2]))
	{
		//checks for O and X
		if (acGrid[1][2] == 'O')
		{
			cout <<endl<< "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[1][2] == 'X')
		{
			cout <<endl<< "player 2 wins" << endl;
			return true;
		}
	}

	//left column
	if ((acGrid[0][0] == acGrid [0][1]) && (acGrid [0][1] == acGrid [0][2]))
	{
		//checks for O and X
		if (acGrid[0][1] == 'O')
		{
			cout << endl << "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[0][1] == 'X')
		{
			cout << endl << "player 2 wins" << endl;
			return true;
		}
	}

	//middle column
	if ((acGrid[1][0] == acGrid [1][1]) && (acGrid [1][1] == acGrid [1][2]))
	{
		//checks for O and X
		if (acGrid[1][1] == 'O')
		{
			cout <<endl<< "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[1][1] == 'X')
		{
			cout <<endl<< "player 2 wins" << endl;
			return true;
		}
	}
	
	//right column
	if ((acGrid[2][0] == acGrid [2][1]) && (acGrid [2][1] == acGrid [2][2]))
	{
		//checks for O and X
		if (acGrid[2][1] == 'O')
		{
			cout <<endl<< "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[2][1] == 'X')
		{
			cout <<endl<< "player 2 wins" << endl;
			return true;
		}
	}

	//diagonal
	if ((acGrid[0][0] == acGrid [1][1]) && (acGrid [1][1] == acGrid [2][2]))
	{
		//checks for O and X
		if (acGrid[1][1] == 'O')
		{
			cout <<endl<< "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[1][1] == 'X')
		{
			cout <<endl<< "player 2 wins" << endl;
			return true;
		}
	}
	
	//anti-diagonal
	if ((acGrid[2][0] == acGrid [1][1]) && (acGrid [1][1] == acGrid [0][2]))
	{
		//checks for O and X
		if (acGrid[1][1] == 'O')
		{
			cout <<endl<< "player 1 wins" << endl;
			return true;
		}
		else if (acGrid[1][1] == 'X')
		{
			cout <<endl<< "player 2 wins" << endl;
			return true;
		}
	}

	// these nested loops check if each cell in the board has been played on; returning false if there are spaces left
	for (int i=0; i<iGridSize; i++)
		for(int j=0; j<iGridSize; j++)
			if (acGrid[i][j] == ' ')
				return false;
	// this will only get reached if no player has won and there are no spaces on the board
	cout << endl << "it's a draw, everyone is a winner! "<<endl;
	return true;
}
	
int main()
{
	bool bGameOver=false;
	memset(acGrid, ' ', sizeof(acGrid)); // checks the size of the array
	int imovecount = 0 ;

	do
	{
		system("cls"); // clear screen
		displayGrid(); // display the game board
		cout<<endl<<endl<<"Player "<<(imovecount%2)+1<<"'s Turn"<<endl; // this display the players turn
		placeCounter((imovecount % 2)+1); // player's turn is switching with a mod

		if (win()) // if the win condition has been met then exit the loop
			bGameOver = true; // exit the loop

		imovecount++; // +1 to move count to change number to Odd or Even
		
	}
	while ((bGameOver==false)); // exit loop when board is full or if a player has won

system("pause");
 return 0;
}
