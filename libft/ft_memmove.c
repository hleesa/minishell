/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:24:52 by salee2            #+#    #+#             */
/*   Updated: 2022/07/10 14:47:31 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dp;
	const unsigned char	*sp;

	if (dst == 0 && src == 0)
		return (0);
	if (len == 0)
		return (dst);
	i = 0;
	dp = (unsigned char *)dst;
	sp = (const unsigned char *)src;
	while (i < len)
	{
		if (dp < sp)
		{
			dp[i] = sp[i];
			++i;
		}
		else
		{
			dp[len - 1] = sp[len - 1];
			--len;
		}
	}
	return (dst);
}
