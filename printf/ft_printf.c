/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:36:00 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/11 10:19:03 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_fmtlen(const char **fmt)
{
	int i;

	i = 0;
	while ((*fmt)[i] && (*fmt)[i] != '%')
		i++;
	return (i);
}

int		pf_cpy(const char **fmt, char **s, int *len)
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
		(*len)++;
		(*fmt)++;
	}
	if (!((*s = ft_strjoin_f3(*s, str))))
		return (-1);
	return (0);
}

char	*pf_conv(t_arg *arg, va_list *ap, int *len)
{
	char	*s;

	s = 0;
	if (arg->conv == 'c')
		s = pf_convchar(va_arg(*ap, int));
	else if (arg->conv == 's')
		s = pf_convstr(va_arg(*ap, char *));
	else if (arg->conv == 'p')
		s = pf_convadress((unsigned long long)va_arg(*ap, void *));
	else if (arg->conv == 'd' || arg->conv == 'i')
		s = pf_convint(va_arg(*ap, int));
	else if (arg->conv == 'u')
		s = pf_convunsigned(va_arg(*ap, unsigned int));
	else if (arg->conv == 'x')
		s = pf_convhexa(va_arg(*ap, unsigned int));
	else if (arg->conv == 'X')
		s = pf_convcaphexa(va_arg(*ap, unsigned int));
	else if (arg->conv == '%')
		s = pf_convpercent();
	else if (arg->conv == 'n')
		*(va_arg(*ap, int*)) = *len;
	if ((pf_params(&s, arg, ap, len)) == -1)
	{
		free(s);
		return (0);
	}
	*len += ft_strlen(s);
	return (s);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_arg	arg;
	char	*s;
	int		len;
	char	*tmp;

	s = 0;
	len = 0;
	tmp = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (pf_cpy(&fmt, &s, &len) == -1)
			return (-1);
		if (!(pf_parse(&fmt, &arg, &ap)))
		{
			if (!(tmp = pf_conv(&arg, &ap, &len)))
				return (-1);
			if (!(s = ft_strjoin_f3(s, tmp)))
				return (-1);
		}
	}
	write(1, s, len);
	free(s);
	va_end(ap);
	return (len);
}
