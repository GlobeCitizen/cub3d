/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:33:17 by mahnich           #+#    #+#             */
/*   Updated: 2020/07/24 03:54:31 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	int i;
}               t_vars;

int	key_printer(int key, t_vars *param)
{
	printf("key code : %i\n", key);
	if (key == 53)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(0);
	}
	return(0);
}

void	draw_circle(t_vars *param, int x, int y, int r)
{
	double angle;
	double x1;
	double y1;

	angle = 360;
	while (angle > 0)
	{
		x1 = x + r * cos(angle * M_PI / 180);
		y1 = y + r * sin(angle * M_PI / 180);
		mlx_pixel_put(param->mlx, param->win, x1, y1, 0x00FF0000);
		angle -= 0.1;
	}
}

int	main()
{
	t_vars vars;
	
	vars.i = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "cub3d");
	mlx_loop(vars.mlx);
}
