/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:00:28 by drecours          #+#    #+#             */
/*   Updated: 2017/10/03 12:24:21 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void	select_one(t_env *env)
{
	env->cursor->select = 1;
	env->cursor = env->cursor->next;
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
