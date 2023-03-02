/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:00:56 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_subshell(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(SUBSHELL);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	*list_tkn = (*list_tkn)->next;
	if (ps_list(&(*tree)->left, list_tkn, LIST))
		return (EXIT_FAILURE);
	if (!*list_tkn || (*list_tkn)->tkn_tp != END_SUB)
		return (ft_parse_error(E_EOF, NULL, 0));
	*list_tkn = (*list_tkn)->next;
	if (*list_tkn && check_redirect_token(*list_tkn))
		return (ps_redirect_list(&(*tree)->right, list_tkn));
	return (EXIT_SUCCESS);
}
