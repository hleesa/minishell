/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:06:34 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/21 16:01:18 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_cmd_name(t_pst **tree, t_tkn **list_tkn)
{
	if ((*list_tkn)->tkn_tp != WORD)
		return (ft_parse_error(E_TKN, *list_tkn, 1));
	*tree = new_parse_node(CMD_NAME);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	(*tree)->list_tkn = *list_tkn;
	*list_tkn = (*list_tkn)->next;
	(*tree)->list_tkn->next = NULL;
	return (EXIT_SUCCESS);
}
