/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:13:33 by doohkim           #+#    #+#             */
/*   Updated: 2023/03/02 18:51:38 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_option(char *argv)
{
	if (*argv != '-')
		return (EXIT_FAILURE);
	argv++;
	while (*argv && *argv == 'n')
		argv++;
	if (*argv)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	print_echo(char **argv, int idx)
{
	while (argv[idx])
	{
		ft_putstr_fd(argv[idx++], STDOUT_FILENO);
		if (argv[idx])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	return ;
}

int	builtin_echo(char **argv)
{
	int	idx;

	idx = 1;
	if (!argv[idx])
		ft_putstr_fd("\n", STDOUT_FILENO);
	else if (!check_option(argv[idx]))
	{
		idx++;
		while (!check_option(argv[idx]))
			idx++;
		print_echo(argv, idx);
	}
	else
	{
		print_echo(argv, idx);
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	return (EXIT_SUCCESS);
}
