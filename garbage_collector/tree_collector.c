/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_collector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:14:50 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	tree_collector_clear(t_pst **clt_tree)
{
	t_pst	*del_tree;

	while (*clt_tree)
	{
		del_tree = *clt_tree;
		*clt_tree = (*clt_tree)->clt_next;
		free(del_tree);
	}
}

static void	tree_collector_add(t_pst **clt_tree, t_pst *node)
{
	node->clt_next = *clt_tree;
	*clt_tree = node;
}

int	tree_collector(t_pst *node)
{
	static t_pst	*clt_tree = NULL;

	if (!node)
	{
		tree_collector_clear(&clt_tree);
		return (EXIT_FAILURE);
	}
	tree_collector_add(&clt_tree, node);
	return (EXIT_SUCCESS);
}
