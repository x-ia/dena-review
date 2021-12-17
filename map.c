#include "4inrow.h"

t_board	*board_init()
{
	t_board	*board;
	int		row;
	int		col;

	board = malloc(sizeof(t_board));
	row = 0;
	while(row < ROWS)
	{
		col = 0;
		while (col < COLS)
		{
			board->cell[col][row] = 0;
			col++;
		}
		row++;
	}
	board->status = 1;
	board->msg = MSG_TURN;
	return (board);
}

t_board	*put_stone(t_board *board, int col)
{
	int		row;

	if (col < 0 || col >= COLS)
	{
		board->msg = MSG_RANGE;
		return (board);
	}
	row = 0;
	while (row < ROWS)
	{
		if (board->cell[col][row] == 0)
		{
			board->cell[col][row] = board->status;
			return (judge(board, col, row));
		}
		row++;
	}
	board->msg = MSG_FULL;
	return (board);
}

void	board_term(t_board *board)
{
	free (board);
}
