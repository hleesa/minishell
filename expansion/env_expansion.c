/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:44:21 by doohkim           #+#    #+#             */
/*   Updated: 2023/03/01 15:40:18 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	do_env_expansion(t_tkn *list_tkn, int *s_idx)
{
	int	e_idx;

	e_idx = *s_idx + 1;
	if (list_tkn->str[e_idx] == '?')
	{
		if (replace_status(list_tkn, *s_idx, e_idx + 1))
			return (EXIT_FAILURE);
	}
	else
	{
		while (list_tkn->str[e_idx] \
			&& ft_strichr(list_tkn->str[e_idx], " ><|&\'\"()$") == -1)
			(e_idx)++;
		if (e_idx - *s_idx > 1)
		{
			if (replace_env(list_tkn, *s_idx, e_idx))
				return (EXIT_FAILURE);
		}
	}
	if (list_tkn->str[*s_idx] != '$')
		(*s_idx)--;
	return (EXIT_SUCCESS);
}

static int	find_env_double_quote(t_tkn *list_tkn, int *s_idx)
{
	(*s_idx)++;
	while (list_tkn->str[*s_idx] != '\"')
	{
		if (list_tkn->str[*s_idx] == '$')
		{
			if (do_env_expansion(list_tkn, s_idx))
				return (EXIT_FAILURE);
		}
		(*s_idx)++;
	}
	return (EXIT_SUCCESS);
}

static int	find_env(t_tkn *list_tkn)
{
	int	s_idx;

	s_idx = 0;
	while (list_tkn->str[s_idx])
	{
		if (list_tkn->str[s_idx] == '\"')
		{
			if (find_env_double_quote(list_tkn, &s_idx))
				return (EXIT_FAILURE);
		}
		else if (list_tkn->str[s_idx] == '\'')
		{
			s_idx++;
			while (list_tkn->str[s_idx] != '\'')
				s_idx++;
		}
		else if (list_tkn->str[s_idx] == '$')
		{
			if (do_env_expansion(list_tkn, &s_idx))
				return (EXIT_FAILURE);
		}
		s_idx++;
	}
	return (EXIT_SUCCESS);
}

int	env_expansion(t_tkn *list_tkn)
{
	while (list_tkn)
	{
		if (list_tkn->tkn_tp == WORD)
		{
			if (find_env(list_tkn))
				return (EXIT_FAILURE);
		}
		list_tkn = list_tkn->next;
	}
	return (EXIT_SUCCESS);
}
