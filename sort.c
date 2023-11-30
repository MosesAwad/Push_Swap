/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:54 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 19:34:02 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(t_stack *src_node, t_stack *head_dest)
{
	t_stack	*trav;
	int		bool;

	bool = 1;
	trav = head_dest;
	while (trav != NULL)
	{
		if (trav->data < src_node->data)
		{
			bool = 0;
			return (bool);
		}
		trav = trav->next;
	}
	return (bool);
}

int	is_max(t_stack *src_node, t_stack *head_dest)
{
	t_stack	*trav;
	int		bool;

	bool = 1;
	trav = head_dest;
	while (trav != NULL)
	{
		if (trav->data > src_node->data)
		{
			bool = 0;
			return (bool);
		}
		trav = trav->next;
	}
	return (bool);
}

t_stack	*find_max(t_stack *head)
{
	t_stack	*trav;
	t_stack	*max;

	trav = head;
	max = head;
	while (trav != NULL)
	{
		if (trav->data > max->data)
		{
			max = trav;
		}
		trav = trav->next;
	}
	return (max);
}

void	sort2(t_stack **a)
{
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort3(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if ((*a)->data == max->data)
		ra(a);
	else if ((*a)->next->data == max->data)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}
