/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:18:08 by mawad             #+#    #+#             */
/*   Updated: 2023/11/25 19:55:26 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*head_copy;
	t_stack	*last_copy;
	int		len;

	if (*head == NULL)
		return ;
	len = stack_len(*head);
	if (len == 1)
		return ;
	head_copy = *head;
	while ((*head)->next->next != NULL)
	{
		*head = (*head)->next;
	}
	last_copy = (*head)->next;
	(*head)->next = NULL;
	(*head) = last_copy;
	(*head)->next = head_copy;
}

void	rra(t_stack **a)
{
	rev_rotate(a);
}

void	rrb(t_stack **b)
{
	rev_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
