#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft/libft.h"

# define WIDTH 1028
# define HEIGHT 720

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	char		**map;
	int			**arr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			line_color;
	int			x;
	int			y;
	double		h;
	double		w;
	double		movespeed;
	double		rotspeed;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_env;

char	        **read_map(char *filename);
int		        **convert(char **map, char *filename);
void	        render(t_env *z);
void	        move_right(t_env *z);
void	        move_left(t_env *z);
void	        move_down(t_env *z);
void	        move_up(t_env *z);
int				count(char **str);


#endif