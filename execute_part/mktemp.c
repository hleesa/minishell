/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mktemp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:25:08 by salee2            #+#    #+#             */
/*   Updated: 2023/02/23 17:54:03 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_temp_file(char **envp)
{
	char	*temp_path;
	char	*temp_file_name;
	char	*temp_file;

	temp_path = ft_getenv("TMPDIR", envp);
	temp_file_name = "/tmp.heredoc.XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	temp_file = ft_strjoin(temp_path, temp_file_name);
	return (temp_file);
}

void	exec_mktemp(char **envp)
{
	char	*file;
	char	*exec_agv[4];

	file = ft_strdup("/usr/bin/mktemp");
	if (file == NULL)
		exit(EXIT_FAILURE);
	exec_agv[0] = ft_strdup("mktemp");
	if (exec_agv[0] == NULL)
		exit(EXIT_FAILURE);
	exec_agv[1] = "-u";
	exec_agv[2] = get_temp_file(envp);
	if (exec_agv[2] == NULL)
		exit(EXIT_FAILURE);
	exec_agv[3] = NULL;
	execve(file, exec_agv, envp);
	perror("");
	exit(EXIT_FAILURE);
}

void	ft_mktemp_child(int *pipe_fds, char **envp)
{
	redirect_w_pipe_to_stdout(pipe_fds);
	exec_mktemp(envp);
	return ;
}

char	*ft_mktemp_parent(int *pipe_fds, char **envp)
{
	char	buf[256];

	ft_memset(buf, 0, 256);
	redirect_r_pipe_to_stdin(pipe_fds);
	wait(0);
	read(STDIN_FILENO, buf, 256);
	dup2_exit_if_error(g_gb.fds.std_in, STDIN_FILENO);
	envp_clear(envp);
	return (ft_strdup(buf));
}

char	*ft_mktemp(void)
{
	pid_t	pid;
	int		pipe_fds[2];
	char	**envp;

	envp = create_new_envp();
	if (!envp)
		return (NULL);
	mkpipe(pipe_fds);
	pid = fork_exit_if_error();
	if (pid == CHILD)
		ft_mktemp_child(pipe_fds, envp);
	else
		return (ft_mktemp_parent(pipe_fds, envp));
	return (NULL);
}
