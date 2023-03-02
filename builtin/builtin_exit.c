/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:59:17 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/28 18:00:01 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	check_atoi(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (EXIT_FAILURE);
		str++;
	}
	return (EXIT_SUCCESS);
}

int	builtin_exit(char **argv)
{
	int	status;

	if (!g_gb.is_child)
		printf("exit\n");
	if (!argv[1])
		exit(0);
	if (check_atoi(argv[1]))
	{
		ft_perror("minishell: exit: %s: numeric argument required\n", argv[1]);
		exit(255);
	}
	if (argv[2])
	{
		ft_perror("minishell: exit: too many arguments\n");
		return (EXIT_FAILURE);
	}
	status = ft_atoi(argv[1]);
	exit(status);
}
