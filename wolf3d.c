#include "wolf3d.h"

int		exit_game(t_env *z)
{
	mlx_destroy_window(z->mlx, z->win);
	exit(0);
	return (0);
}

void	init_game(t_env *z)
{
	z->mlx = mlx_init();
	z->win = mlx_new_window(z->mlx, WIDTH, HEIGHT, "WOLF");
	z->img_ptr = mlx_new_image(z->mlx, WIDTH, HEIGHT);
	z->data = (int *)mlx_get_data_addr(z->img_ptr, &z->bpp,
			&z->size_l, &z->endian);
	z->h = 720;
	z->w = 1028;
	z->posx = 22;
	z->posy = 12;
	z->dirx = -1;
	z->diry = 0;
	z->planex = 0;
	z->planey = 0.66;
	z->movespeed = 0.4;
	z->rotspeed = 0.2;
}

int		my_key_funct(int keycode, t_env *z)
{
	if (keycode == 53)
	{
		mlx_destroy_window(z->mlx, z->win);
		exit(0);
	}
	if (keycode == 3)
	{
		z->movespeed = 1.0;
		z->rotspeed = 0.5;
	}
	if (keycode == 1)
	{
		z->movespeed = 0.4;
		z->rotspeed = 0.2;
	}
	if (keycode == 124)
		move_right(z);
	if (keycode == 123)
		move_left(z);
	if (keycode == 125)
		move_down(z);
	if (keycode == 126)
		move_up(z);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*z;

	if (argc == 2)
	{
		if (!(z = (t_env *)malloc(sizeof(t_env))))
			return (0);
		init_game(z);
		z->map = read_map(argv[1]);
		z->arr = convert(z->map, argv[1]);
		render(z);
		mlx_put_image_to_window(z->mlx, z->win, z->img_ptr, 0, 0);
		mlx_hook(z->win, 2, 0, my_key_funct, z);
		mlx_hook(z->win, 17, 0, exit_game, z);
		mlx_key_hook(z->win, my_key_funct, z);
		mlx_loop(z->mlx);
	}
	else
		write(1, "BIG NOPE - only map file accepted.", 12);
	free(z);
	return (0);
}