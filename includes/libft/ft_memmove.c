/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:05:01 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/04 11:38:53 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	if (!dst && !src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		while (len-- > 0)
			s1[len] = s2[len];
	}
	return (s1);
}
