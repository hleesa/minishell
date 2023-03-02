/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipeline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:00:28 by doohkim           #+#    #+#             */
/*   Updated: 2023/03/01 15:25:19 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_pipeline(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(PIPELINE);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	if (!*list_tkn)
		return (ft_parse_error(E_EOF, NULL, 0));
	if ((*list_tkn)->tkn_tp == START_SUB)
	{
		if (ps_subshell(&(*tree)->left, list_tkn))
			return (EXIT_FAILURE);
	}
	else
	{
		if (ps_simple_cmd(&(*tree)->left, list_tkn))
			return (EXIT_FAILURE);
	}
	if (*list_tkn && (*list_tkn)->tkn_tp == PIPE)
	{
		if (++g_gb.pipe_level >= 3333)
			return (ft_parse_error(E_TKN, *list_tkn, 1));
		*list_tkn = (*list_tkn)->next;
		return (ps_pipeline(&(*tree)->right, list_tkn));
	}
	return (EXIT_SUCCESS);
}
