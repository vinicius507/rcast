/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:47:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 16:21:10 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"

void	pixel_put(t_img *img, int x, int y, t_color color)
{
	char	*px;

	px = img->data + y * img->line_len + (x * (img->bpp / 8));
	*(unsigned int *)px = color;
}

t_color	pixel_get(t_img *img, int x, int y)
{
	char	*px;

	px = img->data + y * img->line_len + (x * (img->bpp / 8));
	return (*(unsigned int *)px);
}
