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
			board->cell[row][col] = 0;
			col++;
		}
		row++;
	}
	board->status = 1;
	board->msg = "Turn of player 1";
	return (board);
}

t_board	*put_stone(t_board *board, int col)
{
	int		row;

	if (col < 0 || col >= COLS)
	{
		board->msg = "Unable to put (the column is out of range.)";
		return (board);
	}
	row = 0;
	while (row < ROWS)
	{
		if (board->cell[row][col] == 0)
		{
			board->cell[row][col] = board->status;
			return (judge_stone(board, col, row));
		}
		row++;
	}
	board->msg = "Unable to put (the column is full.)";
	return (board);
}

t_board	*judge_stone(t_board *board, int col, int row)
{
	printf("%d %d", col, row);
	return (board);
}

void	board_term(t_board *board)
{
	free (board);
}
