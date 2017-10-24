/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 18:21:32 by drecours          #+#    #+#             */
/*   Updated: 2017/10/24 17:34:06 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		read_me(void)
{
	ft_putstr_fd("\e[36m ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ", 2);
	ft_putstr_fd("ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ  \n", 2);
	ft_putstr_fd("᨟                     USER GUIDE                     ᨟\n", 2);
	ft_putstr_fd("᨟                                                    ᨟\n", 2);
	ft_putstr_fd("᨟    ↑       : prev             ↓     : next         ᨟\n", 2);
	ft_putstr_fd("᨟    W / ←   : begin            S / → : end          ᨟\n", 2);
	ft_putstr_fd("᨟    ↲       : return args      ESC   : quit         ᨟\n", 2);
	ft_putstr_fd("᨟    ⌦  / ⌫  : erase elem       R     : restore last ᨟\n", 2);
	ft_putstr_fd("᨟    A       : select all       D     : unselect all ᨟\n", 2);
	ft_putstr_fd("᨟    SPACE BAR  : select / unselect                  ᨟\n", 2);
	ft_putstr_fd(" ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ", 2);
	ft_putstr_fd("ᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖᨖ  \n\e[0m", 2);
}

void		print_elem(t_elem *first)
{
	t_elem	*elem;

	elem = first;
	write(2, "\n", 1);
	while (elem != first->prev)
	{
		if (elem->cursor == 1)
			tputs(tgetstr("us", NULL), 1, &my_putchar);
		if (elem->select == 1)
			tputs(tgetstr("mr", NULL), 1, &my_putchar);
		ft_putendl_fd(elem->name, 2);
		elem = elem->next;
		tputs(tgetstr("ue", NULL), 1, &my_putchar);
		tputs(tgetstr("me", NULL), 1, &my_putchar);
	}
	if (elem->cursor == 1)
		tputs(tgetstr("us", NULL), 1, &my_putchar);
	if (elem->select)
		tputs(tgetstr("mr", NULL), 1, &my_putchar);
	ft_putendl_fd(elem->name, 2);
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
