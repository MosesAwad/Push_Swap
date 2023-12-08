/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:19:13 by mawad             #+#    #+#             */
/*   Updated: 2023/12/05 17:28:24 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_fprintf_bonus/ft_fprintf_bonus.h"

typedef struct s_stack
{
	int				data;
	int				cheapest;
	int				price;
	int				index;
	int				above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

//stack_spawn_bonus.c
t_stack			*stack_spawn(long long int *numbers, int size);

//stack_utils_bonus.c
t_stack			*find_min(t_stack *head);
int				stack_len(t_stack *head);

//utils_bonus.c
char			*ft_strdup(const char *s);
int				ft_strcmp(char *s1, char *s2);

//get_next_line_bonus.c
char			*get_next_line(int fd);
int				nb_check(int nb_read, char *line, char *buffer);
char			*ft_strjoin(char *s1, const char *s2);

//check_moves_bonus.c
int				execute_moves(t_stack **a, t_stack **b);

//parse_utils_bonus.c
int				check_duplicates(long long int *array, int size);
int				check_out_of_range(long long int *numbers, int size);
size_t			ft_strlcpy(char *dest, char *src, size_t size);

//parse_extraction_bonus.c
long long int	*extract_numbers(char **array, int *size);
int				check_numeric(char **arguments);
int				check_only_signs(char **arguments);
long long int	*get_numbers(int argc, char *argv[], int *size);

//parse_bonus.c
int				parser(long long int *numbers, int size);

//join_args_bonus.c
char			*join_args(int argc, char *argv[]);

//ft_split_bonus.c
int				count_args(char *str);
char			**ft_split(char *str);

//ft_atoi_bonus.c
long long int	ft_atoi(const char *nptr);

//swap_bonus.c
void			swap(t_stack **head);
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

//rotate_bonus.c
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);

//rev_rotate_bonus.c
void			rrr(t_stack **a, t_stack **b);
void			rrb(t_stack **b);
void			rra(t_stack **a);

//push_bonus.c
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

#endif