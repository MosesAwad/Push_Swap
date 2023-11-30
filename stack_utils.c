/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:20:44 by mawad             #+#    #+#             */
/*   Updated: 2023/10/28 21:22:20 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack *head)
{
	t_stack	*min;
	t_stack	*trav;

	trav = head;
	min = head;
	while (trav != NULL)
	{
		if (trav->data < min->data)
			min = trav;
		trav = trav->next;
	}
	return (min);
}

int	stack_len(t_stack *head)
{
	int		count;
	t_stack	*trav;

	count = 0;
	trav = head;
	while (trav != NULL)
	{
		count++;
		trav = trav->next;
	}
	return (count);
}
