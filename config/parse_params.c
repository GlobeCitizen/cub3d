/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:33:42 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/03 15:36:38 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int		parse_resolution(t_config *config, char *line)
{
	char	**resolution;

	if (config->requested_width != 0 || config->requested_height != 0)
		return (0);
	resolution = ft_split(line, ' ');
	config->requested_width = ft_atoi(resolution[1]);
	config->requested_height = ft_atoi(resolution[2]);
	free_split(resolution);
	if (config->requested_height <= 0 || config->requested_height > 1080 ||
		config->requested_width <= 0 || config->requested_width > 1920)
	{
		config->requested_height = 1080;
		config->requested_width = 1920;
	}
	return (1);
}

int		check_duplicate_textures(t_config *config, char *line)
{
	if (!ft_strncmp(line, "NO", 2) && config->textures[0] != NULL)
		return (0);
	else if (!ft_strncmp(line, "SO", 2) && config->textures[1] != NULL)
		return (0);
	else if (!ft_strncmp(line, "WE", 2) && config->textures[2] != NULL)
		return (0);
	else if (!ft_strncmp(line, "EA", 2) && config->textures[3] != NULL)
		return (0);
	else if (line[0] == 'S' && config->textures[4] != NULL)
		return (0);
	return (1);
}

int		parse_textures(t_config *config, char *line)
{
	char	**textures;

	if (!check_duplicate_textures(config, line))
	{
		write(1, "Error : Textures Duplicate!\n", 30);
		return (0);
	}
	textures = ft_split(line, ' ');
	if (!ft_strncmp(line, "NO", 2))
		config->textures[0] = ft_strdup(textures[1]);
	else if (!ft_strncmp(line, "SO", 2))
		config->textures[1] = ft_strdup(textures[1]);
	else if (!ft_strncmp(line, "WE", 2))
		config->textures[2] = ft_strdup(textures[1]);
	else if (!ft_strncmp(line, "EA", 2))
		config->textures[3] = ft_strdup(textures[1]);
	else if (!ft_strncmp(line, "S", 1))
		config->textures[4] = ft_strdup(textures[1]);
	free_split(textures);
	return (1);
}

int		parse_colors(t_config *config, char *line)
{
	char	**colors;

	colors = ft_split(line, ',');
	if (!ft_strncmp(line, "F", 1))
	{
		config->colors[0][0] = ft_atoi(colors[0] + 1);
		config->colors[0][1] = ft_atoi(colors[1]);
		config->colors[0][2] = ft_atoi(colors[2]);
		config->floor++;
	}
	if (!ft_strncmp(line, "C", 1))
	{
		config->colors[1][0] = ft_atoi(colors[0] + 1);
		config->colors[1][1] = ft_atoi(colors[1]);
		config->colors[1][2] = ft_atoi(colors[2]);
		config->ceil++;
	}
	free_split(colors);
	if (config->ceil > 1 || config->floor > 1)
		return (0);
	return (1);
}
