/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:20:43 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 19:03:05 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

void		erase(t_env *env)
{
	t_elem		*elem;
	t_elem		*prev;

	if (env->cursor != env->cursor->next)
	{
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
