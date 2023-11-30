/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:22:19 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:26:39 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack *a)
{
	t_stack	*trav;

	trav = a;
	while (trav != NULL)
	{
		if ((trav->next != NULL) && (trav->data > trav->next->data))
			return (0);
		trav = trav->next;
	}
	return (1);
}

void	final_rotation(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	set_index(*a);
	while (min->index != 0)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
		set_index(*a);
	}
}

void	destroy_stack(t_stack *head)
{
	if (head != NULL)
		destroy_stack(head->next);
	free(head);
}

int	main(int argc, char *argv[])
{
	long long int	*numbers;
	int				size;
	t_stack			*stack_a;
	t_stack			*stack_b;

	size = 0;
	numbers = get_numbers(argc, argv, &size);
	if (parser(numbers, size) != 1 || !numbers)
		return (free(numbers), 1);
	stack_a = stack_spawn(numbers, size);
	stack_b = NULL;
	if (size == 2)
		return (sort2(&stack_a), destroy_stack(stack_a), free(numbers), 1);
	if (check_stack(stack_a))
		return (destroy_stack(stack_a), free(numbers), 1);
	push_swap(&stack_a, &stack_b);
	final_rotation(&stack_a);
	destroy_stack(stack_a);
	free(numbers);
}
