/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <mahnich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:36:49 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/18 21:59:33 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

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
	while (i++ < 1)
	{
		j = 0;
		while (j < 3)
			config->colors[i][j++] = -1;
	}
	config->rows = 0;
	config->rows2 = 0;
	config->colomuns = 0;
	config->ceil = 0;
	config->floor = 0;
}

void	clear_config(t_config *config)
{
	int		i;

	i = 0;
	while (i < 5)
		free(config->textures[i++]);
}

int		main_parser(t_config *config, const char *conf_path)
{
	int		c_fd;
	char	*line;
	int		r;
	int		r2;
	
	r = 1;
	r2 = 1;
	count_rows_colomuns(config, conf_path);
	if ((c_fd = open(conf_path, O_RDONLY)) < 0)
		return (0);
	r *= initialize_map(config);
	while (get_next_line(c_fd, &line))
	{
		r *= parse_config(config, line);
		r2 *= parse_map(config, line);
		free(line);
	}
	free(line);
	if (!r || !check_config(config) || !r2)
	{
		print_error_free(config);
		print_error_map(r2, config);
		return (0);
	}
	close(c_fd);
	return (r * r2);
}

int		parse_config_map(const char *map_path)
{
	t_config	*config;
	int			r;

	r = 1;
	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (0);
	init_config(config);
	r = main_parser(config, map_path);
	return (r);
}
