/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:42:53 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/23 17:43:15 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_parse_error(char *str, t_tkn *token, int not_tkn)
{
	if (!not_tkn)
		ft_perror(str);
	else if (!token)
		ft_perror(str, "newline");
	else
		ft_perror(str, token->str);
	g_gb.exit_status = 258;
	return (EXIT_FAILURE);
}

int	ft_lexer_error(char *str, char *token)
{
	ft_perror(str, token);
	g_gb.exit_status = 258;
	return (EXIT_FAILURE);
}

int	ft_malloc_error(void)
{
	ft_perror("minishell: %s\n", strerror(errno));
	g_gb.exit_status = errno;
	return (EXIT_FAILURE);
}

void	heredoc_input_eof(int c_line, char *eof)
{
	ft_perror("minishell: warning: here-document at line %d ", c_line);
	ft_perror("delimited by end-of-file (wanted `%s')\n", eof);
}
