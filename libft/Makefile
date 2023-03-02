# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 12:29:43 by salee2            #+#    #+#              #
#    Updated: 2023/02/07 17:53:56 by doohkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
GNL_DIR		= ./get_next_line
PERROR_DIR	= ./ft_perror

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_striteri.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	$(GNL_DIR)/get_next_line.c \
   	$(GNL_DIR)/get_next_line_utils.c \
   	$(GNL_DIR)/get_next_line_bonus.c \
   	$(GNL_DIR)/get_next_line_utils_bonus.c \
   	$(PERROR_DIR)/ft_csdiu.c \
   	$(PERROR_DIR)/ft_perror.c \
   	$(PERROR_DIR)/ft_pxp.c \
   	$(PERROR_DIR)/ft_utoa.c \

SRC_B= \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS_M = $(SRCS:.c=.o)
OBJS_B = $(OBJS_M) $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_M)
	ar rcs $@ $?

bonus: $(OBJS_B)
	make OBJS_M="$(OBJS_B)"

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS_M) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
