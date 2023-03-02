/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:38:56 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_io_redirect(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(IO_REDIRECT);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	(*tree)->list_tkn = *list_tkn;
	*list_tkn = (*list_tkn)->next;
	if (!*list_tkn || (*list_tkn)->tkn_tp != WORD)
		return (ft_parse_error(E_TKN, *list_tkn, 1));
	(*tree)->list_tkn->next = *list_tkn;
	*list_tkn = (*list_tkn)->next;
	(*tree)->list_tkn->next->next = NULL;
	return (EXIT_SUCCESS);
}
