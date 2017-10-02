/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 16:46:45 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 17:14:08 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		up_or_down(char *buffer, t_env *env)
{
	env->cursor->cursor = 0;
	env->cursor = (key[2] == DOWN) ? env->cursor->next : env->cursor->prev;
	env->cursor->cursor = 1;
}

void		top_or_bottom(char *buffer, t_env *env)
{
	env->cursor->cursor = 0;
	if (key[0] == W || key[2] == LEFT)
		env->cursor = env->first;
	else
		env->cursor = env->first->prev;
	env->cursor->cursor = 1;
}


