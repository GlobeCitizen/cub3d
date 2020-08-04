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
	char    **textures;

	textures = ft_split(line, ' ');
	if (!strncmp(line, "NO", 2))
		config->textures[0] = ft_strdup(textures[1]);
    else if (!strncmp(line, "SO", 2))
        config->textures[1] = ft_strdup(textures[1]);
    else if (!strncmp(line, "WE", 2))
        config->textures[2] = ft_strdup(textures[1]);
    else if (!strncmp(line, "EA", 2))
        config->textures[3] = ft_strdup(textures[1]);
    else if (!strncmp(line, "S", 1))
        config->textures[4] = ft_strdup(textures[1]);
	free_split(textures);
}

void    parse_colors(t_config *config, char *line)
{
    char    **colors;

    colors =  ft_split(line, ',');
    if (!strncmp(line, "F", 1))
    {
        config->colors[0][0] = ft_atoi(colors[0]+1);
        config->colors[0][1] = ft_atoi(colors[1]);
        config->colors[0][2] = ft_atoi(colors[2]);
    }
    if (!strncmp(line, "C", 1))
    {
        config->colors[1][0] = ft_atoi(colors[0]+1);
        config->colors[1][1] = ft_atoi(colors[1]);
        config->colors[1][2] = ft_atoi(colors[2]);
    }
    free_split(colors);
}