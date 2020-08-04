/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:36:49 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/03 20:34:40 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

void	init_config(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	config->requested_width = 0;
	config->requested_height = 0;
	while (i < 5)
		config->textures[i++] = NULL;
	i = -1;
	while (i++ < 2)
	{
		j = 0;
		while(j < 3)
			config->colors[i][j++] = -1;
	}
	config->rows = 0;
	config->colomuns = 0;
}

int		check_config(t_config *config)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 1;
	if (config->requested_height != 0 && config->requested_width != 0)
	{
		while (i < 5)
			flag = flag * (config->textures[i++] != NULL);
		i = -1;
		while (i++ < 2)
		{
			j = 0;
			while (j < 3)
			flag = flag * (config->colors[i][j++] >= 0 && config->colors[i][j++] <= 255);
		}
		return (flag);
	}
	return (0);
}

int		parse_config(t_config *config, const char *conf_path)
{
	int		c_fd;
	char	*line;

	if ((c_fd = open(conf_path, O_RDONLY)) < 0)
		return (0);
	while(get_next_line(c_fd, &line))
	{
		if (!ft_strncmp(line, "R", 1))
			parse_resolution(config, line);
		else if (!strncmp(line,"NO", 2) || !strncmp(line, "SO", 2) ||
				!strncmp(line, "WE", 2) || !strncmp(line, "EA", 2))
			parse_textures(config, line);
		else if (!strncmp(line, "C", 1) || !strncmp(line, "F", 1))
			parse_colors(config, line);
		if (check_config(config))
			break;
		free(line);

	}
	free(line);
	close(c_fd);
	return (0);
}

int main()
{
	t_config	*config;
	
	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (0);
	init_config(config);
	parse_config(config, "../maps/first.cub");
	free(config);
}
