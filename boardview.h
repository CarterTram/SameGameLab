#ifndef BOARDVIEW_H
#define BOARDVIEW_H
#include "board.h"
class BoardView {
private:
	Board *GameBoard; //Ask how it knows to point to the original board
public:
	BoardView(Board &GameBoard);
	void displayBoard();

};

#endif