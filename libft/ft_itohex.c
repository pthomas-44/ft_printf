/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:23:12 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/08 15:24:08 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexlen(unsigned long long n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*ft_itohex(unsigned long long n, char *hex)
{
	char	*a;
	int		i;

	if (!(a = ft_calloc(sizeof(char), (ft_hexlen(n) + 1))))
		return (0);
	i = ft_hexlen(n);
	a[i--] = 0;
	while (n > 15)
	{
		a[i--] = hex[n % 16];
		n /= 16;
	}
	a[i] = hex[n];
	return (a);
}
