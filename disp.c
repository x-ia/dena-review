#include "4inrow.h"

void	display(t_board *board)
{
	int	row;
	int	col;

	printf("\n");
	row = ROWS;
	while (row > 0)
	{
		row--;
		col = 0;
		printf("%d | ", row);
		while (col < COLS)
		{
			printf("%d | ", board->cell[col][row]);
			col++;
		}
		col = 0;
		printf("\n  -");
		while (col < COLS)
		{
			printf("----");
			col++;
		}
		printf("\n");
	}
	printf("  ");
	col = 0;
	while (col < COLS)
	{
		printf("  %d ", col);
		col++;
	}
	printf("\n\n");
	clr_line;
	printf("Player %d: %s\n", board->status, board->msg);
}
