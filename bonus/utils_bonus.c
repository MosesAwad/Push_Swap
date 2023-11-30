/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:20:04 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 19:44:04 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	result;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	result = *s1 - *s2;
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		slen;
	char	*buffer;
	int		i;

	slen = ft_strlen(s);
	buffer = (char *) malloc((slen + 1) * sizeof(*buffer));
	i = 0;
	if (buffer == NULL)
		return (NULL);
	while (s[i])
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
