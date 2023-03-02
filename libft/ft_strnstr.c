/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:29:10 by salee2            #+#    #+#             */
/*   Updated: 2022/07/12 11:57:41 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			hay_idx;
	const size_t	hay_len = ft_strlen(haystack);
	const size_t	need_len = ft_strlen(needle);

	if (needle == 0)
		return ((char *)haystack);
	hay_idx = 0;
	while (hay_idx + need_len <= hay_len && hay_idx + need_len <= len)
	{
		if (ft_strncmp(haystack + hay_idx, needle, need_len) == 0)
			return ((char *)(haystack + hay_idx));
		++hay_idx;
	}
	return (0);
}
