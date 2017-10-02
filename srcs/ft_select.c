/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 13:16:58 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 16:37:07 by drecours         ###   ########.fr       */
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

	elem = first;
	printf("%s\n", elem->name);
	elem = elem->next;
	while (elem != first)
	{
		printf("%s\n", elem->name);
		elem = elem->next;
	}
}
void		ft_select(char **av, t_env *env)
{
	t_elem		*first;

	first = list(av);
	env->first = first;
	clear();
	read_me();
	print_elem(first);
	voir_touche(first);
}
