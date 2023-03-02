/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:28:08 by salee2            #+#    #+#             */
/*   Updated: 2023/02/19 18:12:33 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_builtin_enum(char *cmd)
{
	int			i;
	const char	*builtin[BUILTIN_SIZE] = {"echo", "cd", "pwd", "export", \
	"unset", "env", "exit"};

	i = -1;
	while (++i < BUILTIN_SIZE)
	{
		if (ft_strcmp(cmd, builtin[i]) == SAME)
			return (i + 1);
	}
	return (0);
}

void	execute_builtin(int builtin_enum, t_tkn *cmd_list)
{
	char	**argv;

	argv = create_argv(cmd_list);
	if (builtin_enum == B_ECHO)
		g_gb.exit_status = builtin_echo(argv);
	else if (builtin_enum == CD)
		g_gb.exit_status = builtin_cd(argv);
	else if (builtin_enum == PWD)
		g_gb.exit_status = builtin_pwd();
	else if (builtin_enum == EXPORT)
		g_gb.exit_status = builtin_export(argv);
	else if (builtin_enum == UNSET)
		g_gb.exit_status = builtin_unset(argv);
	else if (builtin_enum == ENV)
		g_gb.exit_status = builtin_env();
	else if (builtin_enum == EXIT)
		g_gb.exit_status = builtin_exit(argv);
	clear_argv(argv);
	return ;
}
