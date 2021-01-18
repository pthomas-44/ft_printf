/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:11:58 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/18 14:13:34 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_fillspace2(char **s, t_arg *arg)
{
	if (!(arg->caschiant))
	{
		while ((int)ft_strlen(*(s)) < arg->width)
		{
			if (arg->flags & HYPHEN)
			{
				if (!(*s = ft_strjoin_f1(*s, " ")))
					return (-1);
			}
			else
			{
				if (!(*s = ft_strjoin_f2(" ", *s)))
					return (-1);
			}
		}
	}
	return (0);
}

int		pf_fillspace(char **s, t_arg *arg)
{
	char *tmp;

	if (arg->caschiant && arg->flags & HYPHEN)
	{
		if (!(tmp = ft_calloc(sizeof(char), arg->width + 1)))
			return (-1);
		while ((int)ft_strlen(tmp) < arg->width)
			if (!(tmp = ft_strjoin_f1(tmp, " ")))
				return (-1);
		tmp[0] = 0;
		free(*s);
		*s = tmp;
	}
	else if (arg->caschiant)
	{
		while ((int)ft_strlen(*(s)) < arg->width - arg->caschiant)
		{
			if (!(*s = ft_strjoin_f2(" ", *s)))
				return (-1);
		}
	}
	return (pf_fillspace2(s, arg));
}
