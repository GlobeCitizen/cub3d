/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <mahnich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:08:06 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/18 20:28:06 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int     check_first_last_line(t_config *config)
{
    int i;

    i = 0;
    while (i < config->colomuns)
    {
        if (config->map_buffer[0][i] == 0 || config->map_buffer[config->rows - 1][i] == 0)
            return (0);
            i++;
    }
    return (1);
}

int     check_left_right_borders(t_config *config)
{
    int first;
    int	last;
	int	i;

	i = 0;
	while (i < config->rows)
	{
		first = 0;
		while (config->map_buffer[i][first] == -1 && first < config->colomuns)
			first++;
		last = config->colomuns - 1;
		while (config->map_buffer[i][last] == -1 && last > 0)
			last--;
		if (last <= 1 || config->map_buffer[i][last] != 1 || config->map_buffer[i][first] != 1)
			return (0);
		i++;
	}
	return (1);
}

int		check_holes(t_config *config)
{
	int		i;
	int		j;

	i = 1;
	while (i < config->rows - 1)
	{
		j = 1;
		while (j < config->colomuns)
		{
			if (config->map_buffer[i][j] == 0)
			{
				if (config->map_buffer[i - 1][j] == -1 || config->map_buffer[i + 1][j] == -1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	print_error_map(int r, t_config *config)
{
	if (!check_holes(config) || !check_first_last_line(config) ||
	!check_left_right_borders(config) || !r)
	{
		write(1, "Error in map format !\n", 23);
	}
	free_map(config);
}