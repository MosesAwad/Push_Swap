/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:50:10 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:28:20 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sep(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static void	free_bird(char **array, int k)
{
	int	i;

	i = 0;
	while (i < k)
		free(array[i++]);
	free(array);
}

int	count_args(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_sep(str[i]) && str[i])
			i++;
		if (!is_sep(str[i]) && str[i])
			count++;
		while (!is_sep(str[i]) && str[i])
			i++;
	}
	return (count);
}

static int	array_spawn(char **array, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		if (is_sep(str[i]))
		{
			i++;
			continue ;
		}
		while (!is_sep(str[i + j]) && str[i + j])
			j++;
		array[k] = (char *)malloc(sizeof(char) * (j + 1));
		if (!array[k])
			return (free_bird(array, k), 0);
		ft_strlcpy(array[k++], str + i, j + 1);
		i = i + j;
	}
	return (1);
}

char	**ft_split(char *str)
{
	int		count;
	char	**buffer;

	if (str == NULL)
		return (NULL);
	count = count_args(str);
	buffer = (char **)malloc(sizeof(*buffer) * (count + 1));
	if (buffer == NULL)
		return (NULL);
	if (array_spawn(buffer, str) == 0)
		return (NULL);
	buffer[count] = NULL;
	return (buffer);
}
