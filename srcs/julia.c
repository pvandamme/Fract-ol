/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:59:44 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/28 19:21:26 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			julia_hook(int x, int y, void *data)
{
	if (((t_data *)data)->inp->pause == 0 && ((t_data *)data)->id->fract == 2)
	{
		((t_data *)data)->var->c_r = (double)x / 500 - 1.3;
		((t_data *)data)->var->c_i = (double)y / 500 - 1.3;
		print_julia(data);
	}
	return (0);
}

void		init_julia(t_data *data)
{
	data->inp->x1 = -2;
	data->inp->y1 = -1.5;
	data->inp->pause = 0;
	data->var->c_r = -0.9;
	data->var->c_i = 0.305;
	data->inp->zoom = 300;
	data->inp->it_max = 50;
}

static void	calc_julia(t_id *id, t_var *var, t_inp *inp)
{
	int		i;
	double	tmp;

	i = 0;
	var->z_r = var->x / inp->zoom + inp->x1;
	var->z_i = var->y / inp->zoom + inp->y1;
	while (var->z_r * var->z_r + var->z_i *
			var->z_i < 4 && i < inp->it_max)
	{
		tmp = var->z_r;
		var->z_r = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
		var->z_i = 2 * var->z_i * tmp + var->c_i;
		i++;
	}
	if (inp->color != 1)
		if (i == inp->it_max)
			id->tab[var->y * WIDTH + var->x] = 0;
		else
			id->tab[var->y * WIDTH + var->x] = i * inp->color_value;
	else
		color(id, var, inp, i);
}

int			print_julia(t_data *data)
{
	char	*it;

	data->var->x = 0;
	bzero_tab(data->id->tab);
	while (data->var->x < WIDTH)
	{
		data->var->y = 0;
		while (data->var->y < WIDTH)
		{
			calc_julia(data->id, data->var, data->inp);
			data->var->y++;
		}
		data->var->x++;
	}
	mlx_put_image_to_window(data->id->mlx_p, data->id->win_p,
			data->id->img_p, 0, 0);
	mlx_string_put(data->id->mlx_p, data->id->win_p, 20, 20, 16777215,
			"ITERATION MAX : ");
	if (!(it = ft_itoa(data->inp->it_max)))
		return (0);
	mlx_string_put(data->id->mlx_p, data->id->win_p, 180, 20, 16777215, it);
	free(it);
	return (1);
}
