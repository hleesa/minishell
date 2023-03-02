/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_simple_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:50:17 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_simple_cmd(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(SIMPLE_CMD);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	if (check_redirect_token(*list_tkn))
	{
		if (ps_redirect_list(&(*tree)->left, list_tkn))
			return (EXIT_FAILURE);
		if (*list_tkn && \
			(check_redirect_token(*list_tkn) || (*list_tkn)->tkn_tp == WORD))
			return (ps_cmd_suffix(&(*tree)->right, list_tkn));
	}
	else
	{
		if (ps_cmd_name(&(*tree)->left, list_tkn))
			return (EXIT_FAILURE);
		if (*list_tkn && \
			(check_redirect_token(*list_tkn) || (*list_tkn)->tkn_tp == WORD))
			return (ps_suffix(&(*tree)->right, list_tkn));
	}
	return (EXIT_SUCCESS);
}
