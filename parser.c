/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 10:41:16 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 15:29:01 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parse_flags(const char **fmt, t_arg *arg)
{
	while (ft_strchr("#0- +", **fmt))
	{
		if (**fmt == '#')
			arg->flags |= HASH;
		if (**fmt == '-')
			arg->flags |= HYPHEN;
		else if (**fmt == '0')
			arg->flags |= ZERO;
		if (**fmt == '+')
			arg->flags |= PLUS;
		else if (**fmt == ' ')
			arg->flags |= SPACE;
		(*fmt)++;
	}
}

void	pf_parse_width(const char **fmt, t_arg *arg)
{
	if (**fmt == '*')
	{
		arg->width = va_arg(arg->ap, int);
		(*fmt)++;
	}
	if (arg->width < 0)
	{
		arg->width *= -1;
		arg->flags |= HYPHEN;
	}
	else
	{
		while (ft_isdigit(**fmt))
		{
			arg->width = arg->width * 10 + **fmt - 48;
			(*fmt)++;
		}
	}
}

void	pf_parse_prec(const char **fmt, t_arg *arg)
{
	if (**fmt == '.')
	{
		arg->dot = 1;
		(*fmt)++;
		if (**fmt == '*')
		{
			arg->prec = va_arg(arg->ap, int);
			(*fmt)++;
		}
		if (arg->prec < 0)
		{
			arg->prec = 0;
			arg->dot = 0;
		}
		else
		{
			while (ft_isdigit(**fmt))
			{
				arg->prec = arg->prec * 10 + **fmt - 48;
				(*fmt)++;
			}
		}
	}
}

int		pf_parse(const char **fmt, t_arg *arg)
{
	arg->flags = 0;
	arg->width = 0;
	arg->dot = 0;
	arg->prec = 0;
	arg->conv = 0;
	arg->caschiant = 0;
	if (**fmt != '%')
		return (-1);
	(*fmt)++;
	pf_parse_flags(fmt, arg);
	pf_parse_width(fmt, arg);
	pf_parse_prec(fmt, arg);
	if (ft_strchr("cspdiuxX%n", **fmt))
	{
		arg->conv = **fmt;
		(*fmt)++;
	}
	return (0);
}
