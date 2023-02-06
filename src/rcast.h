/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcast.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/06 17:58:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCAST_H
# define RCAST_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SCREEN_HALF_WIDTH 640
# define SCREEN_HALF_HEIGHT 360

# define RAY_PRECISION 64

enum	e_sides
{
	S_NO,
	S_SO,
	S_WE,
	S_EA,
	S_COUNT,
};

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endianess;
	int		width;
	int		height;
}	t_img;

typedef struct s_screen
{
	void	*mlx;
	void	*window;
	t_img	buffer;
	t_img	walls[S_COUNT];
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
	double		angle;
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
	int		side;
	double	distance;
}	t_hit;

typedef int		t_color;

t_screen	init_screen(void);

void		load_hooks(t_simulation *rcast);

void		pixel_put(t_img *img, int x, int y, t_color color);

t_color		pixel_get(t_img *img, int x, int y);

int			rgb(int r, int g, int b);

void		fill(t_img *img, t_color color);

void		raycasting(t_simulation *rcast);

int			render(t_simulation *rcast);

#endif // !RCAST_H
