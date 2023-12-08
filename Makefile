# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mawad <mawad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 18:22:09 by mawad             #+#    #+#              #
#    Updated: 2023/12/05 20:19:08 by mawad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c sort.c stack_utils.c stack_spawn.c


PUSH_SWAP_DIR = push_swap_alg
PUSH_SWAP_SRCS = $(addprefix $(PUSH_SWAP_DIR)/, push_swap.c push_swap_utils1.c push_swap_utils2.c move_nodes_a2b.c move_nodes_b2a.c)

MOVES_DIR = moves
MOVES_SRCS = $(addprefix $(MOVES_DIR)/, push.c rev_rotate.c rotate.c swap.c)

PARSE_DIR = parse
PARSE_SRCS = $(addprefix $(PARSE_DIR)/, join_args.c ft_split.c ft_atoi.c parse_utils.c parse_extraction.c parse.c)

FT_FPRINTF_DIR = ft_fprintf
FT_FPRINTF_SRCS = $(addprefix $(FT_FPRINTF_DIR)/, ft_print_address.c ft_print_hex.c ft_print_nbr.c ft_print_unsigned.c ft_fprintf_utils.c \
					ft_fprintf.c)


BONUS_DIR = bonus
BONUS_SRCS = $(addprefix $(BONUS_DIR)/, utils_bonus.c main_bonus.c get_next_line_bonus.c stack_utils_bonus.c stack_spawn_bonus.c check_moves_bonus.c)

BONUS_MOVES_DIR = bonus/moves_bonus
BONUS_MOVES_SRCS = $(addprefix $(BONUS_MOVES_DIR)/, push_bonus.c rev_rotate_bonus.c rotate_bonus.c swap_bonus.c)

BONUS_PARSE_DIR = bonus/parse_bonus
BONUS_PARSE_SRCS = $(addprefix $(BONUS_PARSE_DIR)/, ft_atoi_bonus.c ft_split_bonus.c join_args_bonus.c parse_bonus.c parse_extraction_bonus.c \
					parse_utils_bonus.c)

BONUS_FT_FPRINTF_DIR = bonus/ft_fprintf_bonus
BONUS_FT_FPRINTF_SRCS = $(addprefix $(BONUS_FT_FPRINTF_DIR)/, ft_print_address_bonus.c ft_print_hex_bonus.c ft_print_nbr_bonus.c ft_print_unsigned_bonus.c \
						ft_fprintf_utils_bonus.c ft_fprintf_bonus.c)


OBJS = $(SRCS:.c=.o)
PUSH_SWAP_OBJS = $(PUSH_SWAP_SRCS:.c=.o)
MOVES_OBJS = $(MOVES_SRCS:.c=.o)
PARSE_OBJS = $(PARSE_SRCS:.c=.o)
FT_FPRINTF_OBJS = $(FT_FPRINTF_SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_MOVES_OBJS = $(BONUS_MOVES_SRCS:.c=.o)
BONUS_PARSE_OBJS = $(BONUS_PARSE_SRCS:.c=.o)
BONUS_FT_FPRINTF_OBJS = $(BONUS_FT_FPRINTF_SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(PUSH_SWAP_OBJS) $(MOVES_OBJS) $(PARSE_OBJS) $(FT_FPRINTF_OBJS)
	$(CC) $(OBJS) $(PUSH_SWAP_OBJS) $(MOVES_OBJS) $(PARSE_OBJS) $(FT_FPRINTF_OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@



bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(BONUS_MOVES_OBJS) $(BONUS_PARSE_OBJS) $(BONUS_FT_FPRINTF_OBJS)
	$(CC) $(BONUS_OBJS) $(BONUS_MOVES_OBJS) $(BONUS_PARSE_OBJS) $(BONUS_FT_FPRINTF_OBJS) -o $(BONUS_NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@



clean:
	rm -f $(OBJS) $(PUSH_SWAP_OBJS) $(MOVES_OBJS) $(PARSE_OBJS) $(FT_FPRINTF_OBJS) $(BONUS_OBJS) $(BONUS_MOVES_OBJS) $(BONUS_PARSE_OBJS) $(BONUS_FT_FPRINTF_OBJS)


fclean: clean
	rm -f $(NAME) $(BONUS_NAME)


re: fclean all


rebonus: fclean bonus


.PHONY: all clean fclean re bonus rebonus