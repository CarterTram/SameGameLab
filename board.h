#ifndef BOARD_H
#define BOARD_H

#include <string>
using namespace std;
class Board{
public:
enum boardColors{	
	blue,
	green,
	red,
	white,

};

private:
	int static const rows = 5;
	int static const cols = 5;
	boardColors GBoard[rows][cols];
public:
	
	Board();
	boardColors getColors(int row, int col);
	int getRows();
	int getCols();
	void setBoard(int rows, int cols);
	bool isBoardEmpty(int rows, int cols);
	void removeConnectedBlocks(boardColors color,int row, int col);
	void dropBlocks(int row, int col);
	void dropAllBlocks();
	void setGBoardElement(int row, int col, boardColors color);

};
#endif