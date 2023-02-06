/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:28:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 09:55:03 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"
#include <mlx.h>

int	main(void)
{
	t_screen	screen;

	screen = load_mlx();
	load_hooks(&screen);
	mlx_loop(screen.mlx);
	return (0);
}
