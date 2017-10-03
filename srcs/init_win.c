/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:21:32 by drecours          #+#    #+#             */
/*   Updated: 2017/10/03 15:35:10 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

void		read_me(void)
{
	printf("\e[34m ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ  \n");
	printf("᨟                        USER GUIDE                        ᨟\n");
	printf("᨟                                                          ᨟\n");
	printf("᨟      ↑       : prev               ↓     : next           ᨟\n");
	printf("᨟      W / ←   : begin              S / → : end            ᨟\n");
	printf("᨟      ↲       : return args        ESC   : quit           ᨟\n");
	printf("᨟      ⌦  / ⌫  : erase elem         R     : restore last   ᨟\n");
	printf("᨟      A       : select all         D     : unselect all   ᨟\n");
	printf("᨟      SPACE BAR  : select / unselect                      ᨟\n");
	printf(" ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ  \n\n\e[0m");
}

void		print_elem(t_elem *first)
{
	t_elem	*elem;

	elem = first;
	printf("\n");
	while (elem != first->prev)
	{
		if (elem->cursor == 1)
			tputs(tgetstr("us", NULL), 1, &my_putchar);
		if (elem->select == 1)
			tputs(tgetstr("mr", NULL), 1, &my_putchar);
		printf("%s\n", elem->name);
		elem = elem->next;
		tputs(tgetstr("ue", NULL), 1, &my_putchar);
		tputs(tgetstr("me", NULL), 1, &my_putchar);
	}
	if (elem->cursor == 1)
		tputs(tgetstr("us", NULL), 1, &my_putchar);
	if (elem->select)
		tputs(tgetstr("mr", NULL), 1, &my_putchar);
	printf("%s\n", elem->name);
	tputs(tgetstr("ue", NULL), 1, &my_putchar);
	tputs(tgetstr("me", NULL), 1, &my_putchar);
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
