/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcast.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 13:59:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCAST_H
# define RCAST_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SCREEN_HALF_WIDTH 640
# define SCREEN_HALF_HEIGHT 360

# define RAY_PRECISION 64

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

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef char	**t_map;

typedef struct s_player
{
	t_point		pos;
	int			angle;
	int			fov;
	int			half_fov;
}	t_player;

typedef struct s_simulation
{
	t_map		map;
	t_screen	screen;
	t_player	player;
}	t_simulation;

typedef struct s_ray
{
	double	x;
	double	y;
}	t_ray;

typedef struct s_hit
{
	double	x;
	double	y;
	double	distance;
}	t_hit;

typedef int		t_color;

t_screen	init_screen(void);

void		load_hooks(t_simulation *rcast);

void		pixel_put(t_img *img, int x, int y, t_color color);

int			rgb(int r, int g, int b);

void		fill(t_img *img, t_color color);

void		raycasting(t_simulation *rcast);

int			render(t_simulation *rcast);

#endif // !RCAST_H
