#include "wolf3d.h"

int		expose_hook(t_env *z)
{
	mlx_clear_window(z->mlx, z->win);
	mlx_destroy_image(z->mlx, z->img_ptr);
	z->img_ptr = mlx_new_image(z->mlx, WIDTH, HEIGHT);
	render(z);
	mlx_put_image_to_window(z->mlx, z->win, z->img_ptr, 0, 0);
	return (0);
}

void	move_right(t_env *z)
{
	double		olddirx;
	double		oldplanex;

	olddirx = z->dirx;
	oldplanex = z->planex;
	z->dirx = z->dirx * cos(-z->rotspeed) - z->diry * sin(-z->rotspeed);
	z->diry = olddirx * sin(-z->rotspeed) + z->diry * cos(-z->rotspeed);
	z->planex = z->planex * cos(-z->rotspeed) - z->planey * sin(-z->rotspeed);
	z->planey = oldplanex * sin(-z->rotspeed) + z->planey * cos(-z->rotspeed);
	expose_hook(z);
}

void	move_left(t_env *z)
{
	double		olddirx;
	double		oldplanex;

	olddirx = z->dirx;
	oldplanex = z->planex;
	z->dirx = z->dirx * cos(z->rotspeed) - z->diry * sin(z->rotspeed);
	z->diry = olddirx * sin(z->rotspeed) + z->diry * cos(z->rotspeed);
	z->planex = z->planex * cos(z->rotspeed) - z->planey * sin(z->rotspeed);
	z->planey = oldplanex * sin(z->rotspeed) + z->planey * cos(z->rotspeed);
	expose_hook(z);
}

void	move_down(t_env *z)
{
	if (z->arr[(int)(z->posx - z->dirx * z->movespeed)][(int)(z->posy)] == 0)
		z->posx -= z->dirx * z->movespeed;
	if (z->arr[(int)(z->posx)][(int)(z->posy - z->diry * z->movespeed)] == 0)
		z->posy -= z->diry * z->movespeed;
	expose_hook(z);
}

void	move_up(t_env *z)
{
	if (z->arr[(int)(z->posx + z->dirx * z->movespeed)][(int)(z->posy)] == 0)
		z->posx += z->dirx * z->movespeed;
	if (z->arr[(int)(z->posx)][(int)(z->posy + z->diry * z->movespeed)] == 0)
		z->posy += z->diry * z->movespeed;
	expose_hook(z);
}