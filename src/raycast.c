/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:50:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 13:55:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double	radians(int degree)
{
	return (degree * M_PI / 180);
}

void	draw_line(t_img *img, t_point start, t_point end, t_color color)
{
	int	x;
	int	y;

	if (start.x < 0)
		x = 0;
	else if (start.x >= SCREEN_WIDTH)
		x = SCREEN_WIDTH - 1;
	else
		x = start.x;
	if (start.y < 0)
		y = 0;
	else if (start.y > SCREEN_HEIGHT)
		y = SCREEN_HEIGHT - 1;
	else
		y = start.y;
	while (y < end.y && y < SCREEN_HEIGHT)
	{
		pixel_put(img, start.x, y, color);
		y++;
	}
}

static t_hit raycast(t_simulation *rcast, double ray_angle)
{
	double	dx;
	double	dy;
	t_ray	ray;
	t_hit	hit;
	char	wall;

	wall = '0';
	ray = (t_ray){rcast->player.pos.x, rcast->player.pos.y};
	dx = cos(radians(ray_angle)) / RAY_PRECISION;
	dy = sin(radians(ray_angle)) / RAY_PRECISION;
	while (wall != '1')
	{
		ray.x += dx;
		ray.y += dy;
		wall = rcast->map[(int)floor(ray.y)][(int)floor(ray.x)];
	}
	hit.x = ray.x;
	hit.y = ray.y;
	hit.distance = sqrt(
			pow(rcast->player.pos.x - ray.x, 2)
			+ pow(rcast->player.pos.y - ray.y, 2));
	hit.distance = hit.distance * cos(radians(ray_angle - rcast->player.angle)); // fisheye
	return (hit);
}

static void	draw(t_img *buffer, int x, int height)
{
	draw_line(
			buffer,
			(t_point){x, 0},
			(t_point){x, SCREEN_HALF_HEIGHT - height},
			rgb(0, 0, 0));
	draw_line(
			buffer,
			(t_point){x, SCREEN_HALF_HEIGHT - height},
			(t_point){x, SCREEN_HALF_HEIGHT + height},
			rgb(150, 150, 150));
	draw_line(
			buffer,
			(t_point){x, SCREEN_HALF_HEIGHT + height},
			(t_point){x, SCREEN_HEIGHT},
			rgb(200, 200, 200));
}

void	raycasting(t_simulation *rcast)
{
	int		i;
	t_hit	hit;
	int		height;
	double	ray_angle;

	i = 0;
	ray_angle = rcast->player.angle;
	while (i < SCREEN_WIDTH)
	{
		hit = raycast(rcast, ray_angle);
		height = floor(SCREEN_HALF_HEIGHT / hit.distance);
		draw(&rcast->screen.buffer, i, height);
		ray_angle += (double)rcast->player.fov / SCREEN_WIDTH;
		i++;
	}
}
