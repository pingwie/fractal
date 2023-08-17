#include "../include/fractol.h"

int32_t	compute_color_mandel(t_scene *scene, int i)
{
	double	t;

	t = 1.0 * i / (MAX_ITER);
	if (scene->color == 1)
	{
		return (ft_pixel(255 * 9 * (1 - t) * t * t * t, 15 * 255 * \
		(1 - t) * (1 - t) * t * t, 8.5 * 255 * (1 - t) * (1 - t) * \
		(1 - t) * t, 180));
	}
	else if (scene->color == 2)
	{
		return (ft_pixel(255 * 15 * (1 - t) * t * t * t, 8.5 * 255 * \
		(1 - t) * (1 - t) * t * t, 9 * 255 * (1 - t) * (1 - t) * \
		(1 - t) * t, 180));
	}
	else
	{
		return (ft_pixel(255 * 8.5 * (1 - t) * t * t * t, 9 * 255 * \
		(1 - t) * (1 - t) * t * t, 8.5 * 255 * (1 - t) * (1 - t) * \
		(1 - t) * t, 180));
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_max(int n1, int n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (n < 0)
		n = ft_max(ft_strlen(s1), ft_strlen(s2));
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)s1[i] < (unsigned char)s2[i])
			return (-1);
		else if ((unsigned char)s1[i] > (unsigned char)s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	arg_cheker(char *str, t_scene *scene)
{
	if (ft_strncmp(str, "mandel", 7) == 0)
	{
		scene->frac_op = MANDEL;
		return (1);
	}
	else if (ft_strncmp(str, "julia", 6) == 0)
	{
		scene->frac_op = JULIA;
		return (1);
	}
	else if (ft_strncmp(str, "burning", 8) == 0)
	{
		scene->frac_op = BURNING;
		return (1);
	}
	else
	{
		scene->frac_op = -1;
		return (0);
	}
}

double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	return (-x);
}
