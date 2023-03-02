/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:14:27 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:54:42 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	token_str_remove_pre_env(t_tkn *tkn, int env_idx)
{
	int	idx;

	idx = 0;
	while (tkn->str[idx])
	{
		if (idx == env_idx)
		{
			while (tkn->str[idx + 1])
			{
				tkn->str[idx] = tkn->str[idx + 1];
				idx++;
			}
			tkn->str[idx] = tkn->str[idx + 1];
			break ;
		}
		idx++;
	}
}

static char	*token_str_remove_quote(char *str, int s_idx, int e_idx, int len)
{
	char	*new_str;
	int		idx;
	int		new_idx;

	new_str = (char *)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (NULL);
	idx = 0;
	new_idx = 0;
	while (new_idx < len)
	{
		if (idx != s_idx && idx != e_idx)
			new_str[new_idx++] = str[idx++];
		else
			idx++;
	}
	new_str[len] = 0;
	return (new_str);
}

static int	remove_quote(t_tkn *tkn, int *s_idx, char quote)
{
	char	*new_str;
	char	*del_str;
	int		len;
	int		e_idx;

	len = ft_strlen(tkn->str) - 2;
	if (*s_idx && tkn->str[*s_idx - 1] == '$')
	{
		token_str_remove_pre_env(tkn, --(*s_idx));
		len--;
	}
	e_idx = *s_idx + 1;
	while (tkn->str[e_idx] != quote)
		e_idx++;
	new_str = token_str_remove_quote(tkn->str, *s_idx, e_idx, len);
	if (!new_str)
	{
		token_collector(NULL);
		return (EXIT_FAILURE);
	}
	del_str = tkn->str;
	tkn->str = new_str;
	free(del_str);
	*s_idx = e_idx - 2;
	return (EXIT_SUCCESS);
}

int	quote_expansion(t_tkn *list_tkn)
{
	int	s_idx;

	while (list_tkn)
	{
		if (list_tkn->tkn_tp == WORD)
		{
			s_idx = 0;
			while (list_tkn->str[s_idx])
			{
				if (list_tkn->str[s_idx] == '\'')
				{
					if (remove_quote(list_tkn, &s_idx, '\''))
						return (EXIT_FAILURE);
				}
				else if (list_tkn->str[s_idx] == '\"')
				{
					if (remove_quote(list_tkn, &s_idx, '\"'))
						return (EXIT_FAILURE);
				}
				s_idx++;
			}
		}
		list_tkn = list_tkn->next;
	}
	return (EXIT_SUCCESS);
}
