/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:59:23 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/16 20:27:18 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*create_new_envp_null_str(t_env *env_list)
{
	char	*new_env_str;

	new_env_str = ft_strjoin(env_list->key, "=");
	if (!new_env_str)
		return (NULL);
	return (new_env_str);
}

static char	*create_new_envp_str(t_env *env_list)
{
	char	*new_env_str;
	char	*temp_str;

	temp_str = ft_strjoin("=", env_list->value);
	if (!temp_str)
		return (NULL);
	new_env_str = ft_strjoin(env_list->key, temp_str);
	if (!new_env_str)
		return (NULL);
	free(temp_str);
	return (new_env_str);
}

char	**envp_clear(char **new_envp)
{
	int	idx;

	idx = 0;
	while (new_envp[idx])
		free(new_envp[idx++]);
	free(new_envp);
	return (NULL);
}

char	**create_new_envp(void)
{
	char	**new_envp;
	t_env	*env_list;
	int		idx;
	int		size;

	env_list = g_gb.envp_list;
	size = env_list_size(env_list);
	new_envp = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!new_envp)
		return (NULL);
	idx = 0;
	while (env_list)
	{
		if (env_list->value)
			new_envp[idx] = create_new_envp_str(env_list);
		else
			new_envp[idx] = create_new_envp_null_str(env_list);
		if (!new_envp[idx])
			return (envp_clear(new_envp));
		env_list = env_list->next;
		idx++;
	}
	return (new_envp);
}
