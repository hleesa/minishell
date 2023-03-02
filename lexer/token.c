/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:09:35 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/11 20:01:37 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_tkn	*tkn_new(t_tkn_type tkn_tp, char *str)
{
	t_tkn	*new_tkn;

	new_tkn = (t_tkn *)malloc(sizeof(t_tkn));
	if (!new_tkn)
		return (NULL);
	new_tkn->tkn_tp = tkn_tp;
	new_tkn->str = str;
	new_tkn->next = NULL;
	return (new_tkn);
}

t_tkn	*tkn_last(t_tkn *list_tkn)
{
	t_tkn	*last;

	if (!list_tkn)
		return (list_tkn);
	while (list_tkn->next)
		list_tkn = list_tkn->next;
	last = list_tkn;
	return (last);
}

void	tkn_add_back(t_tkn **list_tkn, t_tkn *new_tkn)
{
	t_tkn	*t_temp;

	if (!*list_tkn)
	{
		*list_tkn = new_tkn;
		return ;
	}
	t_temp = tkn_last(*list_tkn);
	t_temp->next = new_tkn;
}

int	tkn_size(t_tkn *tkn_list)
{
	int	size;

	size = 0;
	while (tkn_list)
	{
		tkn_list = tkn_list->next;
		size++;
	}
	return (size);
}

t_tkn	*tkn_search(t_tkn *list_tkn, t_tkn_type tkn_tp)
{
	while (list_tkn)
	{
		if (list_tkn->tkn_tp == tkn_tp)
			return (list_tkn);
		list_tkn = list_tkn->next;
	}
	return (NULL);
}
