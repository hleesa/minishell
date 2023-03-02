/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:23:25 by salee2            #+#    #+#             */
/*   Updated: 2022/07/10 14:44:52 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	while (i < n)
	{
		if (cp1[i] != cp2[i])
			break ;
		++i;
	}
	if (i == n)
		return (0);
	return (cp1[i] - cp2[i]);
}
