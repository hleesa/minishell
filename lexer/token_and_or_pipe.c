/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_and_or_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:40:10 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_and(char **str, t_tkn **list_tkn, int *len)
{
	if (token_create(str, list_tkn, *len, WORD))
		return (EXIT_FAILURE);
	if ((*str)[1] == '&')
	{
		if (token_create(str, list_tkn, 2, AND_IF))
			return (EXIT_FAILURE);
	}
	else
		return (ft_lexer_error(E_TKN, "&"));
	*len = 0;
	return (EXIT_SUCCESS);
}

int	token_or_pipe(char **str, t_tkn **list_tkn, int *len)
{
	if (token_create(str, list_tkn, *len, WORD))
		return (EXIT_FAILURE);
	if ((*str)[1] == '|')
	{
		if (token_create(str, list_tkn, 2, OR_IF))
			return (EXIT_FAILURE);
	}
	else
	{
		if (token_create(str, list_tkn, 1, PIPE))
			return (EXIT_FAILURE);
	}
	*len = 0;
	return (EXIT_SUCCESS);
}
