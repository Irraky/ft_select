/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:41:34 by drecours          #+#    #+#             */
/*   Updated: 2017/10/24 17:34:32 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		clear(void)
{
	char	*res;

	if (!(res = tgetstr("cl", NULL)))
		return (-1);
	tputs(res, 1, &my_putchar);
	return (1);
}

void	reset_shell(void)
{
	tputs(tgetstr("ve", NULL), 1, &my_putchar);
	if (tcsetattr(0, TCSADRAIN, orig_term) == -1)
		ft_exit("Probleme de configuration.", -1);
}

int		init_shell(t_env *env)
{
	char	*name_term;

	if (!(name_term = getenv("TERM")))
		ft_exit("Pas de detection du terminal.", -1);
	if (tgetent(0, name_term) != 1)
		ft_exit("Probleme de configuration.", -1);
	if (tcgetattr(0, env->data) == -1)
		ft_exit("Probleme de configuration.", -1);
	env->data->c_lflag &= ~(ICANON);
	env->data->c_lflag &= ~(ECHO);
	env->data->c_cc[VMIN] = 1;
	env->data->c_cc[VTIME] = 100;
	env->data->c_lflag |= ISIG;
	if (tcsetattr(0, TCSADRAIN, env->data) == -1)
		ft_exit("Probleme de configuration.", -1);
	tputs(tgetstr("vi", NULL), 1, &my_putchar);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac > 1)
	{
		if (!win_size(ac - 1))
			exit(-1);
		get_signal();
		if (!(env.data = malloc(sizeof(struct termios))))
			ft_exit("Probleme de malloc.", -1);
		init_shell(&env);
		env.last_suppr = NULL;
		orig_term = env.data;
		init_win(&av[1], &env);
		reset_shell();
	}
	else
		write(2, "Uh uh, I need args to work...\n", 30);
	return (0);
}
