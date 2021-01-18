/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:47:01 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 14:12:27 by pthomas          ###   ########lyon.fr   */
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

int		pf_lenwospace(const char *s)
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
