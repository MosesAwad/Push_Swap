/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:21:23 by mawad             #+#    #+#             */
/*   Updated: 2023/11/25 19:32:40 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	swap(t_stack **head)
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
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
