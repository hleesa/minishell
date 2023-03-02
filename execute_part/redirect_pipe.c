/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:14 by salee2            #+#    #+#             */
/*   Updated: 2023/02/07 17:02:15 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	redirect_w_pipe_to_stdout(int *pipe_fds)
{
	close(pipe_fds[READ_FD]);
	dup2_exit_if_error(pipe_fds[WRITE_FD], STDOUT_FILENO);
	close(pipe_fds[WRITE_FD]);
	return ;
}

void	redirect_r_pipe_to_stdin(int *pipe_fds)
{
	close(pipe_fds[WRITE_FD]);
	dup2_exit_if_error(pipe_fds[READ_FD], STDIN_FILENO);
	close(pipe_fds[READ_FD]);
	return ;
}
