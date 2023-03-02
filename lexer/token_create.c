/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:33:51 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/26 20:36:29 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*token_str_create(char *str, int len)
{
	char	*tkn_str;
	int		idx;

	tkn_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!tkn_str)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		tkn_str[idx] = str[idx];
		idx++;
	}
	return (tkn_str);
}

int	token_create(char **str, t_tkn **list_tkn, int len, t_tkn_type tkn_tp)
{
	t_tkn	*tkn;
	char	*tkn_str;

	if (len)
	{
		tkn_str = token_str_create(*str, len);
		if (!tkn_str)
			return (EXIT_FAILURE);
		tkn = tkn_new(tkn_tp, tkn_str);
		if (token_collector(tkn))
		{
			free(tkn_str);
			return (EXIT_FAILURE);
		}
		tkn_add_back(list_tkn, tkn);
		*str += len;
	}
	if (*str[0] == ' ')
		*str += 1;
	return (EXIT_SUCCESS);
}
