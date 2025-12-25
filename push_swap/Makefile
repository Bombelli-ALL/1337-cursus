# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerradi <alerradi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 20:29:53 by alerradi          #+#    #+#              #
#    Updated: 2025/12/21 01:38:14 by alerradi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
NAME_CHECK	= checker
CC      = cc

CFLAGS  = -Wall -Wextra -Werror -I Sourcs

RM      = rm -f

SRC_DIR = Sourcs
SRC_CHECK_DIR = Sourcs_checker

SRCS    = $(SRC_DIR)/sort_digits.c \
          $(SRC_DIR)/check_nums.c \
          $(SRC_DIR)/fill_array.c \
          $(SRC_DIR)/push_swap.c \
		  $(SRC_DIR)/rules1.c \
          $(SRC_DIR)/rules.c  \
          $(SRC_DIR)/libft.c \
          $(SRC_DIR)/help.c


SRCS_CHECK   =	$(SRC_CHECK_DIR)/get_next_line_utils.c \
				$(SRC_CHECK_DIR)/get_next_line.c \
				$(SRC_CHECK_DIR)/checker.c \
        		$(SRC_CHECK_DIR)/check_nums.c \
        		$(SRC_CHECK_DIR)/fill_array.c \
				$(SRC_CHECK_DIR)/rules1.c \
        		$(SRC_CHECK_DIR)/rules.c  \
        		$(SRC_CHECK_DIR)/libft.c 
		  
OBJS    = $(SRCS:.c=.o)
OBJS_CHECK    = $(SRCS_CHECK:.c=.o)

INCLUDES    = -I $(SRC_DIR)
INCLUDES_BONUS = -I $(SRC_CHECK_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_CHECK)
	
$(NAME_CHECK): $(OBJS_CHECK)
	$(CC) $(CFLAGS) $(OBJS_CHECK) -o $(NAME_CHECK)

$(SRC_CHECK_DIR)/%.o: $(SRC_CHECK_DIR)/%.c $(SRC_CHECK_DIR)/checker.h $(SRC_CHECK_DIR)/get_next_line.h
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_CHECK)

fclean: clean
	$(RM) $(NAME) $(NAME_CHECK)

re: fclean all

.PHONY: all clean fclean re bonus