/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:21:23 by mawad             #+#    #+#             */
/*   Updated: 2023/10/30 22:09:13 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*trav;

	if (*head == NULL)
		return ;
	trav = (*head)->next;
	if (trav == NULL)
		return ;
	(*head)->next = trav->next;
	trav->next = *head;
	*head = trav;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
