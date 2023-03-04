/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedef.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:13:32 by doohkim           #+#    #+#             */
/*   Updated: 2023/03/01 15:18:16 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEF_H
# define MINISHELL_TYPEDEF_H

typedef struct termios	t_term;
typedef int				t_bool;

enum e_pipe_fds
{
	READ_FD = 0,
	WRITE_FD = 1,
};

enum e_bool
{
	FALSE,
	TRUE
};

enum e_system
{
	ERROR = -1,
	SUCCESS = 0,
};

enum e_file
{
	DIR = 1,
};

enum e_strcmp
{
	SAME = 0,
};

enum e_fork
{
	CHILD = 0,
};

enum e_builtin
{
	B_ECHO = 1,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

typedef enum e_token_type
{
	WORD = 0,
	SGL_IN,
	DB_IN,
	SGL_OUT,
	DB_OUT,
	PIPE,
	AND_IF,
	OR_IF,
	START_SUB,
	END_SUB
}	t_tkn_type;

typedef enum e_parse_type
{
	COMPLETE_CMD = 0,
	LIST,
	AND_IF_LIST,
	OR_IF_LIST,
	PIPELINE,
	SUBSHELL,
	SIMPLE_CMD,
	REDIRECT_LIST,
	CMD_SUFFIX,
	SUFFIX,
	IO_REDIRECT,
	ARGV,
	CMD_NAME
}	t_pt;

typedef struct s_file_descriptor
{
	int	std_in;
	int	std_out;
}	t_fd;

typedef struct s_token
{
	t_tkn_type		tkn_tp;
	char			*str;
	struct s_token	*next;
	struct s_token	*clt_next;
}	t_tkn;

typedef struct s_parse_tree
{
	t_pt				pst_pt;
	t_tkn				*list_tkn;
	struct s_parse_tree	*left;
	struct s_parse_tree	*right;
	struct s_parse_tree	*clt_next;
}	t_pst;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env;

typedef struct s_global
{
	t_env	*envp_list;
	t_term	term;
	int		is_child;
	int		exit_status;
	int		pipe_level;
}	t_global;

#endif