/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:44:43 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/29 22:03:41 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_command(char *cmd, char **paths, int is_last)
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	cmd_path = get_command_path(paths, args[0]);
	ft_free_split(ft_count_occurence(cmd, ' ') + 1, args);
	if (!cmd_path)
	{
		if (is_last)
			exit(127);
		else
			return (0);
	}
	free(cmd_path);
	return (1);
}
