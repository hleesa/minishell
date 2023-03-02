/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:21:57 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/26 19:36:15 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_token(t_tkn *list_tkn)
{
	while (list_tkn)
	{
		printf("TYPE: ");
		if (list_tkn->tkn_tp == WORD)
			printf("%-14s", "WORD");
		else if (list_tkn->tkn_tp == SGL_IN)
			printf("%-14s", "SINGLE_INPUT");
		else if (list_tkn->tkn_tp == DB_IN)
			printf("%-14s", "DOUBLE_INPUT");
		else if (list_tkn->tkn_tp == SGL_OUT)
			printf("%-14s", "SINGLE_OUTPUT");
		else if (list_tkn->tkn_tp == DB_OUT)
			printf("%-14s", "DOUBLE_OUTPUT");
		else if (list_tkn->tkn_tp == PIPE)
			printf("%-14s", "PIPE");
		else if (list_tkn->tkn_tp == OR_IF)
			printf("%-14s", "OR_IF");
		else if (list_tkn->tkn_tp == AND_IF)
			printf("%-14s", "AND_IF");
		else if (list_tkn->tkn_tp == START_SUB)
			printf("%-14s", "START_SUBSHELL");
		else if (list_tkn->tkn_tp == END_SUB)
			printf("%-14s", "END_SUBSHELL");
		printf(" / STRING: \"%s\"\n", list_tkn->str);
		list_tkn = list_tkn->next;
	}
}

void	print_node(t_pst *tree)
{
	if (tree->pst_pt == COMPLETE_CMD)
		printf("%s\n", "COMPLETE_CMD");
	else if (tree->pst_pt == LIST)
		printf("%s\n", "LIST");
	else if (tree->pst_pt == AND_IF_LIST)
		printf("%s\n", "AND_IF_LIST");
	else if (tree->pst_pt == OR_IF_LIST)
		printf("%s\n", "OR_IF_LIST");
	else if (tree->pst_pt == PIPELINE)
		printf("%s\n", "PIPELINE");
	else if (tree->pst_pt == SUBSHELL)
		printf("%s\n", "SUBSHELL");
	else if (tree->pst_pt == SIMPLE_CMD)
		printf("%s\n", "SIMPLE_CMD");
	else if (tree->pst_pt == REDIRECT_LIST)
		printf("%s\n", "REDIRECT_LIST");
	else if (tree->pst_pt == CMD_SUFFIX)
		printf("%s\n", "CMD_SUFFIX");
	else if (tree->pst_pt == SUFFIX)
		printf("%s\n", "SUFFIX");
	else if (tree->pst_pt == IO_REDIRECT)
		printf("%s / \"%s\", \"%s\"\n", "IO_REDIRECT", \
			tree->list_tkn->str, tree->list_tkn->next->str);
	else if (tree->pst_pt == ARGV)
		printf("%s / \"%s\"\n", "ARGV", tree->list_tkn->str);
	else if (tree->pst_pt == CMD_NAME)
		printf("%s / \"%s\"\n", "CMD_NAME", tree->list_tkn->str);
}

void	print_tree(t_pst *tree, int n)
{
	int	idx;

	if (!tree)
		return ;
	print_tree(tree->right, n + 1);
	if (n)
	{
		idx = n + 1;
		while (--idx)
		{
			printf("    ");
		}
		printf("-> ");
	}
	print_node(tree);
	print_tree(tree->left, n + 1);
}
