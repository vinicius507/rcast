/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcast.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 10:08:04 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCAST_H
# define RCAST_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endianess;
}	t_img;

typedef struct s_screen
{
	void	*mlx;
	void	*window;
	t_img	buffer;
}	t_screen;

typedef unsigned int	t_color;

t_screen	load_mlx(void);

void		load_hooks(t_screen *screen);

void		pixel_put(t_img *img, int x, int y, t_color color);

void		fill(t_img *img, t_color color);

int			render(t_screen *screen);

#endif // !RCAST_H
