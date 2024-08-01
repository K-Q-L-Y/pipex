/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 21:06:43 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/29 19:43:18 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char **paths, char *cmd)
{
	char	*cmd_path;
	char	*slash_cmd;
	int		i;

	i = -1;
	slash_cmd = ft_strjoin("/", cmd);
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], slash_cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			free(slash_cmd);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free(slash_cmd);
	exit_command_not_found(cmd);
	exit_code(1);
	return (0);
}
