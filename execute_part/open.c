/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:17:34 by salee2            #+#    #+#             */
/*   Updated: 2023/02/23 15:17:37 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	exit_if_open_error(int fd, char *path)
{
	if (fd == ERROR)
	{
		ft_perror("minishell: %s: %s\n", path, strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
