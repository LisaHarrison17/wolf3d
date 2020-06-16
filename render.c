#include "wolf3d.h"

void	colours(t_env *z)
{
	if (z->arr[z->mapy][z->mapx] == 1)
		z->line_color = 0x00333057;
	if (z->arr[z->mapy][z->mapx] == 2)
		z->line_color = 0x00FF9CFF;
	if (z->arr[z->mapy][z->mapx] == 3)
		z->line_color = 0x00FFFF85;
	if (z->arr[z->mapy][z->mapx] == 4)
		z->line_color = 0x00B8FFFF;
	if (z->arr[z->mapy][z->mapx] == 5)
		z->line_color = 0x00B8FF9D;
	if (z->side == 1)
		z->line_color = z->line_color / 2;
	while (z->y < HEIGHT)
	{
		if (z->y <= z->drawstart)
			z->data[z->y * WIDTH + z->x] = 0x0000C1FF;
		else if (z->drawstart <= z->drawend)
		{
			z->data[z->y * WIDTH + z->x] = z->line_color;
			z->drawstart++;
		}
		else
			z->data[z->y * WIDTH + z->x] = 75987324;
		z->y++;
	}
}

void	init_view(t_env *z)
{
	z->camerax = 2 * z->x / z->w - 1;
	z->raydirx = z->dirx + z->planex * z->camerax;
	z->raydiry = z->diry + z->planey * z->camerax;
	z->mapx = (int)z->posx;
	z->mapy = (int)z->posy;
	z->deltadistx = fabs(1 / z->raydirx);
	z->deltadisty = fabs(1 / z->raydiry);
	z->hit = 0;
}

void	check_rays(t_env *z)
{
	if (z->raydirx < 0)
	{
		z->stepx = -1;
		z->sidedistx = (z->posx - z->mapx) * z->deltadistx;
	}
	else
	{
		z->stepx = 1;
		z->sidedistx = (z->mapx + 1.0 - z->posx) * z->deltadistx;
	}
	if (z->raydiry < 0)
	{
		z->stepy = -1;
		z->sidedisty = (z->posy - z->mapy) * z->deltadisty;
	}
	else
	{
		z->stepy = 1;
		z->sidedisty = (z->mapy + 1.0 - z->posy) * z->deltadisty;
	}
}

void	collision(t_env *z)
{
	while (z->hit == 0)
	{
		if (z->sidedistx < z->sidedisty)
		{
			z->sidedistx += z->deltadistx;
			z->mapx += z->stepx;
			z->side = 0;
		}
		else
		{
			z->sidedisty += z->deltadisty;
			z->mapy += z->stepy;
			z->side = 1;
		}
		if (z->arr[z->mapx][z->mapy] > 0)
			z->hit = 1;
	}
}

void	render(t_env *z)
{
	z->y = 0;
	z->x = 0;
	while (z->x < z->w)
	{
		z->y = 0;
		init_view(z);
		check_rays(z);
		collision(z);
		if (z->side == 0)
			z->perpwalldist = (z->mapx - z->posx +
					(1 - z->stepx) / 2) / z->raydirx;
		else
			z->perpwalldist = (z->mapy - z->posy +
					(1 - z->stepy) / 2) / z->raydiry;
		z->lineheight = (int)(z->h / z->perpwalldist);
		z->drawstart = -z->lineheight / 2 + z->h / 2;
		if (z->drawstart < 0)
			z->drawstart = 0;
		z->drawend = z->lineheight / 2 + z->h / 2;
		if (z->drawend >= z->h)
			z->drawend = z->h - 1;
		z->line_color = 0x00A687B6;
		colours(z);
		z->x++;
	}
} 