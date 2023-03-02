/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:56:25 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/25 16:01:43 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sig_handler(int signo)
{
	(void)signo;
	printf("minishell$ \n");
	if (rl_on_new_line() == -1)
		exit(1);
	rl_replace_line("", 1);
	rl_redisplay();
	g_gb.exit_status = 1;
}

int	set_term(int init, int is_status)
{
	if (init)
	{
		if (tcgetattr(STDIN_FILENO, &g_gb.term) == -1)
			return (EXIT_FAILURE);
	}
	if (!is_status)
		g_gb.term.c_lflag &= ~(ECHOCTL);
	else
		g_gb.term.c_lflag |= ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &g_gb.term) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	set_signal(int is_status)
{
	if (!is_status)
	{
		if (signal(SIGINT, sig_handler) == SIG_ERR || \
			signal(SIGQUIT, SIG_IGN) == SIG_ERR)
			return (EXIT_FAILURE);
	}
	else
	{
		if (signal(SIGINT, SIG_DFL) == SIG_ERR || \
			signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
