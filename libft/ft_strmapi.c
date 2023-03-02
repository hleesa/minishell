/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:45:04 by salee2            #+#    #+#             */
/*   Updated: 2022/07/09 21:02:51 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;
	size_t	size;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	ret = (char *) malloc(size + 1);
	if (ret == 0)
		return (0);
	i = 0;
	while (i < size && f)
	{
		ret[i] = f(i, s[i]);
		++i;
	}
	ret[size] = '\0';
	return (ret);
}
