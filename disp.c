#include "4inrow.h"

void	display(t_board *board)
{
	int	row;
	int	col;

//	clr;
	row = 0;
	while (row < ROWS)
	{
		col = 0;
		while (col < COLS)
		{
			printf("| %d ", board->cell[row][col]);
			col++;
		}
		printf("|\n");
		col = 0;
		while (col < COLS)
		{
			printf("----");
			col++;
		}
		printf("-\n");
		row++;
	}
	col = 0;
	while (col < COLS)
	{
		printf("  %d ", col);
		col++;
	}
	printf("\n\n%s\n", board->msg);
}
