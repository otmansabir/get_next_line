/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osabir <osabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:44:21 by osabir            #+#    #+#             */
/*   Updated: 2022/12/24 18:17:36 by osabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char			*get_next_line(int fd);
void			*ft_calloc(size_t count, size_t size);
void			ft_memset(void *b, int c, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
// void			*ft_calloc(size_t count, size_t size);
// void			*ft_memset(void *b, int c, size_t len);

#endif
