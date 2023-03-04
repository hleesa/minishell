/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:07:12 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/28 14:58:46 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	input_eof(void)
{
	printf("exit\n");
	rl_clear_history();
	env_list_clear(&g_gb.envp_list);
	exit(0);
}

int	input_cmd(char *r_line, t_tkn **list_tkn, t_pst **parse_tree)
{
	set_term(0, 1);
	signal(SIGINT, SIG_IGN);
	add_history(r_line);
	if (token_split(r_line, list_tkn))
	{
		free(r_line);
		return (EXIT_FAILURE);
	}
	free(r_line);
	if (!*list_tkn)
		return (EXIT_FAILURE);
	if (ps_complete_cmd(parse_tree, list_tkn))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	global_init(void)
{
	g_gb.envp_list = create_env_list(environ);
	if (!g_gb.envp_list)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main_init(void)
{
	if (global_init())
		return (EXIT_FAILURE);
	set_term(1, 0);
	if (set_signal(0))
		return (ft_malloc_error());
	return (EXIT_SUCCESS);
}

void	after_cmd(void)
{
	token_collector(NULL);
	tree_collector(NULL);
	set_term(0, 0);
	if (set_signal(0))
		exit(ft_malloc_error());
}
