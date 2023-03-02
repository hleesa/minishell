/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doohkim <doohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 20:10:26 by doohkim           #+#    #+#             */
/*   Updated: 2023/02/19 16:55:05 by doohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

# define E_TKN "minishell: syntax error near unexpected token `%s'\n"
# define E_EOF "minishell: syntax error: unexpected end of file\n"
# define E_EOF_TKN "minishell: unexpected EOF while looking for matching `%s'\n"

# define RTN_TRUE 1
# define RTN_FALSE 0
# define BUILTIN_SIZE 7

#endif