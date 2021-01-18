/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:36:01 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 14:58:05 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_prec(char **s, t_arg *arg)
{
	char *tmp;

	tmp = 0;
	if (arg->conv == 's' && (int)ft_strlen(*s) > arg->prec)
	{
		if (!(tmp = ft_calloc(sizeof(char), (arg->prec + 1))))
			return (-1);
		ft_strlcpy(tmp, *s, arg->prec + 1);
		free(*s);
		*s = tmp;
	}
	else if (arg->conv != 's')
	{
		while ((int)ft_strlen(*s) < arg->prec)
			if (!(*s = ft_strjoin_f2("0", *s)))
				return (-1);
		if ((int)ft_strlen(*s) == arg->prec && (tmp = ft_strchr(*s, '-')))
		{
			*tmp = '0';
			if (!(*s = ft_strjoin_f2("-", *s)))
				return (-1);
		}
	}
	return (0);
}

int		pf_flags2(char **s, t_arg *arg)
{
	if (arg->flags & PLUS)
	{
		if (**s != '-' && arg->width && !(arg->dot)
		&& arg->flags & ZERO && !(arg->flags & HYPHEN))
			**s = '+';
		else if (**s != '-')
			if (!(*s = ft_strjoin_f2("+", *s)))
				return (-1);
	}
	else if (arg->flags & SPACE)
	{
		if (**s == '0' && (int)ft_strlen(*s) == arg->width)
			**s = ' ';
		else if (**s != '-')
			if (!(*s = ft_strjoin_f2(" ", *s)))
				return (-1);
	}
	return (0);
}

int		pf_flags(char **s, t_arg *arg)
{
	char *tmp;

	if (arg->flags & HASH && ft_strchrstr("123456789abcdefABCDEF", *s))
	{
		if (arg->conv == 'x')
			*s = ft_strjoin_f2("0x", *s);
		else if (arg->conv == 'X')
			*s = ft_strjoin_f2("0X", *s);
	}
	if (arg->flags & ZERO && !(arg->flags & HYPHEN))
		while (pf_lenwospace(*s) < arg->prec
		|| (pf_lenwospace(*s) < arg->width && arg->dot == 0))
			*s = ft_strjoin_f2("0", *s);
	if ((tmp = ft_strchr(*s, '-')))
	{
		*tmp = '0';
		**s = '-';
	}
	return (pf_flags2(s, arg));
}

int		pf_params(char **s, t_arg *arg)
{
	if (arg->dot && !(ft_strchr("cp%n", arg->conv)))
		if ((pf_prec(s, arg)) == -1)
			return (-1);
	if ((pf_flags(s, arg)) == -1)
		return (-1);
	if ((int)ft_strlen(*s) < arg->width)
		if ((pf_fillspace(s, arg)) == -1)
			return (-1);
	return (0);
}
