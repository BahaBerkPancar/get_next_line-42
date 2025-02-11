/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:34:21 by bpancar           #+#    #+#             */
/*   Updated: 2025/01/08 15:59:10 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	a = (void *)malloc(count * size);
	if (a == NULL)
		return (NULL);
	ft_bzero(a, (count * size));
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*src;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if ((len > ft_strlen(s + start)))
		len = ft_strlen(s + start);
	src = malloc(sizeof(char) * (len + 1));
	if (!src)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			src[j] = s[i];
			j++;
		}
		i++;
	}
	src[j] = '\0';
	return (src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	char	*str;
	int		i;
	int		b;

	a = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(a + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	b = 0;
	while (s2[b])
	{
		str[i] = s2[b];
		b++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	if ((char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
