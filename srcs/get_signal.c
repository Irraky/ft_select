/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 13:54:49 by drecours          #+#    #+#             */
/*   Updated: 2017/10/09 14:08:59 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		cont_prg(int sign)
{
	t_env			env;

	(void)sign;
	get_signal();
	if (!(env.data = (struct termios*)malloc(sizeof(struct termios))))
		ft_exit("Probleme de malloc.", -1);
	init_shell(&env);
	ioctl(0, TIOCSTI, "k");
}

static void		stop_prg(int sign)
{
	char	buff[2];

	(void)sign;
	reset_shell();
	tputs(tgetstr("cl", NULL), 1, &my_putchar);
	signal(SIGTSTP, SIG_DFL);
	buff[0] = orig_term->c_cc[VSUSP];
	buff[1] = 0;
	ioctl(0, TIOCSTI, buff);
}

void			exit_prg(int sign)
{
	tputs(tgetstr("cl", NULL), 1, &my_putchar);
	reset_shell();
	exit(sign);
}

static void		win_resize(int sign)
{
	(void)sign;
	ioctl(0, TIOCSTI, "-62");
}

void			get_signal(void)
{
	signal(SIGWINCH, win_resize);
	signal(SIGINT, exit_prg);
	signal(SIGQUIT, exit_prg);
	signal(SIGKILL, exit_prg);
	signal(SIGTERM, exit_prg);
	signal(SIGHUP, exit_prg);
	signal(SIGFPE, exit_prg);
	signal(SIGSEGV, exit_prg);
	signal(SIGABRT, exit_prg);
	signal(SIGALRM, exit_prg);
	signal(SIGUSR1, exit_prg);
	signal(SIGUSR2, exit_prg);
	signal(SIGCONT, cont_prg);
	signal(SIGTSTP, stop_prg);
}
