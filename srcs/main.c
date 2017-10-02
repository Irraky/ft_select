/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:41:34 by drecours          #+#    #+#             */
/*   Updated: 2017/10/02 16:23:39 by drecours         ###   ########.fr       */
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

void	key_that(char key[3])
{
	if (key[0] == CTRLD)
		printf("Ctrl+d, quit !\n");
	else if (key[0] == ARROW && (key[2] == UP || key[2] == DOWN))
		printf("Arrow\n");
	else if (key[0] == W || (key[0] == ARROW && key[2] == LEFT))
		printf("W\n");
	else if (key[0] == S || (key[0] == ARROW && key[2] == RIGHT))
		printf("S\n");
	else if (key[0] == RETURN)
		printf("RETURN\n");
	else if (key[0] == ESC)
		printf("ESC\n");
	else if (key[0] == BACKSPACE)
		printf("Ctrl+d, quit !\n");
	else if (key[0] == DEL)
		printf("Ctrl+d, quit !\n");
	else if (key[0] == R)
		printf("Ctrl+d, quit !\n");
	else if (key[0] == A)
		printf("Ctrl+d, quit !\n");
	else if (key[0] == D)
		printf("Ctrl+d, quit !\n");
	else if (key[0] == SPACE)
		printf("Ctrl+d, quit !\n");
}

int		voir_touche(t_elem *first)
{
	char	buffer[3];
while (1)
	{		buffer[0] = '\0';
		buffer[1] = '\0';
		buffer[2] = '\0';
		if (read(0, buffer, 3) < 0)
			return (-1);
		clear();
		read_me();
		print_elem(first);
		key_that(buffer);
}


	return (0);
}

void	reset_shell(t_env *env)
{
	tputs(tgetstr("ve", NULL), 1, &my_putchar);
	env->data->c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, env->data) == -1)
		exit (-1);
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
		ft_select(&av[1], &env);
		reset_shell(&env);
	}
	else
		write(2, "Uh uh, I need args to work...\n", 30);
	return (0);
}
