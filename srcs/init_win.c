/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:21:32 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 18:59:49 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

void		read_me(void)
{
	printf(" ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ\n");
	printf("᨟                        USER GUIDE                        ᨟\n");
	printf("᨟                                                          ᨟\n");
	printf("᨟      ↑       : prev               ↓     : next           ᨟\n");
	printf("᨟      W / ←   : begin              S / → : end            ᨟\n");
	printf("᨟      ↲       : return args        ESC   : quit           ᨟\n");
	printf("᨟      ⌦  / ⌫  : erase elem         R     : restore last   ᨟\n");
	printf("᨟      A       : select all         D     : unselect all   ᨟\n");
	printf("᨟      SPACE BAR  : select / unselect                      ᨟\n");
	printf(" ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ\n\n");
}

void		print_elem(t_elem *first)
{
	t_elem	*elem;

	if (first != first->next)
	{
		elem = first;
		while (elem != first->prev)
		{
			printf("%s\n", elem->name);
			elem = elem->next;
		}
		printf("%s\n", elem->name);
	}
	else
		printf("%s\n", first->name);
}

void		init_win(char **av, t_env *env)
{
	t_elem		*first;

	first = list(av);
	env->first = first;
	env->cursor = first;
	clear();
	read_me();
	print_elem(first);
	manage_all(env);
}
