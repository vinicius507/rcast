/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:50:11 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 18:36:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double	radians(double degree)
{
	return (degree * M_PI / 180);
}

static int	get_hit_side(t_player *player, t_hit *hit, double ray_angle)
{
	t_point	wall_pos;

	wall_pos = (t_point){floor(hit->x), floor(hit->y)};
	return (S_NO);
}

static t_hit	raycast(t_simulation *rcast, double ray_angle)
{
	double	dx;
	double	dy;
	t_ray	ray;
	t_hit	hit;
	char	wall;

	hit = (t_hit){-1, -1};
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
	hit.side = get_hit_side(&rcast->player, &hit, ray_angle);
	hit.distance = sqrt(pow(rcast->player.pos.x - ray.x, 2)
			+ pow(rcast->player.pos.y - ray.y, 2));
	hit.distance = hit.distance * cos(radians(ray_angle - rcast->player.angle));
	return (hit);
}

static void	draw_line(t_img *img, t_point start, t_point end, t_color color)
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

static void	draw_texture(t_screen *screen, t_img *wall, t_point start, t_hit *hit, int height)
{
	int		i;
	double	y;
	double	dy;
	t_color	color;
	int		texture_x;

	i = 0;
	y = start.y;
	dy = (double)height * 2 / wall->height;
	texture_x = (int)floor(wall->width * (hit->x + hit->y)) % wall->width;
	while (i < wall->height)
	{
		color = pixel_get(wall, texture_x, i);
		draw_line(
			&screen->buffer,
			(t_point){start.x, floor(y)},
			(t_point){start.x, floor(y + dy)},
			color);
		y += dy;
		i++;
	}
}

static void	draw(t_screen *screen, int x, int height, t_hit *hit)
{
	t_img	*buffer;

	buffer = &screen->buffer;
	draw_line(
		buffer,
		(t_point){x, 0},
		(t_point){x, SCREEN_HALF_HEIGHT - height},
		rgb(0, 0, 0));
	draw_texture(
		screen,
		&screen->walls[hit->side],
		(t_point){x, SCREEN_HALF_HEIGHT - height},
		hit,
		height);
	draw_line(
		buffer,
		(t_point){x, SCREEN_HALF_HEIGHT + height},
		(t_point){x, SCREEN_HEIGHT},
		rgb(200, 200, 200));
}

void	raycasting(t_simulation *rcast)
{
	int			x;
	t_hit		hit;
	int			height;
	double		ray_angle;

	x = 0;
	ray_angle = rcast->player.angle;
	while (x < SCREEN_WIDTH)
	{
		hit = raycast(rcast, ray_angle);
		height = floor(SCREEN_HALF_HEIGHT / hit.distance);
		draw(&rcast->screen, x, height, &hit);
		ray_angle += (double)rcast->player.fov / SCREEN_WIDTH;
		x++;
	}
}
