/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:37:40 by salee2            #+#    #+#             */
/*   Updated: 2023/02/19 16:54:50 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**clear_argv(char **argv)
{
	int	idx;

	idx = 0;
	while (argv[idx])
		free(argv[idx++]);
	free(argv);
	return (NULL);
}

char	**create_argv(t_tkn *cmd_list)
{
	char	**argv;
	int		size;
	int		idx;

	size = tkn_size(cmd_list);
	argv = (char **)ft_calloc(size + 1, sizeof(char *));
	if (!argv)
		return (NULL);
	idx = 0;
	while (cmd_list)
	{
		argv[idx] = ft_strdup(cmd_list->str);
		if (!argv[idx])
			return (clear_argv(argv));
		cmd_list = cmd_list->next;
		idx++;
	}
	return (argv);
}
