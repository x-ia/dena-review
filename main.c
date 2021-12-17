/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fourinrow.h"

const unsigned char	g_sym_stone[] = {' ', 'o', 'x'};
const unsigned char	g_key_col[] = {'a', 's', 'd', 'f', 'j', 'k', 'l'};

int	main(void)
{
	t_board	*board;
	int		input;
	int		i;

	i = 0;
	board = board_init();
	while (board->status > 0)
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
