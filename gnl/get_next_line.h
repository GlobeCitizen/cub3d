/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:24:12 by mahnich           #+#    #+#             */
/*   Updated: 2020/01/09 19:50:59 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_SIZE 2048
# define ERROR -1
# define NEXTLINE 1
# define EF 0

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char const *s, int c);
size_t	ft_strlen(char const *s);
char	*ft_strnew(size_t len);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strcpy(char *dst, char const *src);

#endif
