/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:51:30 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/27 15:59:41 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_key_len(char *env)
{
	int	len;

	len = 0;
	while (env[len] && env[len] != '=' && env[len] != '+')
		len++;
	return (len);
}

char	*ft_key_str(char *env)
{
	char	*key;
	int		len;
	int		idx;

	len = ft_key_len(env);
	key = (char *)ft_calloc(len + 1, sizeof(char));
	if (!key)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		key[idx] = env[idx];
		idx++;
	}
	key[idx] = 0;
	return (key);
}

char	*ft_value_str(char *env, int is_append)
{
	char	*value;
	int		key_len;
	int		len;
	int		idx;

	key_len = ft_key_len(env);
	len = ft_strlen(env) - key_len - is_append - 1;
	value = (char *)ft_calloc(len + 1, sizeof(char));
	if (!value)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		value[idx] = env[idx + key_len + 1 + is_append];
		idx++;
	}
	return (value);
}

char	*builtin_getenv(char *key)
{
	char	*env;
	t_env	*start;

	env = NULL;
	start = g_gb.envp_list;
	while (start)
	{
		if (!ft_strcmp(start->key, key) && start->value)
			env = ft_strdup(start->value);
		start = start->next;
	}
	return (env);
}

t_env	*env_list_search_key(t_env *env_list, char *env_str)
{
	char	*key_str;

	key_str = ft_key_str(env_str);
	if (!key_str)
		return (NULL);
	while (env_list)
	{
		if (!ft_strcmp(env_list->key, key_str))
		{
			free(key_str);
			return (env_list);
		}
		env_list = env_list->next;
	}
	free(key_str);
	return (NULL);
}
