/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:48 by salee2            #+#    #+#             */
/*   Updated: 2022/07/13 16:29:06 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(temp, del);
	}
	return ;
}
