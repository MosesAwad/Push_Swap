/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 19:24:16 by mawad             #+#    #+#             */
/*   Updated: 2023/12/05 17:30:43 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf_bonus.h"

static int	num_len(int nb)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	if (nb == -2147483648)
		return (11);
	if (nb < 0)
	{
		nb *= -1;
		flag = 1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	if (flag)
		return (count + 2);
	else
		return (count + 1);
}

static void	put_nbr(int fd, int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr(fd, "-2");
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar(fd, '-');
	}
	if (nb >= 10)
	{
		put_nbr(fd, nb / 10);
		put_nbr(fd, nb % 10);
	}
	else
	{
		ft_putchar(fd, nb + 48);
	}
}

int	ft_print_nbr(int fd, int nb)
{
	put_nbr(fd, nb);
	return (num_len(nb));
}
