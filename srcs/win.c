/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 15:21:29 by drecours          #+#    #+#             */
/*   Updated: 2017/10/06 15:26:34 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		win_size(int ac)
{
	struct winsize		win;

	ioctl(0, TIOCGWINSZ, &win);
	if (ac + 11 >= win.ws_row)
	{
		ft_putendl_fd("It's too small, I need a bigger one", 2);
		return (0);
	}
	return (1);
}
