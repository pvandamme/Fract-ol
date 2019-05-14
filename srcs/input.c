/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 08:56:13 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/28 11:38:48 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_window(t_id *id)
{
	mlx_destroy_window(id->mlx_p, id->win_p);
	free(id->tab);
	exit(0);
}

void	move(int key, t_inp *inp)
{
	if (key == 123)
		inp->x1 += 30 / inp->zoom;
	if (key == 124)
		inp->x1 -= 30 / inp->zoom;
	if (key == 125)
		inp->y1 -= 30 / inp->zoom;
	if (key == 126)
		inp->y1 += 30 / inp->zoom;
}

void	zoom(int x, int y, t_inp *inp)
{
	inp->x1 = (x / inp->zoom + inp->x1) - (x / (inp->zoom * 1.3));
	inp->y1 = (y / inp->zoom + inp->y1) - (y / (inp->zoom * 1.3));
	inp->zoom *= 1.3;
	inp->it_max++;
}

void	dezoom(int x, int y, t_inp *inp)
{
	inp->x1 = (x / inp->zoom + inp->x1) - (x / (inp->zoom / 1.3));
	inp->y1 = (y / inp->zoom + inp->y1) - (y / (inp->zoom / 1.3));
	inp->zoom /= 1.3;
	inp->it_max--;
}

int		mouse_hook(int key, int x, int y, void *data)
{
	if (key == 4 || key == 1)
		zoom(x, y, ((t_data *)data)->inp);
	if (key == 5 || key == 2)
		dezoom(x, y, ((t_data *)data)->inp);
	print_fract(data);
	return (0);
}
