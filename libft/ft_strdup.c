/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:24:26 by salee2            #+#    #+#             */
/*   Updated: 2022/07/08 15:34:19 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*ret;

	size = ft_strlen(s1) + 1;
	ret = (char *) malloc(sizeof(char) * (size));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		ret[i] = s1[i];
		++i;
	}
	return (ret);
}
