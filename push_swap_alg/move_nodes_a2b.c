/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes_a2b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:57:33 by mawad             #+#    #+#             */
/*   Updated: 2023/11/22 16:44:10 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_mode(t_stack *cheap, t_stack **b, t_stack **a)
{
	if (cheap->above_median && cheap->target_node->above_median)
		rr(a, b);
	else if (!cheap->above_median && !cheap->target_node->above_median)
		rrr(a, b);
	else if (cheap->above_median && !cheap->target_node->above_median)
	{
		ra(a);
		rrb(b);
	}
	else if (!cheap->above_median && cheap->target_node->above_median)
	{
		rra(a);
		rb(b);
	}
	set_index(*a);
	set_index(*b);
}

static void	finish_rotation(t_stack *cheap, t_stack **b, t_stack **a)
{
	if (cheap->index && !(cheap)->target_node->index)
	{
		while (cheap->index)
		{
			if (cheap->above_median)
				ra(a);
			else
				rra(a);
			set_index(*a);
		}
	}
	else if (!cheap->index && (cheap)->target_node->index)
	{
		while (cheap->target_node->index)
		{
			if (cheap->target_node->above_median)
				rb(b);
			else
				rrb(b);
			set_index(*b);
		}
	}
}

void	move_nodes_a2b(t_stack **b, t_stack **a)
{
	t_stack	*head_copy;
	t_stack	*cheap;

	head_copy = *a;
	while ((*a)->cheapest == 0 && (*a) != NULL)
		*a = (*a)->next;
	cheap = *a;
	*a = head_copy;
	while (cheap->index && cheap->target_node->index)
		rotate_mode(cheap, b, a);
	if ((cheap)->index || (cheap)->target_node->index)
		finish_rotation(cheap, b, a);
	set_index(*a);
	set_index(*b);
}
