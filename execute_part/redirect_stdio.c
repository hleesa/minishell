/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stdio.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:28 by salee2            #+#    #+#             */
/*   Updated: 2023/02/07 17:02:30 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	redirect_stdin_to_file(char *path)
{
	const int	fd = open(path, O_RDONLY);

	if (exit_if_open_error(fd, path))
		return (EXIT_FAILURE);
	dup2_exit_if_error(fd, STDIN_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	redirect_stdout_to_file(char *path)
{
	const int	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (exit_if_open_error(fd, path))
		return (EXIT_FAILURE);
	dup2_exit_if_error(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	redirect_stdout_to_file_append(char *path)
{
	const int	fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);

	if (exit_if_open_error(fd, path))
		return (EXIT_FAILURE);
	dup2_exit_if_error(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}
