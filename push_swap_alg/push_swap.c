/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:29:08 by mawad             #+#    #+#             */
/*   Updated: 2023/12/07 23:13:13 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_init_a2b(t_stack **b, t_stack **a)
{
	target_finder1(*b, *a);
	set_index(*a);
	set_index(*b);
	set_price(*b, *a);
	set_cheapest(*a);
	move_nodes_a2b(b, a);
	pb(b, a);
}

static void	move_init_b2a(t_stack **a, t_stack **b)
{
	target_finder2(*a, *b);
	set_index(*b);
	set_index(*a);
	set_price(*a, *b);
	set_cheapest(*b);
	move_nodes_b2a(a, b);
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	a_len;
	int	b_len;

	a_len = stack_len(*a);
	if (a_len > 3)
	{
		pb(b, a);
		pb(b, a);
		a_len -= 2;
	}
	while (a_len > 3)
	{
		move_init_a2b(b, a);
		a_len--;
	}
	sort3(a);
	b_len = stack_len(*b);
	while (b_len > 0)
	{
		move_init_b2a(a, b);
		b_len--;
	}
}
