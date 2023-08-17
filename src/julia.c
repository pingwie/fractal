#include "../include/fractol.h"

int32_t	compute_color(t_scene *scene, int i)
{
	double	t;

	t = 1.0 * i / (MAX_ITER);
	if (scene->color == 1)
	{
		return (ft_pixel(255 * 9 * (1 - t) * t * t * t, 15 * 255 * \
		(1 - t) * (1 - t) * t * t, 8.5 * 255 * (1 - t) * (1 - t) * \
		(1 - t) * t, 255));
	}
	else if (scene->color == 2)
	{
		return (ft_pixel(255 * 15 * (1 - t) * t * t * t, 8.5 * 255 * \
		(1 - t) * (1 - t) * t * t, 9 * 255 * (1 - t) * (1 - t) * \
		(1 - t) * t, 255));
	}
	else
	{
		return (ft_pixel(255 * 8.5 * (1 - t) * t * t * t, 9 * 255 * \
		(1 - t) * (1 - t) * t * t, 8.5 * 255 * (1 - t) * (1 - t) * \
		(1 - t) * t, 255));
	}
}

int32_t	get_color_julia(t_scene *scene, float x, float y)
{
	double	pxsize;
	double	x_tmp;
	int		i;

	i = 0;
	pxsize = (scene->rmax - scene->rmin) / WIDTH;
	x = scene->rmin + x * pxsize;
	y = scene->imax - (y * pxsize);
	x_tmp = 0;
	while (x * x + y * y < 4. && i < MAX_ITER)
	{
		x_tmp = x;
		x = x * x - y * y + scene->jul_const[scene->jul_idx][0] + scene->x_din;
		y = 2 * x_tmp * y + scene->jul_const[scene->jul_idx][1] + scene->y_din;
		i++;
	}
	if (i == MAX_ITER)
		return (ft_pixel(0, 0, 0, 250));
	else
		return (compute_color(scene, i));
}
