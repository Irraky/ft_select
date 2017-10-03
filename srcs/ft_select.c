/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:00:28 by drecours          #+#    #+#             */
/*   Updated: 2017/10/03 15:08:02 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void	select_one(t_env *env)
{
	if (env->cursor->select == 0)
		env->cursor->select = 1;
	else
		env->cursor->select = 0;
	env->cursor->cursor = 0;
	env->cursor = env->cursor->next;
	env->cursor->cursor = 1;
}

void	select_all(t_env *env)
{
	t_elem	*elem;

	elem = env->cursor->next;
	env->cursor->select = 1;
	while (elem != env->cursor)
	{
		elem->select = 1;
		elem = elem->next;
	}
}

void	unselect_all(t_env *env)
{
	t_elem	*elem;

	elem = env->cursor->next;
	env->cursor->select = 0;
	while (elem != env->cursor)
	{
		elem->select = 0;
		elem = elem->next;
	}
}
