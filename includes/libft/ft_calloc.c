/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:47:34 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/02/26 12:39:55 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (!count || !size)
	{
		a = malloc(0);
		return (a);
	}
	if (count > INT_MAX / size)
		return (0);
	a = malloc(count * size);
	if (!a)
		return (0);
	ft_bzero(a, count * size);
	return (a);
}
