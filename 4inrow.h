#ifndef _4INROW_H
# define _4INROW_H

# include <stdio.h>
# include <stdlib.h>

# define ROWS 6
# define COLS 7
# define TO_CONNECT 4
# define MSG_TURN "Your turn (Input the column ID you want to put.)"
# define MSG_RANGE "Unable to put (the column is out of range.)"
# define MSG_FULL "Unable to put (the column is full.)"
# define MSG_WIN "You win!"

#define clr		printf("\033[2J") // Clear terminal
#define clr_right	printf("\033[0K") // Clear from the cursor to end of line
#define clr_left	printf("\033[1K") // Clear from the cursor to head of line
#define clr_line	printf("\033[2K") // Clear the line
#define location(x,y)	printf("\033[%d;%dH" ,x,y) // Move the cursor to
#define right(x)	printf("\033[%dC" ,x) // Move the cursor right
#define left(x)		printf("\033[%dD" ,x) // Move the cursor left
#define down(y)		printf("\033[%dB" ,y) // Move the cursor down
#define up(y)		printf("\033[%dA" ,y) // Move the cursor up

typedef struct s_board
{
	int		cell[COLS][ROWS];
	int		status;
	char	*msg;
}	t_board;

t_board	*board_init();
void	board_term(t_board *board);
t_board	*put_stone(t_board *board, int col);
t_board	*judge(t_board *board, int col, int row);
void	display(t_board *board);
int		control(void);
int 	waitkb(void);
int 	kbhit(void);

#endif
