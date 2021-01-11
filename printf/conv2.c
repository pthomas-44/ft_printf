/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:45:51 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/08 18:01:45 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_convunsigned(unsigned int nb)
{
	return (ft_itou((unsigned int)nb));
}

char	*pf_convhexa(unsigned long long nb)
{
	char *hex;

	hex = "0123456789abcdef";
	return (ft_itohex(nb, hex));
}

char	*pf_convcaphexa(unsigned int nb)
{
	char *hex;

	hex = "0123456789ABCDEF";
	return (ft_itohex(nb, hex));
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
