/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:26:28 by salee2            #+#    #+#             */
/*   Updated: 2022/07/11 18:02:10 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (-10 < n && n < 10)
	{
		ft_putchar_fd(sign * n + '0', fd);
		return ;
	}
	ft_putnbr_fd(n / 10 * sign, fd);
	ft_putchar_fd(n % 10 * sign + '0', fd);
	return ;
}
