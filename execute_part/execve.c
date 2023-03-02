/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:37:35 by salee2            #+#    #+#             */
/*   Updated: 2023/02/28 15:03:39 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	get_file_type(const char *path)
{
	struct stat	info;

	if (stat(path, &info) == -1)
		return (-1);
	if (S_ISDIR(info.st_mode))
		return (1);
	else
		return (0);
}

void	perror_exit(char *file, char *msg, t_bool eno, int exit_status)
{
	ft_perror("minishell: %s: ", file);
	if (eno)
		ft_perror(msg, strerror(errno));
	else
		ft_perror(msg);
	exit(exit_status);
}

void	execute_include_path_file(char **argv, char **envp)
{
	if (access(argv[0], F_OK) == SUCCESS)
	{
		if (access(argv[0], X_OK) == SUCCESS)
		{
			if (get_file_type(argv[0]) == DIR)
				perror_exit(argv[0], "is a directory\n", FALSE, 126);
			else if (execve(argv[0], argv, envp) == ERROR)
				perror_exit(argv[0], "%s\n", TRUE, EXIT_FAILURE);
		}
		perror_exit(argv[0], "%s\n", TRUE, 126);
	}
	perror_exit(argv[0], "%s\n", TRUE, 127);
}

void	execute_exclude_path_file(char **argv, char **envp)
{
	int		i;
	char	**executable_file_list;

	executable_file_list = get_executable_file_list("PATH", argv[0], envp);
	i = -1;
	while (executable_file_list[++i])
	{
		if (access(executable_file_list[i], F_OK) == SUCCESS)
		{
			if (access(executable_file_list[i], X_OK) == SUCCESS)
			{
				if (get_file_type(executable_file_list[i]) == DIR)
					perror_exit(argv[0], "command not found\n", FALSE, 127);
				else if (execve(executable_file_list[i], argv, envp) == ERROR)
					perror_exit(argv[0], "%s\n", TRUE, EXIT_FAILURE);
			}
			perror_exit(argv[0], "%s\n", TRUE, 126);
		}
	}
	perror_exit(argv[0], "command not found\n", FALSE, 127);
}

void	execute_execve(t_tkn *cmd_list)
{
	char		**argv;
	char		**envp;

	argv = create_argv(cmd_list);
	if (!argv)
		exit(EXIT_FAILURE);
	if (argv[0][0] == '\0')
		perror_exit(argv[0], "command not found\n", FALSE, 127);
	envp = create_new_envp();
	if (!envp)
		exit(EXIT_FAILURE);
	if (ft_strchr(argv[0], '/'))
		execute_include_path_file(argv, envp);
	else
		execute_exclude_path_file(argv, envp);
	return ;
}
