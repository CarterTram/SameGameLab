#include "boardview.h"
#include <iostream>
#include "board.h"
using namespace std;
int main()
{
	Board b1;
	b1.setBoard(5,5);
	BoardView Bview(b1);
	int totalMoves = 0;
	while (!(b1.isBoardEmpty(b1.getRows(), b1.getCols()))) {
		cout << endl;
		Bview.BoardView::displayBoard();
		cout << " Enter numbers between 0-4 to choose the row, then 0-4 for the column to select the block" << endl;
		int row;
		int col;
		cin >> row >> col;
		if(cin.fail()) {
			
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please only enter integers" << endl;
			continue;
		}
			
		if (row < 0 || row >= b1.getRows() || col < 0 || col >= b1.getCols()) {
			cout << "\nInvalid input! Please enter row and column within 0 - " << b1.getRows() << endl;
			continue;
		}
		if (b1.getColors(row, col) == Board::boardColors::white) {
			cout << "\nThe selected block is empty, please choose another" << endl;
			continue;
		}

		Board::boardColors color = b1.getColors(row, col);
		b1.removeConnectedBlocks(color,row, col);
		totalMoves++;
	}
	cout << "\nCongratulations! You cleared the board in " << totalMoves << " moves." << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
