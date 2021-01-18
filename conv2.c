/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:45:51 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 14:17:13 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_convunsigned(unsigned long long int nb, t_arg *arg)
{
	char *s;

	s = ft_itou((unsigned int)nb);
	if (*s == '0' && arg->dot == 1 && arg->prec == 0 && arg->width != 0)
		*s = ' ';
	else if (*s == '0' && arg->dot == 1 && arg->prec == 0)
		*s = '\0';
	return (s);
}

char	*pf_convhexa(unsigned long long int nb, t_arg *arg)
{
	char *hex;
	char *s;

	hex = "0123456789abcdef";
	s = ft_itohex(nb, hex);
	if (*s == '0' && arg->dot == 1 && arg->prec == 0 && arg->width != 0)
		*s = ' ';
	else if (*s == '0' && arg->dot == 1 && arg->prec == 0)
		*s = '\0';
	return (s);
}

char	*pf_convcaphexa(unsigned long long int nb, t_arg *arg)
{
	char *hex;
	char *s;

	hex = "0123456789ABCDEF";
	s = ft_itohex(nb, hex);
	if (*s == '0' && arg->dot == 1 && arg->prec == 0 && arg->width != 0)
		*s = ' ';
	else if (*s == '0' && arg->dot == 1 && arg->prec == 0)
		*s = '\0';
	return (s);
}

char	*pf_convpercent(void)
{
	char *s;

	if (!(s = ft_calloc(sizeof(char), 2)))
		return (0);
	s[0] = '%';
	s[1] = 0;
	return (s);
}
