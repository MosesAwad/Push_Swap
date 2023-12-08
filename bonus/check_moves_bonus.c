/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:28:26 by mawad             #+#    #+#             */
/*   Updated: 2023/12/07 16:16:59 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_moves(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		sa(a);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(str, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	execute_moves(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	if (!str)
		return (1);
	if (!check_moves(a, b, str))
		return (ft_fprintf(2, "Error\nInvalid instruction or wrong format"),
			free(str), 0);
	free(str);
	while (str)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!check_moves(a, b, str))
			return (ft_fprintf(2, "Error\nInvalid instruction or wrong format"),
				free(str), 0);
		free(str);
	}
	return (1);
}
