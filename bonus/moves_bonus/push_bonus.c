/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:30:24 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:40:54 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	push(t_stack **dhead, t_stack **shead)
{
	t_stack	*transfer;

	if ((*shead) == NULL)
		return ;
	transfer = *shead;
	*shead = (*shead)->next;
	transfer->next = *dhead;
	*dhead = transfer;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
}
