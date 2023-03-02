/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_suffix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:49:46 by salee2            #+#    #+#             */
/*   Updated: 2023/02/16 20:38:49 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_suffix(t_pst *tree, t_tkn **cmd_list)
{
	if (tree->left->pst_pt == ARGV)
	{
		if (expansion(tree->left->list_tkn))
			return (EXIT_FAILURE);
		(*cmd_list)->next = tree->left->list_tkn;
		if (tree->right)
			execute_suffix(tree->right, &(*cmd_list)->next);
	}
	else if (tree->left->pst_pt == IO_REDIRECT)
	{
		if (execute_io_redirect(tree->left))
			return (EXIT_FAILURE);
		if (tree->right)
			execute_suffix(tree->right, cmd_list);
	}
	return (EXIT_SUCCESS);
}

int	execute_cmd_suffix(t_pst *tree, t_tkn **cmd_list)
{
	if (expansion(tree->left->list_tkn))
		return (EXIT_FAILURE);
	*cmd_list = tree->left->list_tkn;
	if (tree->right)
	{
		if (execute_suffix(tree->right, cmd_list))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
