/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:34:24 by salee2            #+#    #+#             */
/*   Updated: 2023/02/19 17:34:27 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	fork_exit_if_error(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == ERROR)
	{
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	return (pid);
}
