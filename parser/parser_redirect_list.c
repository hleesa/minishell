/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirect_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:19:21 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ps_redirect_list(t_pst **tree, t_tkn **list_tkn)
{
	*tree = new_parse_node(REDIRECT_LIST);
	if (tree_collector(*tree))
		return (ft_malloc_error());
	if (ps_io_redirect(&(*tree)->left, list_tkn))
		return (EXIT_FAILURE);
	if (*list_tkn && check_redirect_token(*list_tkn))
		return (ps_redirect_list(&(*tree)->right, list_tkn));
	return (EXIT_SUCCESS);
}
