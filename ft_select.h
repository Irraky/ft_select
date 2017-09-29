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

#include <termios.h>
#include <stdlib.h>
#include <term.h>

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
	struct s_elem		*elem;
	struct termios		*data;
}						t_env;



#endif
