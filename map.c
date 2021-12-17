/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fourinrow.h"

t_board	*board_init(void)
{
	t_board	*board;
	int		row;
	int		col;

	board = malloc(sizeof(t_board));
	row = 0;
	while (row < ROWS)
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

int	check_filled(t_board *board)
{
	int	col;

	col = 0;
	while (col < COLS)
	{
		if (board->cell[col][ROWS - 1] == 0)
			return (0);
		col++;
	}
	return (1);
}

void	board_term(t_board *board)
{
	free (board);
}
