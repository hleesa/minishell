/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:47:21 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_start_sub(char **str, t_tkn **list_tkn, int *len)
{
	if (token_create(str, list_tkn, *len, WORD))
		return (EXIT_FAILURE);
	if (token_create(str, list_tkn, 1, START_SUB))
		return (EXIT_FAILURE);
	*len = 0;
	return (EXIT_SUCCESS);
}

int	token_end_sub(char **str, t_tkn **list_tkn, int *len)
{
	if (token_create(str, list_tkn, *len, WORD))
		return (EXIT_FAILURE);
	if (token_create(str, list_tkn, 1, END_SUB))
		return (EXIT_FAILURE);
	*len = 0;
	return (EXIT_SUCCESS);
}
