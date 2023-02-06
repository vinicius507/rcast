/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:51:35 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 16:20:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

static char	*g_textures[S_COUNT] = {
	"assets/no.xpm",
	"assets/so.xpm",
	"assets/we.xpm",
	"assets/ea.xpm",
};

void	load_texture(t_screen *screen, int side)
{
	t_img	*wall;

	wall = &screen->walls[side];
	wall->ptr = mlx_xpm_file_to_image(
			screen->mlx,
			g_textures[side],
			&wall->width,
			&wall->height);
	wall->data = mlx_get_data_addr(
			wall->ptr,
			&wall->bpp,
			&wall->line_len,
			&wall->endianess);
}

t_screen	init_screen(void)
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
	load_texture(&screen, S_NO);
	load_texture(&screen, S_SO);
	load_texture(&screen, S_WE);
	load_texture(&screen, S_EA);
	return (screen);
}

static int	kill_screen(t_simulation *rcast)
{
	t_screen	*screen;

	screen = &rcast->screen;
	mlx_destroy_image(screen->mlx, screen->buffer.ptr);
	mlx_destroy_image(screen->mlx, screen->walls[S_NO].ptr);
	mlx_destroy_image(screen->mlx, screen->walls[S_SO].ptr);
	mlx_destroy_image(screen->mlx, screen->walls[S_WE].ptr);
	mlx_destroy_image(screen->mlx, screen->walls[S_EA].ptr);
	mlx_destroy_window(screen->mlx, screen->window);
	mlx_destroy_display(screen->mlx);
	free(screen->mlx);
	free(rcast->map[0]);
	free(rcast->map[1]);
	free(rcast->map[3]);
	free(rcast->map[4]);
	free(rcast->map);
	exit(0);
}

void	load_hooks(t_simulation *rcast)
{
	mlx_loop_hook(rcast->screen.mlx, &render, rcast);
	mlx_hook(rcast->screen.window, 17, 0, &kill_screen, rcast);
}
