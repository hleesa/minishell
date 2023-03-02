/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:59:48 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_list(t_pst **tree, t_tkn **list_tkn, t_pt node_type)
{
	*tree = new_parse_node(node_type);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	if (ps_pipeline(&(*tree)->left, list_tkn))
		return (EXIT_FAILURE);
	if (*list_tkn && (*list_tkn)->tkn_tp == AND_IF)
	{
		*list_tkn = (*list_tkn)->next;
		return (ps_list(&(*tree)->right, list_tkn, AND_IF_LIST));
	}
	else if (*list_tkn && (*list_tkn)->tkn_tp == OR_IF)
	{
		*list_tkn = (*list_tkn)->next;
		return (ps_list(&(*tree)->right, list_tkn, OR_IF_LIST));
	}
	return (EXIT_SUCCESS);
}
