/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 05:20:19 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/21 05:39:42 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	res = malloc(len_s + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	substr_len;
	char	*res;
	size_t	i;

	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	substr_len = slen - start;
	if (substr_len > len)
		substr_len = len;
	res = malloc(substr_len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < substr_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
