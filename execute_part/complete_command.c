/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:49:42 by salee2            #+#    #+#             */
/*   Updated: 2023/02/19 18:12:55 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_if_list(t_pst *tree)
{
	if (tree->pst_pt == AND_IF_LIST && g_gb.exit_status == 0)
		execute_pipeline(tree->left);
	else if (tree->pst_pt == OR_IF_LIST && g_gb.exit_status != 0)
		execute_pipeline(tree->left);
	if (tree->right)
		execute_if_list(tree->right);
	return ;
}

void	execute_list(t_pst *tree)
{
	if (execute_heredoc(tree))
		return ;
	execute_pipeline(tree->left);
	if (tree->right)
		execute_if_list(tree->right);
	return ;
}

void	execute_complete_list(t_pst *tree)
{
	const t_fd	fds = {dup_exit_if_error(STDIN_FILENO), \
	dup_exit_if_error(STDOUT_FILENO)};

	g_gb.is_child = 0;
	execute_list(tree->left);
	dup2_exit_if_error(fds.std_in, STDIN_FILENO);
	dup2_exit_if_error(fds.std_out, STDOUT_FILENO);
	return ;
}
