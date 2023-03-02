/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:40:15 by salee2            #+#    #+#             */
/*   Updated: 2023/02/26 16:34:56 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	write_temp_file(char *temp_file_path, char *eof)
{
	char	*input;
	int		temp_file_fd;
	int		c_line;

	temp_file_fd = open(temp_file_path, O_RDWR | O_CREAT | O_TRUNC, 0644);
	exit_if_open_error(temp_file_fd, temp_file_path);
	c_line = 0;
	while (TRUE)
	{
		input = readline("> ");
		c_line++;
		if (input == NULL)
		{
			heredoc_input_eof(c_line, eof);
			break ;
		}
		if (ft_strcmp(input, eof) == SAME)
		{
			free(input);
			break ;
		}
		ft_putendl_fd(input, temp_file_fd);
		free(input);
	}
	close(temp_file_fd);
}

void	write_heredoc_temp_child(char *temp_file_path, char *eof)
{
	set_term(0, 0);
	signal(SIGINT, SIG_DFL);
	write_temp_file(temp_file_path, eof);
	exit(EXIT_SUCCESS);
}

int	write_heredoc_temp_parent(void)
{
	wait(&g_gb.exit_status);
	if (WIFEXITED(g_gb.exit_status))
		g_gb.exit_status = WEXITSTATUS(g_gb.exit_status);
	else if (WIFSIGNALED(g_gb.exit_status))
	{
		g_gb.exit_status |= 128;
		printf("\n");
	}
	return (g_gb.exit_status);
}

int	write_heredoc_temp(t_pst *tree)
{
	int		ret;
	pid_t	pid;
	char	*eof;
	char	*temp_file_path;

	ret = 0;
	eof = tree->list_tkn->next->str;
	temp_file_path = ft_mktemp();
	if (temp_file_path == NULL)
		exit(EXIT_FAILURE);
	pid = fork_exit_if_error();
	if (pid == CHILD)
		write_heredoc_temp_child(temp_file_path, eof);
	else
		ret = write_heredoc_temp_parent();
	(*(&tree))->list_tkn->next->str = temp_file_path;
	free(eof);
	return (ret);
}

int	execute_heredoc(t_pst *tree)
{
	int	ret;

	ret = 0;
	if (tree->pst_pt == IO_REDIRECT && tree->list_tkn->tkn_tp == DB_IN)
		return (write_heredoc_temp(tree));
	if (tree->left)
		ret += execute_heredoc(tree->left);
	if (tree->right)
		ret += execute_heredoc(tree->right);
	return (ret);
}
