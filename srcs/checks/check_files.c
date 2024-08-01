/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:47:40 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/30 22:33:14 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	get_infile(char *file)
{
	int	fd;

	if (access(file, F_OK) == -1)
	{
		perror(file);
		return (-1);
	}
	else if (access(file, R_OK) == -1)
		exit_perror(file, 0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_perror(file, 1);
	return (fd);
}

int	get_outfile(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_perror(file, 1);
	return (fd);
}
