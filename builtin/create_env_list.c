/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:36:03 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/28 19:36:55 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	increase_shlvl(t_env *node)
{
	char	*new_lvl;
	int		lvl;

	lvl = ft_atoi(node->value);
	lvl++;
	new_lvl = ft_itoa(lvl);
	if (!new_lvl)
		return (EXIT_FAILURE);
	free(node->value);
	node->value = new_lvl;
	return (EXIT_SUCCESS);
}

static int	check_node(t_env *node)
{
	if (!node)
		return (EXIT_FAILURE);
	else if (!ft_strcmp(node->key, "OLDPWD"))
	{
		free(node->value);
		node->value = NULL;
	}
	else if (!ft_strcmp(node->key, "SHLVL"))
	{
		if (increase_shlvl(node))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_env	*create_env_list(char **old_envp)
{
	t_env	*list;
	t_env	*node;
	int		idx;

	list = NULL;
	idx = 0;
	while (old_envp[idx])
	{
		node = new_env_node(old_envp[idx++], 0);
		if (check_node(node))
		{
			env_list_clear(&list);
			return (NULL);
		}
		env_search_insert(&list, node);
	}
	return (list);
}
