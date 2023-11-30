/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:20:22 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:29:46 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	check_duplicates(long long int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_out_of_range(long long int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (numbers[i] > 2147483647 || numbers[i] < -2147483648)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = 0;
	while (src[i++])
		srclen++;
	i = 0;
	if (size == 0)
		return (srclen);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
