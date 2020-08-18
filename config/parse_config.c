/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <mahnich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 22:42:59 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/18 20:15:56 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

void	print_error_free(t_config *config)
{
	int	i;
	int	j;
	int	flag;
	int	flag2;

	i = 0;
	flag = 1;
	while (i < 5)
	{
		flag2 *= (config->textures[i] != NULL);
		j = -1;
		while (j++ < 2 && i < 2)
			flag *= ((config->colors[i][j] >= 0 && config->colors[i][j] <= 255)
			* (config->ceil == 1 && config->floor == 1));
		i++;
	}
	i = 0;
	if (!flag)
		write(1, "Error in ceil or floor color configuration!\n", 46);
	if (!flag2)
		write(1, "Error in Textures configuration!\n", 34);
	while (i < 5)
		free(config->textures[i++]);
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
		while (i++ < 1)
		{
			j = 0;
			while (j < 3)
			{
				flag = flag * (config->colors[i][j] >= 0 &&
					config->colors[i][j] <= 255);
				j++;
			}
		}
		return (flag);
	}
	return (0);
}

int     parse_config(t_config *config, char *line)
{
    int     r;

    r = 1;
    if (!ft_strncmp(line, "R", 1))
		r *= parse_resolution(config, line);
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
    !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2) ||
    line[0] == 'S')
		r *= parse_textures(config, line);
	else if (!ft_strncmp(line, "C", 1) || !ft_strncmp(line, "F", 1))
		r *= parse_colors(config, line);
    return (r);
}