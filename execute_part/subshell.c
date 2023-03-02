/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:39:39 by salee2            #+#    #+#             */
/*   Updated: 2023/02/19 18:14:02 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_subshell(t_pst *tree)
{
	pid_t	pid;

	pid = fork_exit_if_error();
	if (pid == CHILD)
	{
		g_gb.is_child = 1;
		if (tree->right)
			execute_redirect_list(tree->right);
		execute_list(tree->left);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&g_gb.exit_status);
		if (WIFEXITED(g_gb.exit_status))
			g_gb.exit_status = WEXITSTATUS(g_gb.exit_status);
	}
	return ;
}
