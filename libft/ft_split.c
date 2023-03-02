/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:13:20 by salee2            #+#    #+#             */
/*   Updated: 2022/07/12 14:22:19 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_num_of_row(char const *s, char c)
{
	size_t	i;
	size_t	nom_of_row;

	if (s == 0)
		return (0);
	i = 0;
	nom_of_row = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		if (s[i] && s[i] != c)
			++nom_of_row;
		while (s[i] && s[i] != c)
			++i;
	}
	return (nom_of_row);
}

void	free_all(char **ret, int word_idx)
{
	--word_idx;
	while (word_idx >= 0)
	{
		free(ret[word_idx]);
		--word_idx;
	}
	free(ret);
	return ;
}

char	*mystrdup(char const *s, char c, size_t *idx)
{
	size_t	i;
	size_t	di;
	char	*ret;

	while (s[*idx] && s[*idx] == c)
		++*idx;
	di = 0;
	while (s[*idx + di] && s[*idx + di] != c)
		++di;
	ret = (char *)malloc(sizeof(char) * (di + 1));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < di)
	{
		ret[i] = s[*idx + i];
		++i;
	}
	*idx += di;
	ret[di] = '\0';
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	s_idx;
	size_t	row;
	size_t	row_end;

	row_end = get_num_of_row(s, c);
	ret = (char **) malloc(sizeof(char *) * (row_end + 1));
	if (ret == 0)
		return (0);
	s_idx = 0;
	row = 0;
	while (row < row_end)
	{
		ret[row] = mystrdup(s, c, &s_idx);
		if (ret[row] == 0)
		{
			free_all(ret, (int)row);
			return (0);
		}
		++row;
	}
	ret[row_end] = 0;
	return (ret);
}
