/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:45:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 16:58:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int	render(t_simulation *rcast)
{
	raycasting(rcast);
	mlx_put_image_to_window(
		rcast->screen.mlx,
		rcast->screen.window,
		rcast->screen.buffer.ptr, 0, 0);
	usleep(20000);
	rcast->player.angle += 0.2;
	if (rcast->player.angle > 360)
		rcast->player.angle -= 360;
	return (0);
}
