#include "../include/fractol.h"

float	get_color_mandel(t_scene *scene, float c_x, float c_y)
{
	double	x_r;
	double	y_r;
	double	pxsize;
	double	x_tmp;
	int		i;

	y_r = 0;
	x_r = 0;
	i = 0;
	pxsize = (scene->rmax - scene->rmin) / WIDTH;
	c_x = scene->rmin + c_x * pxsize;
	c_y = scene->imax - (c_y * pxsize);
	x_tmp = 0;
	while (x_r * x_r + y_r * y_r < 4 && i < MAX_ITER)
	{
		x_tmp = x_r;
		x_r = x_r * x_r - y_r * y_r + c_x;
		y_r = 2 * x_tmp * y_r + c_y;
		i++;
	}
	if (i == MAX_ITER)
		return (ft_pixel(0, 0, 0, 255));
	else
		return (compute_color_mandel(scene, i));
}
