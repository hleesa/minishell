/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:01:23 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/26 20:21:16 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "./minishell_include.h"
# include "./minishell_define.h"
# include "./minishell_typedef.h"

t_global	g_gb;
extern char	**environ;

int		set_signal(int is_status);
int		set_term(int init, int is_status);

void	input_eof(void);
int		input_cmd(char *r_line, t_tkn **list_tkn, t_pst **parse_tree);
int		global_init(void);
int		main_init(void);
void	after_cmd(void);

char	**ft_split(char const *s, char c);

int		tkn_size(t_tkn *tkn_list);
t_tkn	*tkn_new(t_tkn_type tkn_tp, char *str);
t_tkn	*tkn_last(t_tkn *list_tkn);
void	tkn_add_back(t_tkn **list_tkn, t_tkn *new_tkn);
t_tkn	*tkn_search(t_tkn *list_tkn, t_tkn_type tkn_tp);

int		token_create(char **str, t_tkn **list_tkn, int len, t_tkn_type tkn_tp);

int		token_word(char **str, t_tkn **list_tkn, int *len);
int		token_input(char **str, t_tkn **list_tkn, int *len);
int		token_output(char **str, t_tkn **list_tkn, int *len);
int		token_or_pipe(char **str, t_tkn **list_tkn, int *len);
int		token_and(char **str, t_tkn **list_tkn, int *len);
int		token_single_quote(char **str, t_tkn **list_tkn, int *len);
int		token_double_quote(char **str, t_tkn **list_tkn, int *len);
int		token_start_sub(char **str, t_tkn **list_tkn, int *len);
int		token_end_sub(char **str, t_tkn **list_tkn, int *len);

int		token_split(char *str, t_tkn **list_tkn);

t_pst	*new_parse_node(t_pt pt);

int		check_redirect_token(t_tkn *list_tkn);

int		ps_complete_cmd(t_pst **tree, t_tkn **list_tkn);
int		ps_list(t_pst **tree, t_tkn **list_tkn, t_pt node_type);
int		ps_pipeline(t_pst **tree, t_tkn **list_tkn);
int		ps_cmd_list(t_pst **tree, t_tkn **list_tkn);
int		ps_subshell(t_pst **tree, t_tkn **list_tkn);
int		ps_simple_cmd(t_pst **tree, t_tkn **list_tkn);
int		ps_cmd_suffix(t_pst **tree, t_tkn **list_tkn);
int		ps_cmd_name(t_pst **tree, t_tkn **list_tkn);
int		ps_suffix(t_pst **tree, t_tkn **list_tkn);
int		ps_argv(t_pst **tree, t_tkn **list_tkn);
int		ps_redirect_list(t_pst **tree, t_tkn **list_tkn);
int		ps_io_redirect(t_pst **tree, t_tkn **list_tkn);

int		ft_strichr(char find_c, char *str);
char	*get_env_value(char *env_str);
char	*token_str_replace_env(t_tkn *tkn, char *env_str, int s_idx, int e_idx);
int		replace_status(t_tkn *tkn, int s_idx, int e_idx);
int		replace_env(t_tkn *tkn, int s_idx, int e_idx);

int		env_expansion(t_tkn *list_tkn);
int		quote_expansion(t_tkn *list_tkn);
int		expansion(t_tkn *list_tkn);

int		token_collector(t_tkn *token);

int		tree_collector(t_pst *node);

int		ft_lexer_error(char *str, char *token);
int		ft_parse_error(char *str, t_tkn *token, int not_tkn);
int		ft_malloc_error(void);
void	heredoc_input_eof(int c_line, char *eof);

void	print_token(t_tkn *list_tkn);
void	print_tree(t_pst *tree, int n);

int		check_export_env(char *argv);
int		check_append(char *env_str);
int		append_env(t_env **env_list, char *env_str, int is_append);
int		export_env(t_env **env_list, char *env_str, int is_append);

t_env	*new_env_node(char *env_str, int is_append);
t_env	*create_env_list(char **old_envp);
void	delete_env(t_env *env);
void	env_list_clear(t_env **env_list);
int		env_list_size(t_env *env_list);

int		builtin_cd(char **argv);
int		builtin_echo(char **argv);
int		builtin_env(void);
int		builtin_exit(char **argv);
int		builtin_export(char **argv);
int		builtin_pwd(void);
int		builtin_unset(char **argv);
char	**envp_clear(char **new_envp);
char	**create_new_envp(void);
void	env_search_insert(t_env **env_list, t_env *env_node);
int		ft_key_len(char *env);
char	*ft_key_str(char *env);
char	*ft_value_str(char *env, int is_append);
char	*builtin_getenv(char *key);
t_env	*env_list_search_key(t_env *env_list, char *env_str);

char	**clear_argv(char **argv);
char	**create_argv(t_tkn *cmd_list);
int		get_builtin_enum(char *cmd);
void	execute_builtin(int builtin_enum, t_tkn *cmd_list);
int		execute_cmd_suffix(t_pst *tree, t_tkn **cmd_list);
void	execute_list(t_pst *tree);
void	execute_complete_list(t_pst *tree);
void	dup2_exit_if_error(int fildes, int fildes2);
int		dup_exit_if_error(int fildes);
int		exit_if_open_error(int fd, char *path);
void	execute_execve(t_tkn *cmd_list);
char	*ft_getenv(const char *name, char **env);
char	**get_executable_file_list(const char *name, char *file_name, \
char **env);
int		execute_heredoc(t_pst *tree);
void	write_heredoc(t_pst *tree);
char	*ft_mktemp(void);
pid_t	fork_exit_if_error(void);
void	mkpipe(int *pipe_fds);
void	execute_pipe(t_pst *tree);
void	execute_pipeline(t_pst *tree);
int		execute_io_redirect(t_pst *tree);
int		execute_redirect_list(t_pst *tree);
int		execute_suffix(t_pst *tree, t_tkn **cmd_list);
void	redirect_w_pipe_to_stdout(int *pipe_fds);
void	redirect_r_pipe_to_stdin(int *pipe_fds);
int		redirect_stdin_to_file(char *path);
int		redirect_stdout_to_file(char *path);
int		redirect_stdout_to_file_append(char *path);
int		execute_pre_simple_command(t_pst *tree, t_tkn **cmd_list);
void	execute_simple_command(t_pst *tree);
void	execute_subshell(t_pst *tree);

#endif