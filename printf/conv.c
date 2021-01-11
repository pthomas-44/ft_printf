/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:24:15 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/11 10:00:58 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_convchar(int c)
{
	char *s;

	if (!(s = ft_calloc(sizeof(char), 2)))
		return (0);
	s[0] = c;
	s[1] = 0;
	return (s);
}

char	*pf_convstr(char *str)
{
	char	*s;
	int		i;

	i = 0;
	if (!str)
	{
		if (!(s = ft_calloc(sizeof(char), (6))))
			return (0);
		s[0] = '(';
		s[1] = 'n';
		s[2] = 'u';
		s[3] = 'l';
		s[4] = 'l';
		s[5] = ')';
		return (s);
	}
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

char	*pf_convadress(unsigned long long ptr)
{
	char *s;

	if (!(s = ft_calloc(sizeof(char), 3)))
		return (0);
	s[0] = '0';
	s[1] = 'x';
	s[2] = 0;
	if (!((s = ft_strjoin_f3(s, pf_convhexa(ptr)))))
		return (0);
	return (s);
}

char	*pf_convint(int nb)
{
	return (ft_itoa(nb));
}
