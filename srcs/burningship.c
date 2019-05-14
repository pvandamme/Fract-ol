/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:00:30 by pvandamm          #+#    #+#             */
/*   Updated: 2019/01/22 22:11:19 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_burningship(t_data *data)
{
	data->inp->it_max = 50;
	data->inp->zoom = 300;
	data->inp->x1 = -2;
	data->inp->y1 = -1.5;
}

static void	calc_burningship(t_id *id, t_var *var, t_inp *inp)
{
	int		i;
	double	tmp;

	var->c_r = var->x / inp->zoom + inp->x1;
	var->c_i = var->y / inp->zoom + inp->y1;
	var->z_r = 0;
	var->z_i = 0;
	i = 0;
	while (var->z_r * var->z_r + var->z_i * var->z_i < 4
			&& i < inp->it_max)
	{
		tmp = var->z_r * var->z_r - var->z_i * var->z_i + var->c_r;
		var->z_i = fabs(2 * var->z_r * var->z_i) + var->c_i;
		var->z_r = tmp;
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

int			print_burningship(t_data *data)
{
	char	*it;

	data->var->x = 0;
	bzero_tab(data->id->tab);
	while (data->var->x < WIDTH)
	{
		data->var->y = 0;
		while (data->var->y < WIDTH)
		{
			calc_burningship(data->id, data->var, data->inp);
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
