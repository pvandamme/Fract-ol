/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:47:55 by pvandamm          #+#    #+#             */
/*   Updated: 2019/01/22 20:11:24 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fractol.h"

int				print_fract(t_data *data)
{
	if (data->id->fract == 1)
		if (!(print_mandelbrot(data)))
			return (0);
	if (data->id->fract == 2)
		if (!(print_julia(data)))
			return (0);
	if (data->id->fract == 3)
		if (!(print_burningship(data)))
			return (0);
	return (1);
}

static int		key_hook(int key, void *data)
{
	if (key == 53)
		destroy_window(((t_data *)data)->id);
	if (key > 122 && key < 127)
		move(key, ((t_data *)data)->inp);
	if (key == 69)
		((t_data *)data)->inp->it_max += 1;
	if (key == 78)
		((t_data *)data)->inp->it_max -= 1;
	if (key == 30)
		((t_data *)data)->inp->it_max += 500;
	if (key == 33)
		if (((t_data *)data)->inp->it_max - 500 > 0)
			((t_data *)data)->inp->it_max -= 500;
	if (key == 35)
	{
		if (((t_data *)data)->inp->pause == 1)
			((t_data *)data)->inp->pause = 0;
		else
			((t_data *)data)->inp->pause = 1;
	}
	if (key > 17 && key < 22)
		color_input(key, ((t_data *)data)->inp);
	print_fract(data);
	return (0);
}

static t_data	*init_struct(void)
{
	t_data	*data;

	if (!(data = malloc(sizeof(t_data))))
		return (0);
	if (!(data->id = malloc(sizeof(t_id))))
		return (0);
	if (!(data->var = malloc(sizeof(t_var))))
		return (0);
	if (!(data->inp = malloc(sizeof(t_inp))))
		return (0);
	data->id->mlx_p = mlx_init();
	data->id->win_p = mlx_new_window(data->id->mlx_p, WIDTH, WIDTH, "fractol");
	data->id->img_p = mlx_new_image(data->id->mlx_p, WIDTH, WIDTH);
	data->id->tab = (unsigned int *)mlx_get_data_addr(data->id->img_p,
			&data->id->bpp, &data->id->sizeline, &data->id->endian);
	data->inp->color = 1;
	return (data);
}

static void		init_fract(char *str, t_data *data)
{
	if (!ft_strcmp(str, "mandelbrot"))
	{
		init_mandelbrot(data);
		data->id->fract = 1;
	}
	else if (!ft_strcmp(str, "julia"))
	{
		init_julia(data);
		data->id->fract = 2;
	}
	else if (!ft_strcmp(str, "burningship"))
	{
		init_burningship(data);
		data->id->fract = 3;
	}
}

int				main(int ac, char **av)
{
	t_data	*data;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "julia") && ft_strcmp(av[1], "mandelbrot")
				&& ft_strcmp(av[1], "burningship"))
		{
			ft_putstr("Usage <filename> [mandelbrot/julia/burningship]\n");
			return (0);
		}
		if (!(data = init_struct()))
			return (0);
		init_fract(av[1], data);
		if (!(print_fract(data)))
			return (0);
		mlx_mouse_hook(data->id->win_p, mouse_hook, data);
		mlx_hook(data->id->win_p, 2, 0, key_hook, data);
		mlx_hook(data->id->win_p, 6, 1L << 6, julia_hook, data);
		mlx_loop(data->id->mlx_p);
	}
	ft_putstr("Usage <filename> [mandelbrot/julia/burningship]\n");
	return (0);
}
