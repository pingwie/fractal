#include "../include/fractol.h"

void	ft_scroll(double xdelta, double ydelta, void *param)
{
	t_scene	*scene;

	(void)xdelta;
	scene = param;
	scene->x_pos = 0;
	scene->y_pos = 0;
	mlx_get_mouse_pos(scene->mlx, &scene->x_pos, &scene->y_pos);
	scene->x_ratio = (double)scene->x_pos / WIDTH;
	scene->y_ratio = (double)scene->y_pos / HEIGHT;
	scene->diff = scene->rmax - scene->rmin;
	if (ydelta < 0)
		scene->ddiff = scene->zoom * scene->diff - scene->diff;
	if (ydelta > 0)
		scene->ddiff = (1 / scene->zoom) * scene->diff - scene->diff;
	scene->rmin = scene->rmin - scene->ddiff * scene->x_ratio;
	scene->rmax = scene->rmax + scene->ddiff * (1 - scene->x_ratio);
	scene->imin = scene->rmin - scene->ddiff * (1 - scene->y_ratio);
	scene->imax = scene->imax + scene->ddiff * scene->y_ratio;
}

void	ft_hook(void *param)
{
	t_scene	*scene;
	double	delta;

	scene = param;
	delta = scene->rmax - scene->rmin;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(scene->mlx);
	if (mlx_is_key_down(scene->mlx, MLX_KEY_LEFT))
	{
		scene->rmin -= 0.03 * delta;
		scene->rmax -= 0.03 * delta;
	}
	if (mlx_is_key_down(scene->mlx, MLX_KEY_RIGHT))
	{
		scene->rmin += 0.03 * delta;
		scene->rmax += 0.03 * delta;
	}
	if (mlx_is_key_down(scene->mlx, MLX_KEY_UP))
	{
		scene->imin += 0.03 * delta;
		scene->imax += 0.03 * delta;
	}
}

void	ft_hook_2(void *param)
{
	t_scene	*scene;
	double	delta;

	scene = param;
	delta = scene->rmax - scene->rmin;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_DOWN))
	{
		scene->imin -= 0.03 * delta;
		scene->imax -= 0.03 * delta;
	}
	if (mlx_is_key_down(scene->mlx, MLX_KEY_1))
		scene->color = 1;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_2))
		scene->color = 2;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_3))
		scene->color = 3;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_A))
		scene->x_din -= 0.001;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_D))
		scene->x_din += 0.001;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_W))
		scene->y_din += 0.001;
	if (mlx_is_key_down(scene->mlx, MLX_KEY_S))
		scene->y_din -= 0.001;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_scene	*scene;

	scene = param;
	if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
	{
		if (scene->frac_op == JULIA)
		{
		scene->rmin = -1.7;
		scene->rmax = 1.7;
		scene->imin = -1.7;
		scene->imax = 1.7;
		scene->x_din = 0.0;
		scene->y_din = 0.0;
		scene->jul_idx = (scene->jul_idx + 1) % JULIA_SETS;
		}
		else if (scene->frac_op == MANDEL)
			init_mandel(scene);
		else
			init_burning(scene);
	}
}
