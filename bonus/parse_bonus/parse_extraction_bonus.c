/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extraction_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:57:22 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:34:46 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

long long int	*extract_numbers(char **array, int *size)
{
	long long int	*buffer;
	int				i;

	i = 0;
	while (array[i] != NULL)
		i++;
	*size = i;
	buffer = (long long int *)malloc(sizeof(*buffer) * i);
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (array[i] != NULL)
	{
		buffer[i] = ft_atoi(array[i]);
		free(array[i]);
		i++;
	}
	free(array);
	return (buffer);
}

int	check_numeric(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j])
		{
			if (!(arguments[i][j] >= '0' && arguments[i][j] <= '9')
				&& arguments[i][j] != '-' && arguments[i][j] != '+')
			{
				i = 0;
				while (arguments[i] != NULL)
					free(arguments[i++]);
				free(arguments);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_only_signs(char **arguments)
{
	int	i;
	int	j;

	i = 0;
	while (arguments[i])
	{
		j = 0;
		while (arguments[i][j] == '-' || arguments[i][j] == '+')
		{
			if (!(arguments[i][j + 1] >= '0' && arguments[i][j + 1] <= '9'))
			{
				i = 0;
				while (arguments[i] != NULL)
					free(arguments[i++]);
				free(arguments);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long long int	*get_numbers(int argc, char *argv[], int *size)
{
	char			*result;
	char			**arguments;
	long long int	*digits;

	result = join_args(argc, argv);
	if (result == NULL)
		return (NULL);
	arguments = ft_split(result);
	if (!arguments)
		return (NULL);
	if (argc > 2)
		free(result);
	if (check_numeric(arguments) == 0)
		return (ft_printf("Error\nNon-numeric character present"), NULL);
	if (check_only_signs(arguments) == 1)
		return (ft_printf("Error\nSign must be followed by digit"), NULL);
	digits = extract_numbers(arguments, size);
	return (digits);
}
