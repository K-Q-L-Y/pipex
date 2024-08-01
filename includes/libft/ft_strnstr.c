/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:34:23 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/04 14:06:02 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	searched;

	if (!*needle)
		return ((char *)haystack);
	if (!haystack && !len)
		return (0);
	searched = 0;
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && searched + i < len)
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack);
			i++;
		}
		searched++;
		haystack++;
	}
	return (0);
}
