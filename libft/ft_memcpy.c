/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:53:49 by salee2            #+#    #+#             */
/*   Updated: 2022/07/10 14:45:45 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dp;
	unsigned char	*sp;

	if (dst == 0 && src == 0)
		return (0);
	dp = (unsigned char *) dst;
	sp = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dp[i] = sp[i];
		++i;
	}
	return (dst);
}
