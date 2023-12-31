/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:14:07 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:33:25 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_len(unsigned int c)
{
	int	len;

	len = 0;
	while (c >= 16)
	{
		c = c / 16;
		len++;
	}
	return (len + 1);
}

static void	put_hex(unsigned int c, char frmt)
{
	char	*set1;
	char	*set2;

	set1 = "0123456789ABCDEF";
	set2 = "0123456789abcdef";
	if (c >= 16)
	{
		put_hex(c / 16, frmt);
		put_hex(c % 16, frmt);
	}
	else
	{
		if (frmt == 'X')
			ft_putchar(set1[c % 16]);
		else if (frmt == 'x')
			ft_putchar(set2[c % 16]);
	}
}

int	ft_print_hex(unsigned int c, char frmt)
{
	int	len;

	len = 0;
	put_hex(c, frmt);
	len = hex_len(c);
	return (len);
}
