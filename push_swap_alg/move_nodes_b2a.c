/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes_b2a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:00:53 by mawad             #+#    #+#             */
/*   Updated: 2023/10/30 22:08:49 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_mode(t_stack *cheap, t_stack **a, t_stack **b)
{
	if (cheap->above_median && cheap->target_node->above_median)
		rr(a, b);
	else if (!cheap->above_median && !cheap->target_node->above_median)
		rrr(a, b);
	else if (cheap->above_median && !cheap->target_node->above_median)
	{
		rb(b);
		rra(a);
	}
	else if (!cheap->above_median && cheap->target_node->above_median)
	{
		rrb(b);
		ra(a);
	}
	set_index(*b);
	set_index(*a);
}

static void	finish_rotation(t_stack *cheap, t_stack **a, t_stack **b)
{
	if (cheap->index && !(cheap)->target_node->index)
	{
		while (cheap->index)
		{
			if (cheap->above_median)
				rb(b);
			else
				rrb(b);
			set_index(*b);
		}
	}
	else if (!cheap->index && (cheap)->target_node->index)
	{
		while (cheap->target_node->index)
		{
			if (cheap->target_node->above_median)
				ra(a);
			else
				rra(a);
			set_index(*a);
		}
	}
}

void	move_nodes_b2a(t_stack **a, t_stack **b)
{
	t_stack	*head_copy;
	t_stack	*cheap;

	head_copy = *b;
	while ((*b)->cheapest == 0 && (*b) != NULL)
		*b = (*b)->next;
	cheap = *b;
	*b = head_copy;
	while (cheap->index && cheap->target_node->index)
		rotate_mode(cheap, a, b);
	if ((cheap)->index || (cheap)->target_node->index)
		finish_rotation(cheap, a, b);
	set_index(*b);
	set_index(*a);
}
