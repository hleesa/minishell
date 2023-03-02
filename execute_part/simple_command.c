/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:56:58 by salee2            #+#    #+#             */
/*   Updated: 2023/02/26 19:41:06 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_pre_simple_command(t_pst *tree, t_tkn **cmd_list)
{
	if (tree->left->pst_pt == REDIRECT_LIST)
	{
		if (execute_redirect_list(tree->left))
			return (EXIT_FAILURE);
		if (tree->right)
			if (execute_cmd_suffix(tree->right, cmd_list))
				return (EXIT_FAILURE);
	}
	else if (tree->left->pst_pt == CMD_NAME)
	{
		if (expansion(tree->left->list_tkn))
			return (EXIT_FAILURE);
		*cmd_list = tree->left->list_tkn;
		if (tree->right)
			if (execute_suffix(tree->right, cmd_list))
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	simple_command_child(t_tkn *cmd_list)
{
	if (set_signal(1))
		exit(ft_malloc_error());
	if (cmd_list != NULL)
		execute_execve(cmd_list);
	exit(EXIT_SUCCESS);
}

void	simple_command_parent(void)
{
	wait(&g_gb.exit_status);
	if (WIFEXITED(g_gb.exit_status))
		g_gb.exit_status = WEXITSTATUS(g_gb.exit_status);
	else if (WIFSIGNALED(g_gb.exit_status))
	{
		if (g_gb.exit_status == SIGQUIT)
			printf("Quit: %d", g_gb.exit_status);
		g_gb.exit_status |= 128;
		printf("\n");
	}
	return ;
}

void	execute_simple_command(t_pst *tree)
{
	pid_t	pid;
	t_tkn	*cmd_list;
	int		builtin_enum;

	cmd_list = NULL;
	if (execute_pre_simple_command(tree, &cmd_list))
	{
		g_gb.exit_status = EXIT_FAILURE;
		return ;
	}
	g_gb.exit_status = EXIT_SUCCESS;
	if (cmd_list == NULL)
		return ;
	builtin_enum = get_builtin_enum(cmd_list->str);
	if (builtin_enum != 0)
		execute_builtin(builtin_enum, cmd_list);
	else
	{
		pid = fork_exit_if_error();
		if (pid == CHILD)
			simple_command_child(cmd_list);
		else
			simple_command_parent();
	}
	return ;
}
