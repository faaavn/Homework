#include <iostream>

using namespace std;

const int sizeBoard = 3;
char PlayBoard[sizeBoard][sizeBoard];

struct Tic_tac_toe
{
	char players;
	int move;
	int score;

};



int main()
{
	cout <<' ' << PlayBoard[0][0] << ' ' << '|' << PlayBoard[0][1] << ' ' << '|' << PlayBoard[0][2] << endl; // игровое поле
	cout <<' ' << PlayBoard[1][0] << ' ' << '|' << PlayBoard[1][1] << ' ' << '|' << PlayBoard[1][2] << endl;
	cout <<' ' << PlayBoard[2][0] << ' ' << '|' << PlayBoard[2][1] << ' ' << '|' << PlayBoard[2][2] << endl;
	
 	return 0;
}
