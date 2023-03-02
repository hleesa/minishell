/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:41:15 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_single_quote(char **str, t_tkn **list_tkn, int *len)
{
	(void)list_tkn;
	while ((*str)[++(*len)] != '\'')
	{
		if (!(*str)[*len])
			return (ft_lexer_error(E_EOF_TKN, "\'"));
	}
	*len += 1;
	return (EXIT_SUCCESS);
}

int	token_double_quote(char **str, t_tkn **list_tkn, int *len)
{
	(void)list_tkn;
	while ((*str)[++(*len)] != '\"')
	{
		if (!(*str)[*len])
			return (ft_lexer_error(E_EOF_TKN, "\""));
	}
	*len += 1;
	return (EXIT_SUCCESS);
}
