#include "main.h"

/**
 * print_chessboard - prints a chessboard
 * @chessboard: chessboard layout
 */
void print_chessboard(char (*chessboard)[8])
{
	int row, col;

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
			_putchar(chessboard[row][col]);
		_putchar('\n');
	}
}

