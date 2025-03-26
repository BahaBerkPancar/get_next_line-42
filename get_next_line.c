/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:34:25 by bpancar           #+#    #+#             */
/*   Updated: 2025/03/26 05:54:07 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char *leak_check(char *s)
{
	if(!*s || !s || s[0] == '\n')
	{
		free(s);
		return(NULL);
	}
	else
		return(s);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*s_str;

	s_str = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		s_str[i] = 0;
		i++;
	}
}

char	*ft_read(int fd, char *str)
{
	char	*readstr;
	int		byte;
	char	*tmp;

	readstr = ft_calloc(BUFFER_SIZE + 1, 1);
	byte = 1;
	if (!str)
		str = ft_strdup("");
	while (ft_strchr(readstr, '\n') == 0 && byte > 0)
	{
		byte = read(fd, readstr, BUFFER_SIZE);
		if ((byte == -1) || (byte == 0 && !str[0]))
			return (free(readstr), free(str), NULL);
		readstr[byte] = '\0';
		tmp = str;
		str = ft_strjoin(str, readstr);
		free(tmp);
	}
	return (free(readstr), str);
}

char	*get_next_line(int fd)
{
	static char	*afterstr;
	int			j;
	char		*beforestr;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	beforestr = NULL;
	j = -1;
	afterstr = ft_read(fd, afterstr);
	while (afterstr && afterstr[++j])
	{
		if (afterstr[j] == '\n' || afterstr[j + 1] == '\0')
		{
			j++;
			beforestr = ft_substr(afterstr, 0, j);
			temp = afterstr;
			afterstr = ft_strdup(afterstr + j);
			afterstr = leak_check(afterstr);
			return (free(temp), beforestr);
		}
	}
	return (beforestr);
}
