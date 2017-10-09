/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:13:41 by drecours          #+#    #+#             */
/*   Updated: 2017/10/09 13:33:44 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

static t_elem	*new_elem(t_elem *elem, char *str)
{
	t_elem	*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		exit(-1);
	new->name = str;
	new->cursor = 0;
	new->select = 0;
	new->prev = elem;
	new->next = NULL;
	if (elem)
		elem->next = new;
	return (new);
}

t_elem			*list(char **av)
{
	t_elem	*elem;
	t_elem	*first;

	elem = NULL;
	elem = new_elem(NULL, *av);
	first = elem;
	av++;
	while (*av)
	{
		elem = new_elem(elem, *av);
		av++;
	}
	if (first)
	{
		first->cursor = 1;
		elem->next = first;
		first->prev = elem;
	}
	return (first);
}
