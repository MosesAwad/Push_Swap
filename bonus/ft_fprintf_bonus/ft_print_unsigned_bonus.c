/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:24:16 by mawad             #+#    #+#             */
/*   Updated: 2023/12/05 17:30:48 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf_bonus.h"

static int	unsigned_len(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count + 1);
}

static void	put_unsigned(int fd, unsigned int nb)
{
	if (nb >= 10)
	{
		put_unsigned(fd, nb / 10);
		put_unsigned(fd, nb % 10);
	}
	else
	{
		ft_putchar(fd, nb + 48);
	}
}

int	ft_print_unsigned(int fd, unsigned int nb)
{
	put_unsigned(fd, nb);
	return (unsigned_len(nb));
}
