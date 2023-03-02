/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:17:58 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_argv(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(ARGV);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	(*tree)->list_tkn = *list_tkn;
	*list_tkn = (*list_tkn)->next;
	(*tree)->list_tkn->next = NULL;
	return (EXIT_SUCCESS);
}
