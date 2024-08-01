/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:37:17 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/02/26 12:03:17 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)str;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == ch)
			return (ptr);
		ptr++;
		i++;
	}
	return (0);
}
