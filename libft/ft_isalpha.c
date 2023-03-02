/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:37:31 by salee2            #+#    #+#             */
/*   Updated: 2022/07/04 15:37:53 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (isupper(c) || islower(c))
		return (1);
	return (0);
}
