/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 13:41:34 by drecours          #+#    #+#             */
/*   Updated: 2017/09/29 15:13:34 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <stdio.h>
#include <unistd.h>

int		my_putchar(int c)
{
	write(1, &c, 1);
	return (c);
}

int		clear(void)
{
	char	*res;
	if (!(res = tgetstr("cl", NULL)))
		return (-1);
	tputs(res, 1, &my_putchar);
	return (1);
}

int		voir_touche()
{
	char	buffer[3];

	while (1)
	{
		read(0, buffer, 3);
		if (buffer[0] == 27)
			printf("C'est une fleche !\n");
		else if (buffer[0] == 4)
		{
			printf("Ctrl+d, quit !\n");
			return (0);
		}
		else
			printf("perdu");
	}
	return (0);
}

int		main(int ac, char **av, char **env)
{
	char	*name_term;
	t_env	envi;
	(void)ac;(void)av;(void)env;

	if (!(name_term = getenv("TERM")))
		return (-1);
	if (tgetent(NULL, name_term) < 0)
		return (-1);
	if(tcgetattr(0, envi.data) == 0)
	{
		printf("COIN");
		return (-1);
	}
	voir_touche();
	//if (!(clear()))
	//	return (-1)
	//if (tcsetattr(0, TCSADRAIN, &term) == -1)
	//	 return (-1);;
	printf("COINCOIN");
	return (0);
}
