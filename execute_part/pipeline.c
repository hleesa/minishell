/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:03 by salee2            #+#    #+#             */
/*   Updated: 2023/02/26 16:40:58 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	mkpipe(int *pipe_fds)
{
	if (pipe(pipe_fds) == ERROR)
	{
		perror("pipe()");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	pipe_child(t_pst *tree, int *pipe_fds)
{
	t_tkn	*cmd_list;
	int		builtin_enum;

	if (set_signal(1))
		exit(ft_malloc_error());
	cmd_list = NULL;
	g_gb.is_child = 1;
	if (tree->right != NULL)
		redirect_w_pipe_to_stdout(pipe_fds);
	if (tree->left->pst_pt == SUBSHELL)
		execute_subshell(tree->left);
	else if (tree->left->pst_pt == SIMPLE_CMD)
	{
		if (execute_pre_simple_command(tree->left, &cmd_list))
			exit(EXIT_FAILURE);
		if (cmd_list == NULL)
			exit(EXIT_SUCCESS);
		builtin_enum = get_builtin_enum(cmd_list->str);
		if (builtin_enum != 0)
			execute_builtin(builtin_enum, cmd_list);
		else if (cmd_list != NULL)
			execute_execve(cmd_list);
	}
	exit(EXIT_SUCCESS);
}

void	pipe_parent(t_pst *tree, int *pipe_fds)
{
	redirect_r_pipe_to_stdin(pipe_fds);
	if (tree->right)
		execute_pipe(tree->right);
	wait(&g_gb.exit_status);
	if (WIFEXITED(g_gb.exit_status))
		g_gb.exit_status = WEXITSTATUS(g_gb.exit_status);
	else if (!tree->right && WIFSIGNALED(g_gb.exit_status))
	{
		if (g_gb.exit_status == SIGQUIT)
			printf("Quit: %d", g_gb.exit_status);
		g_gb.exit_status |= 128;
		printf("\n");
	}
	return ;
}

void	execute_pipe(t_pst *tree)
{
	pid_t	pid;
	int		pipe_fds[2];

	mkpipe(pipe_fds);
	pid = fork_exit_if_error();
	if (pid == CHILD)
		pipe_child(tree, pipe_fds);
	else
		pipe_parent(tree, pipe_fds);
	return ;
}

void	execute_pipeline(t_pst *tree)
{
	if (tree->right)
		execute_pipe(tree);
	else if (tree->left->pst_pt == SIMPLE_CMD)
		execute_simple_command(tree->left);
	else if (tree->left->pst_pt == SUBSHELL)
		execute_subshell(tree->left);
	return ;
}
