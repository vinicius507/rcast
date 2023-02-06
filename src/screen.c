/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:51:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 10:11:57 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

void	fill(t_img *img, t_color color)
{
	int	x;
	int	y;
	int	pixels;

	pixels = SCREEN_WIDTH * SCREEN_HEIGHT;
	while (pixels--)
	{
		x = pixels % SCREEN_WIDTH;
		y = pixels / SCREEN_WIDTH;
		pixel_put(img, x, y, color);
	}
}

t_screen	load_mlx(void)
{
	t_screen	screen;

	memset(&screen, 0, sizeof(t_screen));
	screen.mlx = mlx_init();
	screen.window = mlx_new_window(
			screen.mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"Rcast");
	screen.buffer.ptr = mlx_new_image(screen.mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	screen.buffer.data = mlx_get_data_addr(
			screen.buffer.ptr,
			&screen.buffer.bpp,
			&screen.buffer.line_len,
			&screen.buffer.endianess);
	return (screen);
}

static int	kill_screen(t_screen *screen)
{
	mlx_destroy_image(screen->mlx, screen->buffer.ptr);
	mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	exit(0);
}

void	load_hooks(t_screen *screen)
{
	mlx_loop_hook(screen->mlx, &render, screen);
	mlx_hook(screen->window, 17, 0, &kill_screen, screen);
}
