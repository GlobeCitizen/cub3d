/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <mahnich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 15:15:59 by mahnich           #+#    #+#             */
/*   Updated: 2020/08/18 20:15:51 by mahnich          ###   ########.fr       */
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

typedef struct	s_config
{
	int		requested_height;
	int		requested_width;
	int		rows;
	int		rows2;
	int		colomuns;
	int		ceil;
	int		floor;
	char	*textures[5];
	int		colors[2][3];
	int		**map_buffer;
}				t_config;

int				parse_resolution(t_config *config, char	*line);
int				parse_textures(t_config *config, char *line);
int				parse_colors(t_config *config, char *line);
int     		parse_config(t_config *config, char *line);
int				check_config(t_config *config);
void			print_error_free(t_config *config);
int				count_rows_colomuns(t_config *config, const char *conf_path);
int				parse_map(t_config *config, char *line);
int				initialize_map(t_config *config);
int				fill_map(t_config *config, char *line);
void			free_map(t_config *config);
int     		check_first_last_line(t_config *config);
int				check_left_right_borders(t_config *config);
int				check_holes(t_config *config);
void			print_error_map(int r, t_config *config);





#endif
