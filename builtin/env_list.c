/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:31:56 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/28 19:37:12 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env	*new_env_node(char *env_str, int is_append)
{
	t_env	*new_node;

	new_node = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->key = ft_key_str(env_str);
	if (!new_node->key)
	{
		free(new_node);
		return (NULL);
	}
	if (ft_key_len(env_str) != ((int) ft_strlen(env_str) + is_append))
	{
		new_node->value = ft_value_str(env_str, is_append);
		if (!new_node->value)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = NULL;
	return (new_node);
}

void	delete_env(t_env *env)
{
	free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

void	env_list_clear(t_env **env_list)
{
	t_env	*del_env;

	while (*env_list)
	{
		del_env = *env_list;
		*env_list = (*env_list)->next;
		delete_env(del_env);
	}
}

int	env_list_size(t_env *env_list)
{
	int	size;

	size = 0;
	while (env_list)
	{
		size++;
		env_list = env_list->next;
	}
	return (size);
}
