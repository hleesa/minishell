/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:58:46 by salee2            #+#    #+#             */
/*   Updated: 2023/02/21 14:58:48 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PERROR_H
# define FT_PERROR_H

# include <stdarg.h>
# include  "../../includes/minishell.h"

# define HEX_LEN 19

ssize_t	c_func(va_list ap);
ssize_t	s_func(va_list ap);
ssize_t	p_func(va_list ap);
ssize_t	d_func(va_list ap);
ssize_t	i_func(va_list ap);
ssize_t	u_func(va_list ap);
ssize_t	xl_func(va_list ap);
ssize_t	xu_func(va_list ap);
ssize_t	percent_func(va_list ap);
void	set_func_num(int *to_func_num);
void	set_num_to_func(ssize_t	(*num_to_func[9])());
int		is_error(const char *format, int *to_func_num);
int		print_format(const char *format, va_list ap, \
		int *to_func_num, ssize_t (*num_to_func[9])(va_list));
char	*ft_utoa(unsigned int n);
char	*itoh(unsigned long long num, const char *to_hex, int is_addr);
int		ft_perror(const char *format, ...);

#endif //FT_PERROR_H
