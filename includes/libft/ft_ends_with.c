/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ends_with.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:58:51 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/29 17:59:06 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ends_with(char *s, char *end)
{
	int	i;
	int	j;

	if (!s || !end)
		return (0);
	i = ft_strlen(s) - 1;
	j = ft_strlen(end) - 1;
	if (i < j)
		return (0);
	while (j >= 0)
	{
		if (s[i] != end[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}
