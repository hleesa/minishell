/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:28:10 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/25 16:08:22 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	t_tkn	*list_tkn;
	t_pst	*parse_tree;
	char	*r_line;

	if (main_init())
		return (EXIT_FAILURE);
	while (1)
	{
		list_tkn = NULL;
		parse_tree = NULL;
		r_line = readline("minishell$ ");
		if (!r_line)
			input_eof();
		else if (*r_line == '\0')
			free(r_line);
		else
		{
			if (!input_cmd(r_line, &list_tkn, &parse_tree))
				execute_complete_list(parse_tree);
		}
		after_cmd();
	}
	return (EXIT_SUCCESS);
}
