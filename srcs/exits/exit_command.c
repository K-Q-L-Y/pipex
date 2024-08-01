/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:30:01 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/29 19:35:04 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_command_not_found(char *cmd)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": command not found", 2);
}
