/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:30:24 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:41:19 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
