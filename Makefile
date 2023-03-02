# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 13:35:32 by salee2            #+#    #+#              #
#    Updated: 2023/02/28 19:38:23 by doohkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
LIBFT_DIR	= ./libft
LIBFT_FILE	= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RL_LIB		= -lreadline -L$(HOME)/.brew/opt/readline/lib
RL_HEADER	= -I$(HOME)/.brew/opt/readline/include
RM			= rm -f

BUILTIN_SRCS = \
	builtin_cd \
	builtin_echo \
	builtin_env \
	builtin_exit \
	builtin_export_utils \
	builtin_export \
	builtin_pwd \
	builtin_unset \
	create_env_list \
	create_new_envp \
	env_list_insert \
	env_list_utils \
	env_list \

ERROR_N_DEBUG_SRCS = \
	debug \
	error \

EXECUTE_PART_SRCS = \
	argv \
	builtin \
	cmd_suffix \
	complete_command \
	dup \
	execve \
	fork \
	get_executable_file_list \
	heredoc \
	mktemp \
	open \
	pipeline \
	redirect_list \
	redirect_pipe \
	redirect_stdio \
	simple_command \
	subshell \

EXPANSION_SRCS = \
	env_expansion \
	env_expansion_util \
	quote_expansion \
	expansion

GARBAGE_COLLECTOR_SRCS = \
	token_collector \
	tree_collector \

LEXER_SRCS = \
	token \
	token_and_or_pipe \
	token_create \
	token_io \
	token_quote \
	token_split \
	token_subshell \
	token_word \

MAIN_SRCS = \
	main_utils \
	main \
	set_signal \

PARSER_SRCS =\
	parser_argv \
	parser_cmd_name \
	parser_cmd_suffix \
	parser_complete_cmd \
	parser_io_redirect \
	parser_list \
	parser_pipeline \
	parser_redirect_list \
	parser_simple_cmd \
	parser_subshell \
	parser_suffix \
	parser_util \
	tree \

SRCS = \
	$(addsuffix .c, $(addprefix builtin/, $(BUILTIN_SRCS))) \
	$(addsuffix .c, $(addprefix error_n_debug/, $(ERROR_N_DEBUG_SRCS))) \
	$(addsuffix .c, $(addprefix execute_part/, $(EXECUTE_PART_SRCS))) \
	$(addsuffix .c, $(addprefix expansion/, $(EXPANSION_SRCS))) \
	$(addsuffix .c, $(addprefix garbage_collector/, $(GARBAGE_COLLECTOR_SRCS))) \
	$(addsuffix .c, $(addprefix lexer/, $(LEXER_SRCS))) \
	$(addsuffix .c, $(addprefix main/, $(MAIN_SRCS))) \
	$(addsuffix .c, $(addprefix parser/, $(PARSER_SRCS))) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(RL_LIB) -o $@ $^ $(LIBFT_DIR)/$(LIBFT_FILE)

%o: %c
	$(CC) $(CFLAGS) $(RL_HEADER) -c -o $@ $<

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(LIBFT_FILE)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
