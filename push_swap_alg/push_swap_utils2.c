/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:08:19 by mawad             #+#    #+#             */
/*   Updated: 2023/11/22 16:08:17 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	target_finder1(t_stack *dest, t_stack *src)
{
	t_stack	*dhead_copy;
	int		min;

	dhead_copy = dest;
	while (src != NULL)
	{
		min = -2147483648;
		dest = dhead_copy;
		if (is_max(src, dest) || is_min(src, dest))
			src->target_node = find_max(dest);
		else
		{
			while (dest != NULL)
			{
				if (src->data > dest->data && min < dest->data)
				{
					min = dest->data;
					src->target_node = dest;
				}
				dest = dest->next;
			}
		}
		src = src->next;
	}
}

void	target_finder2(t_stack *dest, t_stack *src)
{
	t_stack	*dhead_copy;
	int		max;

	dhead_copy = dest;
	while (src != NULL)
	{
		max = 2147483647;
		dest = dhead_copy;
		if (is_max(src, dest))
			src->target_node = find_min(dest);
		else
		{
			while (dest != NULL)
			{
				if (src->data < dest->data && max > dest->data)
				{
					max = dest->data;
					src->target_node = dest;
				}
				dest = dest->next;
			}
		}
		src = src->next;
	}
}
