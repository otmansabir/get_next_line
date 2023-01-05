/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:02:08 by osabir            #+#    #+#             */
/*   Updated: 2022/12/25 18:58:31 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_memset((char *)str, 0, (count * size));
	return ((char *)str);
}

void	ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			j;

	str = (unsigned char *)b;
	j = 0;
	while (j < len)
	{
		str[j] = (unsigned char)c;
		j++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (NULL);
	j = ft_strlen(s);
	i = 0;
	if (start >= j)
		start = j;
	if (len > j - start)
		len = (j - start);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	if (s)
	{
		while (i < len && s[start])
			str[i++] = s[start++];
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	int		j;

	j = 0;
	while (s[j] != '\0' && s[j] != (char)c)
	j++;
	if (s[j] == (char)c)
		return ((char *)(s + j));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	j;

	j = 0;
	while (s[j] != '\0')
		j++;
	return (j);
}
