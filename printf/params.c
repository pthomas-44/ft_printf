/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:36:01 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/11 15:16:12 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	pf_strlenwospace(const char *s)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s && s[i])
	{
		if (s[i] != ' ')
			nb++;
		i++;
	}
	return (nb);
}

int		pf_prec(char **s, t_arg *arg, va_list *ap, int *len)
{
	char *tmp;

	tmp = 0;
	if (arg->conv == 's' && ft_strlen(*s) > arg->prec)
	{
		if (!(tmp = ft_calloc(sizeof(char), (arg->prec + 1))))
			return (-1);
		ft_strlcpy(tmp, *s, arg->prec + 1);
		free(*s);
		*s = tmp;
	}
	else
	{
		while (ft_strlen(*s) < arg->prec)
			if (!(*s = ft_strjoin_f2("0", *s)))
				return (-1);
		if (ft_strlen(*s) == arg->prec && (tmp = ft_strchr(*s, '-')))
		{
			*tmp = '0';
			if (!(*s = ft_strjoin_f2("-", *s)))
				return (-1);
		}
	}
	return (0);
}

void		pf_flags(char **s, t_arg *arg, va_list *ap, int *len)
{
	if (arg->flags & HASH && ft_strchrstr("123456789abcdefABCDEF", *s))
	{
		if (arg->conv == 'x')
			*s = ft_strjoin_f2("0x", *s);
		else if (arg->conv == 'X')
			*s = ft_strjoin_f2("0x", *s);
	}
	if (arg->flags & ZERO && !(arg->flags & HYPHEN))
	{
		while (pf_strlenwospace(*s) < arg->prec
			|| (pf_strlenwospace(*s) < arg->width && arg->prec == 0))
			*s = ft_strjoin_f2("0", *s);
	}
	if (arg->flags & PLUS)
	{
		if (**s != '-')
			if (!(*s = ft_strjoin_f2("+", *s)))
				return (-1);
	}
}

int		pf_fillspace(char **s, t_arg *arg, va_list *ap, int *len)
{
	while (ft_strlen(*s) < arg->width)
	{
		if (arg->flags & HYPHEN)
		{
			if (!(*s = ft_strjoin_f1(*s, " ")))
				return (-1);
		}
		else
		{
			if (!(*s = ft_strjoin_f2(" ", *s)))
				return (-1);
		}
	}
	return (0);
}

int		pf_params(char **s, t_arg *arg, va_list *ap, int *len)
{
	if (arg->dot && !(ft_strchr("cp%n", arg->conv)))
		if ((pf_prec(s, arg, ap, len)) == -1)
			return (-1);
	pf_flags(s, arg, ap, len);
	if (ft_strlen(*s) < arg->width)
		if ((pf_fillspace(s, arg, ap, len)) == -1)
			return (-1);
	return (0);
}
