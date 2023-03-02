/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:47:27 by salee2            #+#    #+#             */
/*   Updated: 2023/02/16 20:40:15 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	execute_io_redirect(t_pst *tree)
{
	int	ret;

	if (tree->list_tkn->tkn_tp == SGL_IN)
		return (redirect_stdin_to_file(tree->list_tkn->next->str));
	else if (tree->list_tkn->tkn_tp == SGL_OUT)
		return (redirect_stdout_to_file(tree->list_tkn->next->str));
	else if (tree->list_tkn->tkn_tp == DB_IN)
	{
		ret = redirect_stdin_to_file(tree->list_tkn->next->str);
		unlink(tree->list_tkn->next->str);
		return (ret);
	}
	else if (tree->list_tkn->tkn_tp == DB_OUT)
		return (redirect_stdout_to_file_append(tree->list_tkn->next->str));
	return (EXIT_SUCCESS);
}

int	execute_redirect_list(t_pst *tree)
{
	if (expansion(tree->left->list_tkn))
		return (EXIT_FAILURE);
	if (execute_io_redirect(tree->left))
		return (EXIT_FAILURE);
	if (tree->right)
		execute_redirect_list(tree->right);
	return (EXIT_SUCCESS);
}
