/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:44:07 by mahnich           #+#    #+#             */
/*   Updated: 2020/01/16 20:56:53 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t len)
{
	char	*p;

	p = s;
	while (len--)
	{
		*p = '\0';
		p++;
	}
}

char	*ft_strcpy(char *dst, char const *src)
{
	char	*p;

	p = dst;
	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*str;

	if (!(str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (NULL);
	ft_strcpy(str, s1);
	return (str);
}

int		verify_line(char *fdcontent, char **line)
{
	char	*heap;
	int		i;

	i = 0;
	if (ft_strchr(fdcontent, '\n'))
	{
		heap = ft_strdup(fdcontent);
		fdcontent = ft_strcpy(fdcontent, &ft_strchr(fdcontent, '\n')[1]);
		while (heap[i] != '\n')
			i++;
		heap[i] = 0;
		*line = ft_strjoin(*line, heap);
		free(heap);
		return (1);
	}
	else
	{
		*line = ft_strjoin(*line, fdcontent);
		ft_bzero(fdcontent, BUFFER_SIZE);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char	fdcontent[FD_SIZE][BUFFER_SIZE + 1];
	int			ret;
	char		c;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd >= FD_SIZE ||
			read(fd, &c, 0) == -1)
		return (ERROR);
	*line = ft_strnew(0);
	if (*fdcontent[fd])
		if (verify_line(fdcontent[fd], line))
			return (NEXTLINE);
	while ((ret = read(fd, fdcontent[fd], BUFFER_SIZE)))
	{
		if (ret < 0)
			return (ERROR);
		fdcontent[fd][ret] = 0;
		if (verify_line(fdcontent[fd], line))
			return (NEXTLINE);
	}
	return (EF);
}
