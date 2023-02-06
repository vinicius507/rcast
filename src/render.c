/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:45:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 10:12:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>

int	rgb(int r, int g, int b)
{
	r = r & 0xff;
	g = g & 0xff;
	b = b & 0xff;
	return (r << 16 | g << 8 | b);
}

int	render(t_screen *screen)
{
	fill(&screen->buffer, rgb(0, 0, 0));
	mlx_put_image_to_window(
		screen->mlx,
		screen->window,
		screen->buffer.ptr, 0, 0);
	return (0);
}
