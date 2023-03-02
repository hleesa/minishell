/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:26:34 by salee2            #+#    #+#             */
/*   Updated: 2022/07/13 16:15:27 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_is_set(char const *set, int *is_set)
{
	int	i;
	int	set_end;

	i = 0;
	while (i < 256)
		is_set[i++] = 0;
	i = 0;
	set_end = ft_strlen(set);
	while (i < set_end)
	{
		is_set[(unsigned char const)set[i]] = 1;
		++i;
	}
	return ;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	begin;
	size_t	end;
	int		is_set[256];

	if (s1 == 0)
		return (0);
	set_is_set(set, is_set);
	i = 0;
	while (s1[i] != 0 && is_set[(unsigned char const)s1[i]])
		++i;
	begin = i;
	i = ft_strlen(s1) - 1;
	while (begin < i && is_set[(unsigned char const)s1[i]])
		--i;
	end = i;
	return (ft_substr(s1, begin, end - begin + 1));
}
