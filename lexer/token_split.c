/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:10:07 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_token_type(int (*tkn_type[9])(char**, t_tkn**, int*))
{
	tkn_type[0] = token_word;
	tkn_type[1] = token_input;
	tkn_type[2] = token_output;
	tkn_type[3] = token_or_pipe;
	tkn_type[4] = token_and;
	tkn_type[5] = token_single_quote;
	tkn_type[6] = token_double_quote;
	tkn_type[7] = token_start_sub;
	tkn_type[8] = token_end_sub;
}

int	token_split(char *str, t_tkn **list_tkn)
{
	int	(*tkn_type[9])(char**, t_tkn**, int*);
	int	len;
	int	idx;

	len = 0;
	set_token_type(tkn_type);
	while (1)
	{
		idx = ft_strichr(str[len], " <>|&\'\"()");
		if (idx != -1)
		{
			if (tkn_type[idx](&str, list_tkn, &len))
				return (EXIT_FAILURE);
		}
		else if (!str[len])
		{
			if (token_word(&str, list_tkn, &len))
				return (EXIT_FAILURE);
			break ;
		}
		else
			len++;
	}
	return (EXIT_SUCCESS);
}
