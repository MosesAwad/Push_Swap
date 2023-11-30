/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:10:38 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:28:24 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_strjoin_local(char *s1, const char *s2)
{
	static int	call_count;
	char		*str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (call_count++)
		free(s1);
	str[i++] = ' ';
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*join_args(int argc, char *argv[])
{
	int		i;
	char	*join_res;

	if (argc == 1)
		return (NULL);
	if (argc == 2)
		return (argv[1]);
	i = 2;
	join_res = ft_strjoin_local(argv[i - 1], argv[i]);
	i++;
	while (i < argc)
	{
		join_res = ft_strjoin_local(join_res, argv[i]);
		i++;
	}
	return (join_res);
}
