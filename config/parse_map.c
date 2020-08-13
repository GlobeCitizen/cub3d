/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 17:08:49 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/13 21:20:28 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int		count_rows_colomuns(t_config *config, const char *conf_path)
{
	int		c_fd2;
	char	*line2;

	if((c_fd2 = open(conf_path, O_RDONLY)) < 0)
		return (0);
	while (get_next_line(c_fd2, &line2))
	{
		if (line2[0] != 'R' && ft_strncmp(line2, "NO", 2) &&
				ft_strncmp(line2, "SO", 2) && ft_strncmp(line2, "WE", 2) &&
				ft_strncmp(line2, "EA", 2) && line2[0] != 'S' && line2[0] != 'C'
				&& line2[0] != 'F' && line2[0] != 0)
		{
			if (config->colomuns < ft_strlen(line2))
				config->colomuns = ft_strlen(line2);
			config->rows++;
		}
		free(line2);
	}
	free(line2);
	close(c_fd2);
	return (1);
}

int		initialize_map(t_config *config)
{
	int	i;
	int	j;

	i = 0;
	if (!(config->map_buffer = (int **)malloc(sizeof(int) * config->rows)))
		return (0);
	while (i < config->rows)
	{
		j = 0;
		if (!(config->map_buffer[i] = (int *)malloc(sizeof(int) * config->colomuns)))
			return (0);
		while (j < config->colomuns)
			config->map_buffer[i][j++] = -1;
		i++;
	}
	return (1);
}

int		fill_map(t_config *config, char *line)
{
	int		i;
	int		r;

	i = 0;
	r = 1;

	while (i < ft_strlen(line))
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2')
			config->map_buffer[config->rows2][i] = line[i] - 48;
		else if (line[i] == 'N')
			config->map_buffer[config->rows2][i] = 8;
		else if (line[i] == 'S')
			config->map_buffer[config->rows2][i] = 5;
		else if (line[i] == 'W')
			config->map_buffer[config->rows2][i] = 4;
		else if (line[i] == 'E')
			config->map_buffer[config->rows2][i] = 6;
		else if (line[i] == ' ')
			config->map_buffer[config->rows2][i] = -1;
		else
			r = 0;
		printf("ici2 i ==[%i] and j == [%i]\n", config->rows2 , i);
		i++;
	}
	config->rows2++;

	return (r);
}

int		parse_map(t_config *config, char *line)
{
//	if (line[0] != 'R' && ft_strncmp(line, "NO", 2) &&
//			ft_strncmp(line, "SO", 2) && ft_strncmp(line, "WE", 2) &&
//			ft_strncmp(line, "EA", 2) && line[0] != 'S' && line[0] != 'C'
//			&& line[0] != 'F' && line[0] != 0)
//	{
//		fill_map(config, line);
//	}
	return (1);
}
