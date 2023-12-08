/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:06:31 by mawad             #+#    #+#             */
/*   Updated: 2023/12/05 17:30:25 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FPRINTF_BONUS_H
# define FT_FPRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_print_hex(int fd, unsigned int c, char frmt);
int		ft_print_nbr(int fd, int nb);
int		ft_print_address(int fd, unsigned long long int c);
int		ft_print_unsigned(int fd, unsigned int nb);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, char *str);
int		ft_fprintf(int fd, const char *placeholders, ...);

#endif