/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:41:34 by drecours          #+#    #+#             */
/*   Updated: 2017/10/03 12:02:48 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"
#include <stdio.h>

int		clear(void)
{
	char	*res;

	if (!(res = tgetstr("cl", NULL)))
		return (-1);
	tputs(res, 1, &my_putchar);
	return (1);
}

void	reset_shell(t_env *env)
{
	tputs(tgetstr("ve", NULL), 1, &my_putchar);
	env->data->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, env->data) == -1)
		exit (-1);
	tputs(tgetstr("ve", NULL), 1, &my_putchar);
}

int		init_shell(t_env *env)
{
	char	*name_term;

	if (!(env->data = malloc(sizeof(struct termios))))
		return (-1);
	if (!(name_term = getenv("TERM")))
		return (-1);
	if (tgetent(0, name_term) != 1)
		return (-1);
	if (tcgetattr(0, env->data) == -1)
		return (-1);
	env->data->c_lflag &= ~(ICANON);
	env->data->c_lflag &= ~(ECHO);
	env->data->c_cc[VMIN] = 1;
	env->data->c_cc[VTIME] = 100;
	if (tcsetattr(0, TCSADRAIN, env->data) == -1)
		return (-1);
	tputs(tgetstr("vi", NULL), 1, &my_putchar);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	env;
	if (ac > 1)
	{
		if (init_shell(&env) == -1)
			return (-1);
		env.last_suppr = NULL;
		init_win(&av[1], &env);
		reset_shell(&env);
	}
	else
		write(2, "Uh uh, I need args to work...\n", 30);
	return (0);
}
