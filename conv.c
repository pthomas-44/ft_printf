/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:24:15 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 14:38:41 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_convchar(int c, t_arg *arg)
{
	char *s;

	if (!(s = ft_calloc(sizeof(char), 2)))
		return (0);
	s[0] = c;
	s[1] = 0;
	if (c == 0)
		arg->caschiant = 1;
	return (s);
}

char	*pf_convstr(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
		return (ft_strdup("(null)"));
	if (!(s = ft_calloc(sizeof(char), (ft_strlen(str) + 1))))
		return (0);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*pf_convadress(unsigned long long int ptr, t_arg *arg)
{
	char *s;

	if (!((s = ft_strjoin_f2("0x", pf_convhexa(ptr, arg)))))
		return (0);
	return (s);
}

char	*pf_convint(int nb, t_arg *arg)
{
	char *s;

	if (!(s = ft_itoa(nb)))
		return (0);
	if (*s == '0' && arg->dot == 1 && arg->prec == 0 && arg->width != 0)
		*s = ' ';
	else if (*s == '0' && arg->dot == 1 && arg->prec == 0)
		*s = '\0';
	return (s);
}
