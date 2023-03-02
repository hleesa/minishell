/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:39:43 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	token_collector_clear(t_tkn **clt_token)
{
	t_tkn	*del_token;

	while (*clt_token)
	{
		del_token = *clt_token;
		*clt_token = (*clt_token)->clt_next;
		free(del_token->str);
		free(del_token);
	}
}

static void	token_collector_add(t_tkn **clt_token, t_tkn *token)
{
	token->clt_next = *clt_token;
	*clt_token = token;
}

int	token_collector(t_tkn *token)
{
	static t_tkn	*clt_token = NULL;

	if (!token)
	{
		token_collector_clear(&clt_token);
		return (EXIT_FAILURE);
	}
	token_collector_add(&clt_token, token);
	return (EXIT_SUCCESS);
}
