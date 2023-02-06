/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:28:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 13:59:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

static void	init_simulation(t_simulation *rcast)
{
	memset(rcast, 0, sizeof(t_simulation));
	rcast->map = calloc(5, sizeof(char *));
	rcast->map[0] = strdup("11111");
	rcast->map[1] = strdup("10001");
	rcast->map[2] = strdup("10001");
	rcast->map[3] = strdup("10001");
	rcast->map[4] = strdup("11111");
	rcast->player.fov = 60;
	rcast->player.fov = rcast->player.fov / 2;
	rcast->player.angle = 0;
	rcast->player.pos = (t_point){3, 3};
	rcast->screen = init_screen();
	load_hooks(rcast);
}

int	main(void)
{
	t_simulation	rcast;

	init_simulation(&rcast);
	mlx_loop(rcast.screen.mlx);
	return (0);
}
