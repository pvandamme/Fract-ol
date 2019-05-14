/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 08:52:22 by pvandamm          #+#    #+#             */
/*   Updated: 2018/12/27 17:10:49 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bzero_tab(unsigned int *tab)
{
	int	i;

	i = 0;
	while (i < WIDTH * WIDTH)
	{
		tab[i] = 0;
		i++;
	}
}

void	color_split(t_id *id, t_var *var, t_inp *inp, int i)
{
	if (i % 16 == 7)
		id->tab[var->y * WIDTH + var->x] = 3767761;
	else if (i % 16 == 8)
		id->tab[var->y * WIDTH + var->x] = 8828389;
	else if (i % 16 == 9)
		id->tab[var->y * WIDTH + var->x] = 13888760;
	else if (i % 16 == 10)
		id->tab[var->y * WIDTH + var->x] = 15854015;
	else if (i % 16 == 11)
		id->tab[var->y * WIDTH + var->x] = 16304479;
	else if (i % 16 == 12)
		id->tab[var->y * WIDTH + var->x] = 16755200;
	else if (i % 16 == 13)
		id->tab[var->y * WIDTH + var->x] = 13402112;
	else if (i % 16 == 14)
		id->tab[var->y * WIDTH + var->x] = 10049280;
	else if (i % 16 == 15)
		id->tab[var->y * WIDTH + var->x] = 6960131;
}

void	color(t_id *id, t_var *var, t_inp *inp, int i)
{
	if (i == inp->it_max)
		id->tab[var->y * WIDTH + var->x] = 0;
	else if (i % 16 == 0)
		id->tab[var->y * WIDTH + var->x] = 4333071;
	else if (i % 16 == 1)
		id->tab[var->y * WIDTH + var->x] = 1640218;
	else if (i % 16 == 2)
		id->tab[var->y * WIDTH + var->x] = 590127;
	else if (i % 16 == 3)
		id->tab[var->y * WIDTH + var->x] = 263241;
	else if (i % 16 == 4)
		id->tab[var->y * WIDTH + var->x] = 1892;
	else if (i % 16 == 5)
		id->tab[var->y * WIDTH + var->x] = 797834;
	else if (i % 16 == 6)
		id->tab[var->y * WIDTH + var->x] = 1594033;
	else
		color_split(id, var, inp, i);
}

void	color_input(int key, t_inp *inp)
{
	if (key == 18)
		inp->color = 1;
	else
		inp->color = 2;
	if (key == 19)
		inp->color_value = 9999;
	if (key == 20)
		inp->color_value = 333333;
	if (key == 21)
		inp->color_value = 555555;
}
