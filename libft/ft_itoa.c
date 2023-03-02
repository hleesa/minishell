/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:56:31 by salee2            #+#    #+#             */
/*   Updated: 2022/07/09 20:37:20 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		++size;
	while (n)
	{
		++size;
		n /= 10;
	}
	return (size);
}

void	to_string(int n, char *str, size_t idx)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	if (-10 < n && n < 10)
	{
		str[idx] = n * sign + '0';
		return ;
	}
	to_string(n / 10 * sign, str, idx - 1);
	str[idx] = n % 10 * sign + '0';
	return ;
}

char	*ft_itoa(int n)
{
	char			*ret;
	const size_t	size = get_size(n);

	ret = (char *) malloc(size + 1);
	if (ret == 0)
		return (0);
	to_string(n, ret, size - 1);
	ret[size] = '\0';
	return (ret);
}
