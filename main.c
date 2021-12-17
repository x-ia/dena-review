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
		printf("input: %d\n", input);
		i++;
	}
	printf("%s", board->msg);
	board_term(board);
	return (0);
}
