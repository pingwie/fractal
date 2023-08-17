#include "../include/fractol.h"

void	init(t_scene *scene)
{
	if (scene->frac_op == MANDEL)
		init_mandel(scene);
	else if (scene->frac_op == BURNING)
		init_burning(scene);
	else
		init_julia(scene);
	scene->zoom = 1.05;
	scene->color = 1;
	scene->mlx = mlx_init(WIDTH, HEIGHT, "Fractol", false);
	scene->image = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(scene->mlx, scene->image, 0, 0);
}

void	init_mandel(t_scene *scene)
{
	scene->rmin = -1.7;
	scene->rmax = 0.7;
	scene->imin = -1.2;
	scene->imax = 1.2;
	scene->jul_const = NULL;
}

void	init_burning(t_scene *scene)
{
	scene->rmin = -1;
	scene->rmax = 2;
	scene->imin = -1;
	scene->imax = 2;
	scene->jul_const = NULL;
}

void	init_julia_const(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < JULIA_SETS)
	{
		scene->jul_const[i] = (float *)malloc(sizeof(float) * 2);
		i++;
	}
	scene->jul_const[0][0] = -0.87;
	scene->jul_const[0][1] = 0.24;
	scene->jul_const[1][0] = -0.4;
	scene->jul_const[1][1] = 0.6;
	scene->jul_const[2][0] = 0.285;
	scene->jul_const[2][1] = 0.01;
	scene->jul_const[3][0] = -0.70176;
	scene->jul_const[3][1] = -0.3842;
	scene->jul_const[4][0] = -0.835;
	scene->jul_const[4][1] = -0.2321;
	scene->jul_const[5][0] = -0.8;
	scene->jul_const[5][1] = 0.156;
	scene->jul_const[6][0] = -0.7269;
	scene->jul_const[6][1] = 0.1889;
}

void	init_julia(t_scene *scene)
{
	scene->rmin = -1.7;
	scene->rmax = 1.7;
	scene->imin = -1.7;
	scene->imax = 1.7;
	scene->jul_idx = 0;
	scene->x_din = 0.0;
	scene->y_din = 0.0;
	scene->jul_const = (float **)malloc(sizeof(float *) * JULIA_SETS);
	init_julia_const(scene);
}
