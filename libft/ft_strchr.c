/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:50:11 by salee2            #+#    #+#             */
/*   Updated: 2022/07/12 16:40:15 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	ch = c;

	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		++i;
	}
	if (ch == 0)
		return ((char *)(s + i));
	return (0);
}
