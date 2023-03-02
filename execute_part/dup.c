/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:54:30 by salee2            #+#    #+#             */
/*   Updated: 2023/02/19 16:54:31 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	dup2_exit_if_error(int fildes, int fildes2)
{
	if (dup2(fildes, fildes2) == ERROR)
	{
		perror("dup2()");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	dup_exit_if_error(int fildes)
{
	int	fildes2;

	fildes2 = dup(fildes);
	if (fildes2 == ERROR)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	return (fildes2);
}
