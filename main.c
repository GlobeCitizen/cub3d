/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahnich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:33:17 by mahnich           #+#    #+#             */
/*   Updated: 2020/07/22 12:19:35 by mahnich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "libft/libft.h"

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

int		render_next_frame(int key, t_vars *param)
{
	if (key == 124 || key == 123 || key == 125 || key == 126)
	mlx_clear_window(param->mlx, param->win);
	static int r = 30;
	static int x = 500;
	static int y = 500;
	if (key == 124)
	{
		draw_circle(param, x += 10, y, r++);
	}
	if (key == 123)
	{
		draw_circle(param, x -= 10, y, r--);
	}
	if (key == 126)
	{
		draw_circle(param, x, y-=10, r*=10);
	}
	if (key == 125)
	{
		draw_circle(param, x, y+=10, r/=10);
	}

	printf("key: %i\n", key);
	return(0);
}

int	main()
{
	t_vars vars;
	
	vars.i = 0;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "cub3d");
	//draw_circle(&vars, 500, 500, 100);
	mlx_hook(vars.win, 2, 0, render_next_frame,  &vars);

	mlx_loop(vars.mlx);
}
