/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthomas <pthomas@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:46:49 by pthomas           #+#    #+#             */
/*   Updated: 2021/01/11 15:01:46 by pthomas          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	pft(int result)
{
	printf("\033[31m -> %d\033[0m\n", result - 2);
}

int		main(int ac, char **av)
{
	char *s = "testunpeuplulon";
	
	// printf("string\n\n");
	// pft(printf("|%-s|", s));
	// pft(printf("|%-5s|", s));
	// pft(printf("|%-50s|", s));
	// pft(printf("|%-.5s|", s));
	// pft(printf("|%-.50s|", s));
	// pft(printf("|%-5.5s|", s));
	// pft(printf("|%-5.50s|", s));
	// pft(printf("|%-50.5s|", s));
	// pft(printf("|%-50.50s|", s));
	// printf("\nchar\n\n");
	// pft(printf("|%-c|", 't'));
	// pft(printf("|%-5c|", 't'));
	// pft(printf("|%-50c|", 't'));
	printf("\nnb\n\n");
	pft(ft_printf("|%+-i|", -123456789));
	pft(ft_printf("|%+-5i|", -123456789));
	pft(ft_printf("|%+-50i|", -123456789));
	pft(ft_printf("|%+-.5i|", -123456789));
	pft(ft_printf("|%+-.50i|", -123456789));
	pft(ft_printf("|%+-5.5i|", -123456789));
	pft(ft_printf("|%+-5.50i|", -123456789));
	pft(ft_printf("|%+-50.5i|", -123456789));
	pft(ft_printf("|%+-50.50i|", -123456789));
	printf("\nnb\n\n");
	pft(printf("|%+-i|", -123456789));
	pft(printf("|%+-5i|", -123456789));
	pft(printf("|%+-50i|", -123456789));
	pft(printf("|%+-.5i|", -123456789));
	pft(printf("|%+-.50i|", -123456789));
	pft(printf("|%+-5.5i|", -123456789));
	pft(printf("|%+-5.50i|", -123456789));
	pft(printf("|%+-50.5i|", -123456789));
	pft(printf("|%+-50.50i|", -123456789));
	// printf("\np\n\n");
	// pft(printf("|%-p|", s));
	// pft(printf("|%-5p|", s));
	// pft(printf("|%-50p|", s));
}

// int		main(int ac, char **av)
// {
// 	unsigned n = 156489476;
// 	printf("\n-- le miens --\n\n");
// 	pft(ft_printf("|%0x|", n));
// 	pft(ft_printf("|%05x|", n));
// 	pft(ft_printf("|%050x|", n));
// 	pft(ft_printf("|%0.5x|", n));
// 	pft(ft_printf("|%0.50x|", n));
// 	pft(ft_printf("|%05.5x|", n));
// 	pft(ft_printf("|%05.50x|", n));
// 	pft(ft_printf("|%050.5x|", n));
// 	pft(ft_printf("|%050.50x|", n));
// 	printf("\n-- le vrai --\n\n");
// 	pft(printf("|%0x|", n));
// 	pft(printf("|%05x|", n));
// 	pft(printf("|%050x|", n));
// 	pft(printf("|%0.5x|", n));
// 	pft(printf("|%0.50x|", n));
// 	pft(printf("|%05.5x|", n));
// 	pft(printf("|%05.50x|", n));
// 	pft(printf("|%050.5x|", n));
// 	pft(printf("|%050.50x|", n));
// }
