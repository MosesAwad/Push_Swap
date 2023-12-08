/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 21:34:28 by mawad             #+#    #+#             */
/*   Updated: 2023/12/05 17:57:15 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	parse_message(int flag)
{
	if (flag == 3)
		ft_fprintf(2, "Error\nDuplicates found\n");
	else if (flag == 4)
		ft_fprintf(2, "Error\nArgument out of INT range present\n");
}

int	parser(long long int *numbers, int size)
{
	int	flag;

	flag = 1;
	if (size == 1 || size == 0)
	{
		if (size == 1 && check_out_of_range(numbers, size))
			flag = 4;
		else
			flag = 2;
	}
	else if (check_duplicates(numbers, size))
		flag = 3;
	else if (check_out_of_range(numbers, size))
		flag = 4;
	parse_message(flag);
	return (flag);
}
