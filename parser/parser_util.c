/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 18:54:42 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/02 20:17:34 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_redirect_token(t_tkn *list_tkn)
{
	if (list_tkn->tkn_tp == SGL_IN || list_tkn->tkn_tp == DB_IN \
	|| list_tkn->tkn_tp == SGL_OUT || list_tkn->tkn_tp == DB_OUT)
		return (RTN_TRUE);
	return (RTN_FALSE);
}
