/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2n@student.42seoul.k>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:45:22 by salee2            #+#    #+#             */
/*   Updated: 2022/07/14 19:22:08 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*new_lst;

	if (lst == 0)
		return (0);
	ret = 0;
	while (lst)
	{
		new_lst = ft_lstnew(f(lst->content));
		if (new_lst == 0)
		{
			if (del != 0)
				ft_lstclear(&ret, del);
			return (0);
		}
		ft_lstadd_back(&ret, new_lst);
		lst = lst->next;
	}
	return (ret);
}
