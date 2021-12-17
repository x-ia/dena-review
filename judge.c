#include "4inrow.h"

int	judge_horizon(t_board *board, int row)
{
	int x;
	int	connected;

	x = 0;
	connected = 0;
	while (x < COLS && connected < TO_CONNECT)
	{
		if (board->cell[x][row] == board->status)
			connected++;
		else
			connected = 0;
		x++;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

int	judge_vertic(t_board *board, int col)
{
	int y;
	int	connected;

	y = 0;
	connected = 0;
	while (y < COLS && connected < TO_CONNECT)
	{
		if (board->cell[col][y] == board->status)
			connected++;
		else
			connected = 0;
		y++;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

int	judge_ascend(t_board *board, int col, int row)
{
	int x;
	int y;
	int	connected;

	x = 0;
	y = 0;
	if (col > row)
		x = col - row;
	else
		y = row - col;
	connected = 0;
	while (x < COLS && y < ROWS && connected < TO_CONNECT)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			connected = 0;
		x++;
		y++;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

int	judge_descend(t_board *board, int col, int row)
{
	int x;
	int y;
	int	connected;

	x = 0;
	y = ROWS - 1;
	if (col + row > ROWS - 1)
		x = col + row - ROWS + 1;
	else
		y = row + col;
	connected = 0;
	while (x < COLS && y >= 0 && connected < TO_CONNECT)
	{
		if (board->cell[x][y] == board->status)
			connected++;
		else
			connected = 0;
		x++;
		y--;
	}
	if (connected < TO_CONNECT)
		return (0);
	return (connected);
}

t_board	*judge(t_board *board, int col, int row)
{
	int	match;

	match = judge_horizon(board, row);
	match += judge_vertic(board, col);
	match += judge_ascend(board, col, row);
	match += judge_descend(board, col, row);
	if (match > 0)
	{
		board->msg = MSG_WIN;
		board->status = -board->status;
	}
	else
	{
		board->msg = MSG_TURN;
		board->status = board->status % 2 + 1;
	}
	return (board);
}
