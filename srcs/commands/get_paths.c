/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:10:33 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/25 21:38:32 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*extract_path(char **envp)
{
	char	*path;
	int		i;

	path = NULL;
	i = -1;
	while (envp[++i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			break ;
		}
	}
	return (path);
}

char	**get_paths(char **envp)
{
	char	*path;
	char	*token;
	char	**ret;
	int		i;

	path = extract_path(envp);
	if (path != NULL)
	{
		ret = ft_calloc(sizeof(char *), ft_count_occurence(path, ':') + 2);
		token = ft_strtok(path, ":");
		i = -1;
		while (token != NULL)
		{
			ret[++i] = ft_strdup(token);
			token = ft_strtok(NULL, ":");
		}
	}
	return (ret);
}
