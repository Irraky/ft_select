/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:20:43 by drecours          #+#    #+#             */
/*   Updated: 2017/10/09 14:04:25 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

void	erase_elem(t_env *env)
{
	t_elem		*elem;
	t_elem		*prev;

	if (env->cursor != env->cursor->next)
	{
		if (env->cursor == env->first)
			env->first = env->first->next;
		env->last_first = (env->cursor == env->first) ? 1 : 0;
		elem = env->cursor;
		prev = elem->prev;
		env->last_suppr = elem->name;
		env->bfr_suppr = elem->prev;
		elem->next->cursor = 1;
		env->cursor = elem->next;
		env->cursor->prev = prev;
		prev->next = env->cursor;
		free(elem);
		elem = NULL;
	}
	else
	{
		erase_all(env);
		reset_shell();
		exit(1);
	}
}

void	recover_elem(t_env *env)
{
	t_elem		*zombie;
	t_elem		*tmp;

	if (env->last_suppr)
	{
		tmp = env->bfr_suppr->next;
		if (!(zombie = (t_elem*)malloc(sizeof(t_elem))))
			ft_exit("Probleme de malloc.", -1);
		env->bfr_suppr->next = zombie;
		tmp->prev = zombie;
		zombie->name = env->last_suppr;
		env->last_suppr = NULL;
		zombie->cursor = 1;
		zombie->select = 0;
		zombie->next = tmp;
		zombie->prev = env->bfr_suppr;
		env->cursor->cursor = 0;
		if (env->last_first == 1)
		{
			env->first = zombie;
		}
		env->cursor = zombie;
		env->bfr_suppr = NULL;
	}
}

void	erase_all(t_env *env)
{
	t_elem		*elem;
	t_elem		*tmp;

	elem = env->first->prev;
	elem->next = NULL;
	elem = env->first;
	while (elem)
	{
		tmp = elem->next;
		free(elem);
		elem = NULL;
		elem = tmp;
	}
}
