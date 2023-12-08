/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:18:32 by mawad             #+#    #+#             */
/*   Updated: 2023/12/07 16:17:31 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_stacks(t_stack *a, t_stack *b)
{
	t_stack	*trav;

	trav = a;
	while (trav != NULL)
	{
		if ((trav->next != NULL) && (trav->data > trav->next->data))
			return (0);
		trav = trav->next;
	}
	if (b != NULL)
		return (1);
	return (2);
}

void	destroy_stack(t_stack *head)
{
	if (head != NULL)
		destroy_stack(head->next);
	free(head);
}

void	destroy_helper(t_stack *a, long long int *numbers)
{
	destroy_stack(a);
	free(numbers);
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
	if (!execute_moves(&stack_a, &stack_b))
		return (destroy_helper(stack_a, numbers), destroy_stack(stack_b), 1);
	if (check_stacks(stack_a, stack_b) != 2)
	{
		ft_fprintf(1, "KO\n");
		destroy_stack(stack_b);
	}
	else
		ft_fprintf(1, "OK\n");
	return (destroy_stack(stack_a), free(numbers), 0);
}
