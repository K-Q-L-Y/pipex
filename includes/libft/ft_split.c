/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:47:48 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/29 10:13:57 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	**arr;

	if (!s)
		return (0);
	i = -1;
	count = 0;
	while (s[++i] != 0)
		count += (s[i] != c && (s[i + 1] == c || !s[i + 1]));
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	while (i < count && *s)
	{
		while (*s == c)
			s++;
		arr[i] = ft_substr(s, 0, word_len(s, c));
		s += word_len(s, c);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
