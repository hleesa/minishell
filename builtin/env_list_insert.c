/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:53:50 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/21 14:06:51 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	env_add_front(t_env **env_list, t_env *env_node)
{
	env_node->next = *env_list;
	*env_list = env_node;
}

static void	env_list_insert(t_env **env_list, t_env *env_node)
{
	env_node->next = (*env_list)->next;
	(*env_list)->next = env_node;
}

static void	env_replace_value(t_env **env_list, t_env *env_node)
{
	char	*del_value;

	if (!env_node->value)
		return ;
	del_value = (*env_list)->value;
	(*env_list)->value = env_node->value;
	env_node->value = NULL;
	free(del_value);
}

static int	env_search_insert_front(t_env **env_list, t_env *env_node)
{
	if (!*env_list || ft_strcmp(env_node->key, (*env_list)->key) < 0)
	{
		env_add_front(env_list, env_node);
		return (EXIT_SUCCESS);
	}
	else if (!ft_strcmp(env_node->key, (*env_list)->key))
	{
		env_replace_value(env_list, env_node);
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

void	env_search_insert(t_env **env_list, t_env *env_node)
{
	t_env	*start;

	if (!env_search_insert_front(env_list, env_node))
		return ;
	start = *env_list;
	while (start->next)
	{
		if (ft_strcmp(env_node->key, start->next->key) < 0)
		{
			env_list_insert(&start, env_node);
			return ;
		}
		else if (!ft_strcmp(env_node->key, start->next->key))
		{
			env_replace_value(&start->next, env_node);
			delete_env(env_node);
			return ;
		}
		start = start->next;
	}
	start->next = env_node;
}
