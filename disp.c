/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fourinrow.h"

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
			printf("%c | ", g_sym_stone[board->cell[col][row]]);
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
		printf("  %c ", toupper(g_key_col[col]));
		col++;
	}
	printf("\n\n");
	clr_line();
	printf("Player %d: %s\n", board->status, board->msg);
}
