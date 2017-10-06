/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_key_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:50:00 by drecours          #+#    #+#             */
/*   Updated: 2017/10/06 16:39:42 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

void		esc(t_env *env)
{
	tputs(tgetstr("cl", NULL), 1, &my_putchar);
	reset_shell();
	erase_all(env);
	free(env->data);
	exit(0);
}

static void		key_that(char key[3], t_env *env)
{
	if (key[0] == ARROW && (key[2] == UP || key[2] == DOWN))
		up_or_down(key, env);
	else if (key[0] == W || (key[0] == ARROW && key[2] == LEFT) ||
			key[0] == S || (key[0] == ARROW && key[2] == RIGHT))
		top_or_bottom(key, env);
	else if (key[0] == RETURN)
		ft_return(env);
	else if (key[0] == BACKSPACE || key[0] == DEL)
		erase_elem(env);
	else if (key[0] == ESC && key[1] == 0)
		esc(env);
	else if (key[0] == SPACE)
		select_one(env);
	else if (key[0] == R)
		recover_elem(env);
	else if (key[0] == A)
		select_all(env);
	else if (key[0] == D)
		unselect_all(env);
}

int				manage_all(t_env *env)
{
	char	buffer[3];

	while (1)
	{
		ft_bzero(&buffer, 3);
		if (read(0, buffer, 3) < 0)
			return (-1);
		if (buffer[0] == CTRLD)
			exit_prg(1);
		else
		{
			key_that(buffer, env);
			clear();
			read_me();
			print_elem(env->first);
		}

	}
	return (0);
}
