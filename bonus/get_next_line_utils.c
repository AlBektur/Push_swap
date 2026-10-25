/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 23:51:52 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/25 04:35:21 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bonus_header.h"

static int	ft_str_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*my_strdup(char *s)
{
	int		i;
	char	*res;
	int		len;

	if (!s)
		return (NULL);
	len = ft_str_len(s);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*substr(char *str, int index)
{
	int		i;
	char	*res;

	res = malloc((sizeof(char) * index) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < index)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*res;
	int			size;
	int			i;
	int			j;

	size = ft_str_len(s1) + ft_str_len(s2);
	res = malloc(sizeof(char) * size + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
