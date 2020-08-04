/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:15:59 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/03 20:15:56 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H

# define CONFIG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# include "../gnl/get_next_line.h"

# define DIRECTIONS "NSEW"
# define VALID_MAP_CHARS "012NSEW"

typedef struct s_config 
{
	int		requested_height;
	int		requested_width;
	int		rows;
	int		colomuns;
	char	*textures[5];
	int		colors[2][3];
}			t_config;

void	parse_resolution(t_config *config, char	*line);
void	parse_textures(t_config *config, char *line);
void	parse_colors(t_config *config, char *line);
void	free_split(char **splitted);

#endif
