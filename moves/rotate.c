/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:19:03 by mawad             #+#    #+#             */
/*   Updated: 2023/11/25 19:54:24 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*head_copy;
	t_stack	*new_head;
	int		len;

	if (*head == NULL)
		return ;
	len = stack_len(*head);
	if (len == 1)
		return ;
	new_head = (*head)->next;
	head_copy = *head;
	while ((*head)->next != NULL)
	{
		(*head) = (*head)->next;
	}
	(*head)->next = head_copy;
	(*head)->next->next = NULL;
	*head = new_head;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
