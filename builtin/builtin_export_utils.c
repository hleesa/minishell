/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:36:41 by doohkim           #+#    #+#             */
/*   Updated: 2023/03/01 16:54:48 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_export_env(char *argv)
{
	int	idx;

	if (!ft_isalpha(argv[0]) && argv[0] != '_')
	{
		ft_perror("minishell: export: `%s': not a valid identifier\n", argv);
		return (EXIT_FAILURE);
	}
	idx = 1;
	while (argv[idx] && argv[idx] != '=' && argv[idx] != '+')
	{
		if (!ft_isalnum(argv[idx]) && argv[idx] != '_')
		{
			ft_perror("minishell: export: `%s': not a valid identifier\n", argv);
			return (EXIT_FAILURE);
		}
		idx++;
	}
	if (argv[idx] == '+' && argv[idx + 1] != '=')
	{
		ft_perror("minishell: export: `%s': not a valid identifier\n", argv);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_append(char *env_str)
{
	while (*env_str && *env_str != '=')
	{
		if (*env_str == '+')
			return (1);
		env_str++;
	}
	return (0);
}

int	append_env(t_env **env_list, char *env_str, int is_append)
{
	char	*append_str;
	char	*del_value;
	t_env	*append_env;

	append_env = env_list_search_key(*env_list, env_str);
	append_str = ft_value_str(env_str, is_append);
	if (!append_str)
		return (EXIT_FAILURE);
	del_value = append_env->value;
	if (!del_value)
		append_env->value = append_str;
	else
	{
		append_env->value = ft_strjoin(del_value, append_str);
		if (!append_env->value)
			return (EXIT_FAILURE);
		free(append_str);
		free(del_value);
	}
	return (EXIT_SUCCESS);
}

int	export_env(t_env **env_list, char *env_str, int is_append)
{
	t_env	*node;

	if (is_append && env_list_search_key(*env_list, env_str))
	{
		if (append_env(env_list, env_str, is_append))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	node = new_env_node(env_str, is_append);
	if (!node)
		return (EXIT_FAILURE);
	env_search_insert(env_list, node);
	return (EXIT_SUCCESS);
}
