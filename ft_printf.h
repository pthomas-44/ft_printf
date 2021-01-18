/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:52:43 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 15:28:12 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include "./libft/libft.h"

# define HASH 1
# define ZERO 2
# define HYPHEN 4
# define SPACE 8
# define PLUS 16

typedef struct	s_arg
{
	char		flags;
	int			width;
	int			dot;
	int			prec;
	char		conv;
	va_list		ap;
	int			len;
	int			caschiant;
}				t_arg;

int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));
int				pf_parse(const char **fmt, t_arg *arg);
int				pf_params(char **s, t_arg *arg);
int				pf_fillspace(char **s, t_arg *arg);
int				pf_fmtlen(const char **fmt);
int				pf_lenwospace(const char *s);
char			*pf_convchar(int c, t_arg *arg);
char			*pf_convstr(char *str);
char			*pf_convadress(unsigned long long int ptr, t_arg *arg);
char			*pf_convint(int nb, t_arg *arg);
char			*pf_convunsigned(unsigned long long int nb, t_arg *arg);
char			*pf_convhexa(unsigned long long int nb, t_arg *arg);
char			*pf_convcaphexa(unsigned long long int nb, t_arg *arg);
char			*pf_convpercent(void);

#endif
