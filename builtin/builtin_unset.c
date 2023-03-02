/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:14:36 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/21 14:42:20 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_unset_env(char *argv)
{
	int	idx;

	if (!ft_isalpha(argv[0]) && argv[0] != '_')
	{
		ft_perror("minishell: unset: `%s': not a valid identifier\n", argv);
		return (EXIT_FAILURE);
	}
	idx = 1;
	while (argv[idx])
	{
		if (!ft_isalnum(argv[idx]) && argv[idx] != '_')
		{
			ft_perror("minishell: unset: `%s': not a valid identifier\n", argv);
			return (EXIT_FAILURE);
		}
		idx++;
	}
	return (EXIT_SUCCESS);
}

static void	unset_env(t_env **env)
{
	t_env	*del_env;

	del_env = (*env)->next;
	(*env)->next = del_env->next;
	delete_env(del_env);
}

static void	search_unset_env(t_env **env_list, char *env)
{
	t_env	*start;

	if (!*env_list)
		return ;
	start = *env_list;
	while (start->next)
	{
		if (!ft_strcmp(start->next->key, env))
		{
			unset_env(&start);
			return ;
		}
		start = start->next;
	}
}

int	builtin_unset(char **argv)
{
	t_env	*env_list;
	int		idx;

	env_list = g_gb.envp_list;
	idx = 1;
	while (argv[idx])
	{
		if (!check_unset_env(argv[idx]))
		{
			search_unset_env(&env_list, argv[idx]);
			g_gb.envp_list = env_list;
		}
		idx++;
	}
	return (EXIT_SUCCESS);
}
