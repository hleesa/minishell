/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_complete_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:58:58 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_complete_cmd(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(COMPLETE_CMD);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	if (ps_list(&(*tree)->left, list_tkn, LIST))
		return (EXIT_FAILURE);
	if (*list_tkn)
		return (ft_parse_error(E_TKN, *list_tkn, 1));
	return (EXIT_SUCCESS);
}
