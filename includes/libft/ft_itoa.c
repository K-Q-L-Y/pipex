/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:58:00 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/02/27 11:50:30 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_size(int n)
{
	size_t	size;

	size = 0;
	while (n)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*nb;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!n)
		return (ft_strdup("0"));
	sign = (n > 0) - (n < 0);
	n = n * (n > 0) - n * (n < 0);
	size = get_size(n) + (sign < 0);
	nb = malloc((size + 1) * sizeof(char));
	if (!nb)
		return (0);
	nb[size--] = 0;
	while (n)
	{
		nb[size] = n % 10 + '0';
		n /= 10;
		size--;
	}
	if (sign < 0)
		nb[0] = '-';
	return (nb);
}
