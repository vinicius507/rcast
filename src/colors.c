/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 12:47:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rcast.h"

int	rgb(int r, int g, int b)
{
	r = r & 0xff;
	g = g & 0xff;
	b = b & 0xff;
	return (r << 16 | g << 8 | b);
}

