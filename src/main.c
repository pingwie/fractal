#include "../include/fractol.h"

void	free_scene(t_scene *scene)
{
	int	i;

	i = 0;
	if (scene->jul_const)
	{
		while (i < JULIA_SETS)
			free(scene->jul_const[i++]);
	}
	free(scene->jul_const);
	free(scene);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	fractal(void *param)
{
	t_scene		*scene;
	uint32_t	y;
	uint32_t	x;
	int			color;

	scene = param;
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (scene->frac_op == MANDEL)
				color = get_color_mandel(scene, x, y);
			else if (scene->frac_op == JULIA)
				color = get_color_julia(scene, x, y);
			else
				color = get_color_burning(scene, x, y);
			mlx_put_pixel(scene->image, x, y, color);
			y++;
		}
		x++;
	}
}

int	main(int ac, char **av)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (ac != 2 || !arg_cheker(av[1], scene))
	{
		printf("Fractal argument required:\n");
		printf("mandel, julia, burning\n\n");
		free(scene);
		return (0);
	}
	else
	{
		init(scene);
		mlx_loop_hook(scene->mlx, &fractal, scene);
		mlx_loop_hook(scene->mlx, &ft_hook, scene);
		mlx_loop_hook(scene->mlx, &ft_hook_2, scene);
		mlx_key_hook(scene->mlx, &ft_key_hook, scene);
		mlx_scroll_hook(scene->mlx, ft_scroll, scene);
		mlx_loop(scene->mlx);
		mlx_terminate(scene->mlx);
		free_scene(scene);
	}
	return (0);
}
