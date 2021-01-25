/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:36:00 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/20 13:26:50 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_cpy(t_arg *arg, const char **fmt, char **s)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = ft_calloc(sizeof(char), (pf_fmtlen(fmt) + 1))))
		return (-1);
	str[0] = 0;
	while (**fmt && **fmt != '%')
	{
		str[i] = **fmt;
		i++;
		(arg->len)++;
		(*fmt)++;
	}
	*s = str;
	return (0);
}

char	*pf_converter(t_arg *arg, char *s)
{
	if (arg->conv == 'c')
		s = pf_convchar(va_arg(arg->ap, int), arg);
	else if (arg->conv == 's')
		s = pf_convstr(va_arg(arg->ap, char *));
	else if (arg->conv == 'p')
		s = pf_convadress((unsigned long long)va_arg(arg->ap, void *), arg);
	else if (arg->conv == 'd' || arg->conv == 'i')
		s = pf_convint(va_arg(arg->ap, int), arg);
	else if (arg->conv == 'u')
		s = pf_convunsigned(va_arg(arg->ap, unsigned int), arg);
	else if (arg->conv == 'x')
		s = pf_convhexa(va_arg(arg->ap, unsigned int), arg);
	else if (arg->conv == 'X')
		s = pf_convcaphexa(va_arg(arg->ap, unsigned int), arg);
	else if (arg->conv == '%')
		s = pf_convpercent();
	else if (arg->conv == 'n')
	{
		*(va_arg(arg->ap, int*)) = arg->len;
		return (ft_strdup(""));
	}
	return (s);
}

char	*pf_conv(t_arg *arg)
{
	char	*s;

	s = 0;
	if (!(s = pf_converter(arg, s)))
		return (0);
	if ((pf_params(&s, arg)) == -1)
	{
		free(s);
		return (0);
	}
	if (arg->caschiant && arg->flags & HYPHEN)
		arg->len += arg->caschiant + ft_strlen(s + 1);
	else
		arg->len += ft_strlen(s) + arg->caschiant;
	return (s);
}

int		ft_printf(const char *fmt, ...)
{
	t_arg	arg;
	char	*s;

	s = 0;
	arg.len = 0;
	va_start(arg.ap, fmt);
	while (*fmt)
	{
		if (pf_cpy(&arg, &fmt, &s) == -1)
			return (-1);
		write(1, s, ft_strlen(s));
		free(s);
		if (!(pf_parse(&fmt, &arg)))
		{
			if (!(s = pf_conv(&arg)))
				return (-1);
			if (arg.caschiant && arg.flags & HYPHEN)
				write(1, s, arg.caschiant + ft_strlen(s + 1));
			else
				write(1, s, ft_strlen(s) + arg.caschiant);
			free(s);
		}
	}
	va_end(arg.ap);
	return (arg.len);
}
