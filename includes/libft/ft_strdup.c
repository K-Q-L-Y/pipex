/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:34 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/03/04 09:26:46 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	size;

	size = ft_strlen(s1) + 1;
	a = malloc(size * sizeof(char));
	if (!a)
		return (0);
	ft_strlcpy(a, s1, size);
	return (a);
}
