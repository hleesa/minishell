/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pxp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:58:54 by salee2            #+#    #+#             */
/*   Updated: 2023/02/21 14:58:56 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_perror.h"

char	*itoh(unsigned long long num, const char *to_hex, int is_addr)
{
	int		i;
	char	hex[HEX_LEN];

	ft_bzero(hex, HEX_LEN);
	i = HEX_LEN - 1;
	if (num == 0)
		hex[--i] = to_hex[0];
	while (num)
	{
		hex[--i] = to_hex[num % 16];
		num /= 16;
	}
	if (is_addr)
	{
		hex[--i] = 'x';
		hex[--i] = '0';
	}
	return (ft_strdup(hex + i));
}

ssize_t	p_func(va_list ap)
{
	ssize_t				ret;
	unsigned long long	addr;
	char				*hex_addr;
	const char			*to_hex = "0123456789abcdef";

	addr = (unsigned long long)va_arg(ap, void *);
	hex_addr = itoh(addr, to_hex, 1);
	if (hex_addr == 0)
		return (-1);
	ret = write(STDERR_FILENO, hex_addr, ft_strlen(hex_addr));
	free(hex_addr);
	return (ret);
}

ssize_t	xl_func(va_list ap)
{
	ssize_t			ret;
	unsigned int	u;
	char			*hex;
	const char		*to_hex = "0123456789abcdef";

	u = va_arg(ap, unsigned int);
	hex = itoh(u, to_hex, 0);
	if (hex == 0)
		return (-1);
	ret = write(STDERR_FILENO, hex, ft_strlen(hex));
	free(hex);
	return (ret);
}

ssize_t	xu_func(va_list ap)
{
	ssize_t			ret;
	unsigned int	u;
	char			*hex;
	const char		*to_hex = "0123456789ABCDEF";

	u = va_arg(ap, unsigned int);
	hex = itoh(u, to_hex, 0);
	if (hex == 0)
		return (-1);
	ret = write(STDERR_FILENO, hex, ft_strlen(hex));
	free(hex);
	return (ret);
}

ssize_t	percent_func(va_list ap)
{
	ssize_t	ret;

	if (ap == NULL)
		return (-1);
	ret = write(STDERR_FILENO, "%", 1);
	return (ret);
}
