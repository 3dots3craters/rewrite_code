/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hayelee <hayelee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:08:49 by hayelee           #+#    #+#             */
/*   Updated: 2021/07/03 16:57:57 by hayelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10
# endif 

int		get_next_line(int fd, char **line);
int		check_save(char **save);
int		make_last_line(char **save, char **line);
int		make_save_or_eof(char **save, char **line, char *buf, int read_byte);
int		make_line_and_save(char **save, char **line);
int		ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
