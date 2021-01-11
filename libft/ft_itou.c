/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 15:23:27 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/08 15:24:16 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ulen(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itou(unsigned int n)
{
	unsigned int	nb;
	char			*a;
	int				i;

	nb = n;
	if (!(a = malloc(sizeof(char) * (ft_ulen(n) + 1))))
		return (0);
	i = ft_ulen(n);
	a[i--] = 0;
	while (nb > 9)
	{
		a[i--] = nb % 10 + 48;
		nb /= 10;
	}
	a[i] = nb + 48;
	return (a);
}
