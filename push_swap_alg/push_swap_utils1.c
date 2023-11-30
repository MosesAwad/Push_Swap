/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:26:40 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:27:38 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_stack *head)
{
	int	index;
	int	median;

	index = 0;
	if (stack_len(head) == 2)
		median = 1;
	else
		median = (stack_len(head) / 2) + 1;
	while (head != NULL)
	{
		head->index = index;
		if (index < median)
			head->above_median = 1;
		else
			head->above_median = 0;
		index++;
		head = head->next;
	}
}

void	set_cheapest(t_stack *head)
{
	t_stack	*min_stack;
	t_stack	*trav;

	min_stack = head;
	trav = head;
	while (trav != NULL)
	{
		if (trav->price < min_stack->price)
			min_stack = trav;
		trav = trav->next;
	}
	while (head != NULL)
	{
		if (head == min_stack)
			head->cheapest = 1;
		else
			head->cheapest = 0;
		head = head->next;
	}
}

static int	price_helper1(t_stack *src)
{
	if ((src->above_median && src->target_node->above_median))
	{
		if (src->index && src->target_node->index)
		{
			src->price = 0;
			while ((src->index - src->price)
				&& (src->target_node->index - src->price))
				src->price++;
			if (!(src->index - src->price)
				&& (src->target_node->index - src->price))
				src->price += src->target_node->index - src->price;
			else if ((src->index - src->price)
				&& !(src->target_node->index - src->price))
				src->price += src->index - src->price;
			return (1);
		}
		else if (!src->index && !src->target_node->index)
		{
			src->price = 1;
			return (1);
		}
	}
	return (0);
}

static int	price_helper2(t_stack *src, int len_dest, int len_src)
{
	if ((!src->above_median && !src->target_node->above_median))
	{
		if ((len_src - src->index > 1)
			&& (len_dest - src->target_node->index > 1))
		{
			src->price = 0;
			while ((len_src - (src->index + src->price))
				&& (len_dest - (src->target_node->index + src->price)))
				src->price++;
			if (!(len_src - (src->index + src->price))
				&& (len_dest - (src->target_node->index + src->price)))
				src->price += len_dest - (src->target_node->index + src->price);
			else if ((len_src - (src->index + src->price))
				&& !(len_dest - (src->target_node->index + src->price)))
				src->price += len_src - (src->index + src->price);
			return (1);
		}
		else if ((len_src - src->index == 1)
			&& (len_dest - src->target_node->index == 1))
		{
			src->price = 1;
			return (1);
		}
	}
	return (0);
}

void	set_price(t_stack *dest, t_stack *src)
{
	int	len_dest;
	int	len_src;

	len_dest = stack_len(dest);
	len_src = stack_len(src);
	while (src != NULL)
	{
		if (!price_helper1(src)
			&& !price_helper2(src, len_dest, len_src))
		{
			src->price = src->index;
			if (!src->above_median)
				src->price = len_src - src->index;
			if (src->target_node->above_median == 1)
				src->price += src->target_node->index;
			else
				src->price += len_dest - src->target_node->index;
		}
		src = src->next;
	}
}
