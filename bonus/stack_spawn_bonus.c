/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_spawn_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 21:05:22 by mawad             #+#    #+#             */
/*   Updated: 2023/11/23 20:45:02 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	create_stack(t_stack **head, long long int *numbers, int i)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->data = numbers[i];
	node->next = *head;
	(*head) = node;
}

t_stack	*stack_spawn(long long int *numbers, int size)
{
	int		i;
	t_stack	*head;

	head = NULL;
	i = size - 1;
	while (i >= 0)
	{
		create_stack(&head, numbers, i);
		i--;
	}
	return (head);
}
