/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:05:58 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/28 17:09:48 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	replace_oldpwd(t_env **env_list)
{
	t_env	*start;
	t_env	*env_pwd;
	t_env	*env_old;
	char	*del_value;
	char	*value;

	start = *env_list;
	env_old = env_list_search_key(start, "OLDPWD");
	if (!env_old)
		return ;
	env_pwd = env_list_search_key(start, "PWD");
	if (!env_pwd)
		value = ft_strdup("");
	else
		value = ft_strdup(env_pwd->value);
	if (!value)
		return ;
	del_value = env_old->value;
	env_old->value = value;
	if (del_value)
		free(del_value);
}

static void	replace_pwd(t_env **env_list)
{
	t_env	*start;
	t_env	*env_pwd;
	char	*del_value;
	char	*value;

	start = *env_list;
	env_pwd = env_list_search_key(start, "PWD");
	if (!env_pwd)
		return ;
	value = getcwd(NULL, 0);
	if (!value)
		return ;
	del_value = env_pwd->value;
	env_pwd->value = value;
	free(del_value);
}

int	builtin_cd(char **argv)
{
	char	*home;

	if (!argv[1])
	{
		home = builtin_getenv("HOME");
		if (!home)
		{
			ft_perror("minishell: cd: HOME not set\n");
			return (EXIT_FAILURE);
		}
		if (chdir(home))
			return (EXIT_FAILURE);
		free(home);
	}
	else
	{
		if (chdir(argv[1]))
		{
			printf("minishell: cd: %s: No such file or directory\n", argv[1]);
			return (EXIT_FAILURE);
		}
	}
	replace_oldpwd(&g_gb.envp_list);
	replace_pwd(&g_gb.envp_list);
	return (EXIT_SUCCESS);
}
