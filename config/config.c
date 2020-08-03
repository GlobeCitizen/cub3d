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
#include "../libft/libft.h"

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

	i = 0;
	config->requested_width = 0;
	while (i < 4)
		config->textures[i++] = 0;
	i = 0;
	while (i < 2)
		config->colors[i++] = 0;
	config->rows = 0;
	config->colomuns = 0;
}

void	parse_resolution(t_config *config, char	*line)
{
	char	**resolution;

	resolution = ft_split(line, ' ');
	config->requested_width  = ft_atoi(resolution[1]);
	config->requested_height = ft_atoi(resolution[2]);
	free_split(resolution);
}

void	parse_textures(t_config *config, char *line)
{
	char	**textures;

	textures = ft_split(line, ' ');
	if (!strncmp(line,"NO", 2))
		config->textures[0] = ft_strdup(textures[1]);
	free_split(textures);
}

void		parse_colors(t_config *config, char *line)
{

}

void	free_config(t_config *config)
{

}

int		parse_config(t_config *config, const char *conf_path)
{
	int		c_fd;
	int		r;
	char	*line;

	if ((c_fd = open(conf_path, O_RDONLY)) < 0)
		return (0);
	while(get_next_line(c_fd, &line))
	{
		if (!strncmp(line, "R", 1))
			parse_resolution(config, line);
		else if (!strncmp(line,"NO", 2) || !strncmp(line, "SO", 2) ||
				!strncmp(line, "WE", 2) || !strncmp(line, "EA", 2))
			parse_textures(config, line);
//		else if (!strncmp(line, "C", 1) || !strncmp(line, "F", 1))
//			parse_colors(config, line);
//		if (config_valid(config))
//			break;
		free(line);
	}
	free(line);
	close(c_fd);
	return (1);
}

int main()
{
	t_config	*config;
	
	if (!(config = (t_config *)malloc(sizeof(t_config))))
		return (0);
	init_config(config);
	parse_config(config, "../maps/first.cub");
	printf("width == %i\n", config->requested_width);
	printf("height  == %i\n", config->requested_height);
	printf("north textures == %s", config->textures[0]);
	free_config(config);
	system("leaks a.out");
}
