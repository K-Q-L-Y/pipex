/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:19:27 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/02/26 09:20:41 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	len;

	if (n < 1)
		return (0);
	len = 0;
	while (*s1 != '\0' && *s1 == *s2 && len + 1 < n)
	{
		s1++;
		s2++;
		len++;
	}
	diff = *(unsigned char *)s1 - *(unsigned char *)s2;
	return (diff);
}
