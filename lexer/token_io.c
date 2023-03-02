/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:40:24 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_input(char **str, t_tkn **list_tkn, int *len)
{
	if (token_create(str, list_tkn, *len, WORD))
		return (EXIT_FAILURE);
	if ((*str)[1] == '<')
	{
		if (token_create(str, list_tkn, 2, DB_IN))
			return (EXIT_FAILURE);
	}
	else
	{
		if (token_create(str, list_tkn, 1, SGL_IN))
			return (EXIT_FAILURE);
	}
	*len = 0;
	return (EXIT_SUCCESS);
}

int	token_output(char **str, t_tkn **list_tkn, int *len)
{
	if (token_create(str, list_tkn, *len, WORD))
		return (EXIT_FAILURE);
	if ((*str)[1] == '>')
	{
		if (token_create(str, list_tkn, 2, DB_OUT))
			return (EXIT_FAILURE);
	}
	else
	{
		if (token_create(str, list_tkn, 1, SGL_OUT))
			return (EXIT_FAILURE);
	}
	*len = 0;
	return (EXIT_SUCCESS);
}
