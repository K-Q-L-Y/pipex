/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseng-kh <cseng-kh@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:47:19 by cseng-kh          #+#    #+#             */
/*   Updated: 2024/07/09 10:48:37 by cseng-kh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strspn(const char *str, const char *delim)
{
	const char	*s;
	const char	*d;
	size_t		count;

	s = str;
	count = 0;
	while (*s)
	{
		d = delim;
		while (*d)
		{
			if (*s == *d)
				break ;
			d++;
		}
		if (*d == '\0')
			return (count);
		count++;
		s++;
	}
	return (count);
}

static size_t	ft_strcspn(const char *str, const char *delim)
{
	const char	*s;
	const char	*d;

	s = str;
	while (*s)
	{
		d = delim;
		while (*d)
		{
			if (*s == *d)
				return (s - str);
			d++;
		}
		s++;
	}
	return (s - str);
}

char	*ft_strtok(char *str, const char *delim)
{
	char		*token;
	static char	*last_token = NULL;

	if (str == NULL && last_token == NULL)
		return (NULL);
	if (str != NULL)
		last_token = str;
	token = last_token;
	token += ft_strspn(token, delim);
	if (*token == '\0')
	{
		last_token = NULL;
		return (NULL);
	}
	last_token = token + ft_strcspn(token, delim);
	if (*last_token != '\0')
	{
		*last_token = '\0';
		last_token++;
	}
	else
		last_token = NULL;
	return (token);
}
