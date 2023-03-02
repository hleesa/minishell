/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:06:41 by salee2            #+#    #+#             */
/*   Updated: 2022/07/11 14:10:38 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t			dst_len;
	const size_t	src_len = ft_strlen(src);

	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		++dst_len;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	if (src_len + dst_len < dstsize)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, dstsize - dst_len - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_len + src_len);
}
