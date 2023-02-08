/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:28:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/08 17:23:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>
#include <stdlib.h>
#include <string.h>

static void	init_simulation(t_simulation *rcast)
{
	memset(rcast, 0, sizeof(t_simulation));
	rcast->map = calloc(10, sizeof(char *));
	rcast->map[0] = strdup("1111111111");
	rcast->map[1] = strdup("1000000011");
	rcast->map[2] = strdup("1000011001");
	rcast->map[3] = strdup("1000000001");
	rcast->map[4] = strdup("1000001011");
	rcast->map[5] = strdup("1000011001");
	rcast->map[6] = strdup("1010000001");
	rcast->map[7] = strdup("1000011001");
	rcast->map[8] = strdup("1010100001");
	rcast->map[9] = strdup("1111111111");
	rcast->player.fov = 60;
	rcast->player.fov = rcast->player.fov / 2;
	rcast->player.angle = 90;
	rcast->player.pos = (t_point){4, 3};
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
