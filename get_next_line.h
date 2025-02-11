/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpancar <bpancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:34:34 by bpancar           #+#    #+#             */
/*   Updated: 2025/01/08 15:59:13 by bpancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef    BUFFER_SIZE
#  define   BUFFER_SIZE 42
# endif

# include <stdlib.h>

void	ft_bzero(void *str, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *src);
void	*ft_calloc(size_t count, size_t size);

#endif