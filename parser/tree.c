/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:21:29 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/02 20:17:34 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_pst	*new_parse_node(t_pt pt)
{
	t_pst	*new_node;

	new_node = (t_pst *)ft_calloc(1, sizeof(t_pst));
	if (!new_node)
		return (NULL);
	new_node->pst_pt = pt;
	new_node->list_tkn = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
