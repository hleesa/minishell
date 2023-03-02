/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:18:31 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_cmd_suffix(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(CMD_SUFFIX);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	if (ps_cmd_name(&(*tree)->left, list_tkn))
		return (EXIT_FAILURE);
	if (*list_tkn && \
		(check_redirect_token(*list_tkn) || (*list_tkn)->tkn_tp == WORD))
		return (ps_suffix(&(*tree)->right, list_tkn));
	return (EXIT_SUCCESS);
}
