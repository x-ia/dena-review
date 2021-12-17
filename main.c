#include "4inrow.h"

int	main(void)
{
	t_board	*board;
	int	input;
	int	i;

	i = 0;
	board = board_init(ROWS, COLS);
	while(board->status > 0)
	{
		display(board);
		input = control();
		board = put_stone(board, input);
		up(ROWS * 2 + 4);
		i++;
	}
	board->status = -board->status;
	display(board);
	board_term(board);
	return (0);
}
