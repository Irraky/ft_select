/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drecours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:41:37 by drecours          #+#    #+#             */
/*   Updated: 2017/09/29 14:58:25 by drecours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

#define ARROW 27
#define UP 65
#define DOWN 66
#define SPACE 32
#define RETURN 10
#define ESC 27
#define BACKSPACE 126
#define DEL 127
#define CTRLD 4
#define A 97
#define N 110
#define E 101


#include <termios.h>
#include <stdlib.h>
#include <term.h>
#include <sys/ioctl.h>
#include <unistd.h>

struct termios			*orig_term;

typedef struct			s_elem
{
	char				*name;
	short				cursor;
	short				select;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef struct			s_env
{
	struct s_elem		*first;
	struct termios		*data;
}						t_env;

/*
** SELECT_FUNCTIONS
*/

t_elem		*list(char **av);

/*
** LIB_FUNCTIONS
*/

int		my_putchar(int c);
void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);

#endif
