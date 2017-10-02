/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:20:43 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 19:29:23 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

void		erase_elem(t_env *env)
{
	t_elem		*elem;
	t_elem		*prev;

	if (env->cursor != env->cursor->next)
	{
		if (env->cursor == env->first)
			env->first = env->first->next;
		elem = env->cursor;
		prev = elem->prev;
		env->last_suppr = elem->name;
		elem->next->cursor = 1;
		env->cursor = elem->next;
		env->cursor->prev = prev;
		prev->next = env->cursor;
		free(elem);
		elem = NULL;
	}
	else
	{
		free(env->cursor);
		env->cursor = NULL;
		exit (-1);
	}
}

void	recover_elem(t_env *env)
{
	t_elem		*zombie;
	t_elem		*tmp;

	if (env->last_suppr)
	{
		tmp = env->cursor->next;
		if (!(zombie = (t_elem*)malloc(sizeof(t_elem))))
			exit(-1);
		env->cursor->next = zombie;
		tmp->prev = zombie;
		zombie->name = env->last_suppr;
		env->last_suppr = NULL;
		zombie->cursor = 1;
		zombie->select = 0;
		zombie->next = tmp;
		zombie->prev = env->cursor;
		env->cursor->cursor = 0;
		if (env->cursor == env->first)
			env->first = zombie;
		env->cursor = zombie;
	}
}
