/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_key_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 17:50:00 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 19:14:00 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

static void		key_that(char key[3], t_env *env)
{
	//	if (key[0] == CTRLD)
	//		printf("Ctrl+d, quit !\n");
	if (key[0] == ARROW && (key[2] == UP || key[2] == DOWN))
		up_or_down(key, env);
	else if (key[0] == W || (key[0] == ARROW && key[2] == LEFT) ||
			key[0] == S || (key[0] == ARROW && key[2] == RIGHT))
		top_or_bottom(key, env);
	//	else if (key[0] == RETURN)
	//		printf("RETURN\n");
	//	else if (key[0] == ESC)
	//		printf("ESC\n");
	else if (key[0] == BACKSPACE || key[0] == DEL)
		erase(env);
	else if (key[0] == SPACE)
		select_one(env);
	//	else if (key[0] == R)
	//		printf("Ctrl+d,dd quit !\n");
	else if (key[0] == A)
		select_all(env);
	else if (key[0] == D)
		unselect_all(env);
	printf("COIN\n");
}

int				manage_all(t_env *env)
{
	char	buffer[3];
	t_elem	*cur;

	while (1)
	{
		buffer[0] = '\0';
		buffer[1] = '\0';
		buffer[2] = '\0';
		if (read(0, buffer, 3) < 0)
			return (-1);
		else
		{
			clear();
			read_me();
			print_elem(env->first);
			cur = env->first;
			if (cur->cursor == 1)
				printf("|%s|\n", cur->name);
			cur = cur->next;
			while (cur != env->first)
			{
				if (cur->cursor == 1)
					printf("|%s|\n", cur->name);
				cur = cur->next;
			}
			key_that(buffer, env);
		}

	}
	return (0);
}
