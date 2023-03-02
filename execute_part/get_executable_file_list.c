/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_executable_file_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salee2 <salee2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:06:40 by salee2            #+#    #+#             */
/*   Updated: 2023/01/19 20:06:41 by salee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_getenv(const char *name, char **env)
{
	while (*env)
	{
		if (ft_strncmp(name, *env, ft_strlen(name)) == SAME)
			return (*(env) + ft_strlen(name) + 1);
		++env;
	}
	return (NULL);
}

char	**get_env_list(const char *name, char **env)
{
	return (ft_split(ft_getenv(name, env), ':'));
}

char	**get_executable_file_list(const char *name, char *file_name, \
char **env)
{
	int		i;
	char	**file_list;
	char	*temp;

	file_list = get_env_list(name, env);
	i = -1;
	while (file_list[++i])
	{
		temp = file_list[i];
		file_list[i] = ft_strjoin(file_list[i], "/");
		free(temp);
		temp = file_list[i];
		file_list[i] = ft_strjoin(file_list[i], file_name);
		free(temp);
	}
	return (file_list);
}
