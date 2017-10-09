/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:33:08 by drecours          #+#    #+#             */
/*   Updated: 2017/10/09 13:34:34 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		ft_return(t_env *env)
{
	t_elem		*tmp;
	t_elem		*tmp2;
	short		space;

	space = 0;
	tmp = env->first->prev;
	tmp->next = NULL;
	tmp = env->first;
	tputs(tgetstr("cl", NULL), 1, &my_putchar);
	while (tmp && tmp->name)
	{
		if (tmp->select == 1)
		{
			if (space == 1)
				write(STDOUT_FILENO, " ", 1);
			write(STDOUT_FILENO, tmp->name, ft_strlen(tmp->name));
			space = 1;
		}
		tmp2 = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = tmp2;
	}
	reset_shell();
	exit(1);
}
