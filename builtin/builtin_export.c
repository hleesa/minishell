/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:26:38 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:56:04 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	print_export(t_env *env_list)
{
	while (env_list)
	{
		printf("declare -x %s", env_list->key);
		if (env_list->value)
			printf("=\"%s\"", env_list->value);
		printf("\n");
		env_list = env_list->next;
	}
	return (EXIT_SUCCESS);
}

int	builtin_export(char **argv)
{
	t_env	*env_list;
	int		idx;
	int		is_append;

	env_list = g_gb.envp_list;
	idx = 1;
	if (!argv[idx])
		return (print_export(env_list));
	while (argv[idx])
	{
		if (!check_export_env(argv[idx]))
		{
			is_append = check_append(argv[idx]);
			if (export_env(&env_list, argv[idx], is_append))
				return (EXIT_FAILURE);
			g_gb.envp_list = env_list;
		}
		idx++;
	}
	return (EXIT_SUCCESS);
}
