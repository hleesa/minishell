/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expansion_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:56:44 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/26 20:21:21 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strichr(char find_c, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (find_c == str[idx])
			return (idx);
		idx++;
	}
	return (-1);
}

char	*get_env_value(char *env_str)
{
	char	*new_str;

	new_str = builtin_getenv(++env_str);
	return (new_str);
}

char	*token_str_replace_env(t_tkn *tkn, char *env_str, int s_idx, int e_idx)
{
	char	*new_str;
	int		len;
	int		idx;
	int		new_idx;

	len = ft_strlen(tkn->str) - (e_idx - s_idx) + ft_strlen(env_str);
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	new_idx = 0;
	idx = 0;
	while (new_idx < len)
	{
		if (idx == s_idx)
		{
			idx = 0;
			while (env_str && env_str[idx])
				new_str[new_idx++] = env_str[idx++];
			idx = e_idx;
		}
		new_str[new_idx++] = tkn->str[idx++];
	}
	return (new_str);
}

int	replace_status(t_tkn *tkn, int s_idx, int e_idx)
{
	char	*status;
	char	*new_str;
	char	*del_str;

	status = ft_itoa(g_gb.exit_status);
	if (!status)
		return (EXIT_FAILURE);
	new_str = token_str_replace_env(tkn, status, s_idx, e_idx);
	if (!new_str)
	{
		free(status);
		return (EXIT_FAILURE);
	}
	del_str = tkn->str;
	tkn->str = new_str;
	free(del_str);
	free(status);
	return (EXIT_SUCCESS);
}

int	replace_env(t_tkn *tkn, int s_idx, int e_idx)
{
	char	*env_str;
	char	*new_str;
	char	*del_str;

	env_str = ft_substr(tkn->str, s_idx, e_idx - s_idx);
	if (!env_str)
		return (EXIT_FAILURE);
	del_str = env_str;
	env_str = get_env_value(del_str);
	free(del_str);
	new_str = token_str_replace_env(tkn, env_str, s_idx, e_idx);
	if (!new_str)
	{
		free(env_str);
		return (EXIT_FAILURE);
	}
	del_str = tkn->str;
	tkn->str = new_str;
	free(env_str);
	free(del_str);
	return (EXIT_SUCCESS);
}
