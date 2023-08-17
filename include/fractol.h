#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/MLX42.h"

# define WIDTH 700
# define HEIGHT 700
# define MAX_ITER 150
# define MANDEL 1
# define JULIA 2
# define BURNING 3
# define JULIA_SETS 7

typedef struct s_scene
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			frac_op;
	double		cursor_x;
	double		cursor_y;
	double		rmin;
	double		rmax;
	double		imin;
	double		imax;
	double		zoom;
	int			color;
	int32_t		x_pos;
	int32_t		y_pos;
	double		x_ratio;
	double		y_ratio;
	double		diff;
	double		ddiff;
	float		**jul_const;
	int			jul_idx;
	float		x_din;
	float		y_din;
}	t_scene;

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
int32_t	compute_color(t_scene *scene, int i);
int32_t	compute_color_mandel(t_scene *scene, int i);
float	get_color_mandel(t_scene *scene, float c_x, float c_y);
int32_t	get_color_julia(t_scene *scene, float x, float y);
int32_t	get_color_burning(t_scene *scene, float c_x, float c_y);
void	ft_hook(void *param);
void	ft_hook_2(void *param);
void	ft_scroll(double xdelta, double ydelta, void *param);
int		ft_strlen(const char *s);
int		ft_max(int n1, int n2);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		arg_cheker(char *str, t_scene *scene);
void	init(t_scene *scene);
void	init_mandel(t_scene *scene);
void	init_julia_const(t_scene *scene);
void	init_julia(t_scene *scene);
void	init_burning(t_scene *scene);
void	free_scene(t_scene *scene);
void	ft_key_hook(mlx_key_data_t keydata, void *param);
double	ft_abs(double x);
#endif
