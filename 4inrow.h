#ifndef _4INROW_H
# define _4INROW_H

# include <stdio.h>
# include <stdlib.h>

#define clr		printf("\033[2J") //画面クリア
#define clr_right	printf("\033[0K") //カーソル位置からその行の右端までをクリア
#define clr_left	printf("\033[1K") //カーソル位置からその行の左端までをクリア
#define clr_line	printf("\033[2K") //カーソル位置の行をクリア
#define location(x,y)	printf("\033[%d;%dH" ,x,y) //カーソル位置を移動
#define right(x)	printf("\033[%dC" ,x) //カーソルを指定数だけ右に移動
#define left(x)		printf("\033[%dD" ,x) //カーソルを指定数だけ左に移動
#define down(x)		printf("\033[%dB" ,x) //カーソルを指定数だけ下に移動
#define up(x)		printf("\033[%dA" ,x) //カーソルを指定数だけ上に移動

# define ROWS 6
# define COLS 7

typedef struct s_board
{
	int		cell[ROWS][COLS];
	int		status;
	char	*msg;
}	t_board;

t_board	*board_init();
void	board_term(t_board *board);
t_board	*put_stone(t_board *board, int col);
t_board	*judge_stone(t_board *board, int col, int row);
void	display(t_board *board);
int		control(void);
int 	waitkb(void);
int 	kbhit(void);

#endif
