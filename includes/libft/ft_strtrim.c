/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:55:56 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/04 14:14:23 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;

	if (!s1 || !set)
		return (ft_calloc(0, 0));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	if (!s1)
		return (ft_calloc(0, 0));
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size - 1]))
		size--;
	return (ft_substr(s1, 0, size));
}
