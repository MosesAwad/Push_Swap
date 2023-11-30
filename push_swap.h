/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawad <mawad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:19:13 by mawad             #+#    #+#             */
/*   Updated: 2023/11/24 23:37:17 by mawad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/ft_printf.h"

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

//checker_get_next_line.c
char			*get_next_line(int fd);

//checker_moves.c
int				execute_moves(t_stack **a, t_stack **b);

//checker_utils.c
int				ft_strcmp(char *s1, char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);

//parse.c
int				parser(long long int *numbers, int size);

//parse_utils.c
size_t			ft_strlcpy(char *dest, char *src, size_t size);
int				check_duplicates(long long int *array, int size);
int				check_out_of_range(long long int *numbers, int size);

//ft_split.c
char			**ft_split(char *str);
int				count_args(char *str);

//ft_atoi.c
long long int	ft_atoi(const char *nptr);

//parse_extraction.c
long long int	*extract_numbers(char **array, int *size);
int				check_numeric(char **arguments);
int				check_only_signs(char **arguments);
long long int	*get_numbers(int argc, char *argv[], int *size);

//join_args.c
size_t			ft_strlen(const char *s);
char			*join_args(int argc, char *argv[]);

//stack_spawn.c
t_stack			*stack_spawn(long long int *numbers, int size);

//print_checks.c
void			print_stack(t_stack *head);
void			pro_print_stack(t_stack *head);
void			print_both(t_stack *a, t_stack *b);
void			print_price(t_stack *head);
void			print_index(t_stack *head);
void			print_targets(t_stack *b);
void			print_cheapest(t_stack *b);

//move_nodes
void			move_nodes_b2a(t_stack **a, t_stack **b);
void			move_nodes_a2b(t_stack **b, t_stack **a);

//push_swap.c
void			push_swap(t_stack **a, t_stack **b);

//push_swap_utils1.c
void			set_index(t_stack *head);
void			set_price(t_stack *dest, t_stack *src);
void			set_cheapest(t_stack *head);

//push_swap_utils2.c
void			target_finder1(t_stack *dest, t_stack *src);
void			target_finder2(t_stack *dest, t_stack *src);

//swap.c
void			sa(t_stack **a);
void			sb(t_stack **b);
void			ss(t_stack **a, t_stack **b);

//push.c
void			pa(t_stack **a, t_stack **b);
void			pb(t_stack **b, t_stack **a);

//rotate.c
void			ra(t_stack **a);
void			rb(t_stack **b);
void			rr(t_stack **a, t_stack **b);

//rev_rotate.c
void			rra(t_stack **a);
void			rrb(t_stack **b);
void			rrr(t_stack **a, t_stack **b);

//sort.c
int				is_min(t_stack *src_node, t_stack *head_dest);
int				is_max(t_stack *src_node, t_stack *head_dest);
t_stack			*find_max(t_stack *head);
void			sort2(t_stack **a);
void			sort3(t_stack **head);

//stack_utils.c
t_stack			*find_min(t_stack *head);
int				stack_len(t_stack *head);

#endif