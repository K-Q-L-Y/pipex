/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:37:20 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/29 19:41:16 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_code(int overwrite_code)
{
	static int	code = 0;

	if (overwrite_code > 0)
		code = overwrite_code;
	return (code);
}
