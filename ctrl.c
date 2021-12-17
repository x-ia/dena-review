/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykosaka <ykosaka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#             */
/*   Updated: 2021/11/29 04:39:38 by ykosaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fourinrow.h"

int	control(void)
{
	char	hit;
	int		i;

	i = 0;
	hit = waitkb();
	while (i < COLS)
	{
		if (hit == g_key_col[i])
			return (i);
		i++;
	}
	if (hit == 'q')
		return (-9);
	if (hit == 'z')
		return (-2);
	return (-1);
}
