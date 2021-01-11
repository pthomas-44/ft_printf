/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:52:43 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/11 12:39:51 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

# define HASH 1
# define ZERO 2
# define HYPHEN 4
# define SPACE 8
# define PLUS 16
# define L 1
# define LL 2
# define H 4
# define HH 8

typedef struct	s_arg
{
	char		flags;
	int			width;
	int			dot;
	int			prec;
	char		length;
	char		conv;
}				t_arg;

int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));
int				pf_parse(const char **fmt, t_arg *arg, va_list *ap);
int				pf_params(char **s, t_arg *arg, va_list *ap, int *len);
char			*pf_convchar(int c);
char			*pf_convstr(char *str);
char			*pf_convadress(unsigned long long ptr);
char			*pf_convint(int nb);
char			*pf_convunsigned(unsigned int nb);
char			*pf_convhexa(unsigned long long nb);
char			*pf_convcaphexa(unsigned int nb);
char			*pf_convpercent(void);

#endif
