/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:20:14 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/04 13:43:12 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	dstsize;

	if (!s)
		return (0);
	dstsize = 0;
	while (dstsize < len + start && s[dstsize])
		dstsize++;
	if (dstsize < start)
		return ((char *)ft_calloc(1, sizeof(char)));
	dstsize = dstsize - start + 1;
	s = s + start;
	ret = malloc(sizeof(char) * dstsize);
	if (!ret)
		return (0);
	ft_strlcpy(ret, s, dstsize);
	return (ret);
}
