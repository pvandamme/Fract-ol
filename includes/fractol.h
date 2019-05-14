/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvandamm <pvandamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:17:30 by pvandamm          #+#    #+#             */
/*   Updated: 2019/01/22 20:26:12 by pvandamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1000

# include <pthread.h>
# include "math.h"
# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_inp
{
	int				it_max;
	int				pause;
	int				color;
	int				color_value;
	double			zoom;
	double			x1;
	double			y1;
}					t_inp;

typedef struct		s_id
{
	int				bpp;
	int				sizeline;
	int				endian;
	int				fract;
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	unsigned int	*tab;
}					t_id;

typedef struct		s_var
{
	int				x;
	int				y;
	int				y_max;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
}					t_var;

typedef struct		s_data
{
	t_inp			*inp;
	t_var			*var;
	t_id			*id;
}					t_data;

int					julia_hook(int x, int y, void *param);
int					print_julia(t_data *data);
int					print_burningship(t_data *data);
int					print_mandelbrot(t_data *data);
int					print_fract(t_data *data);
int					mouse_hook(int key, int x, int y, void *param);
void				destroy_window(t_id *id);
void				move(int key, t_inp *inp);
void				bzero_tab(unsigned int *tab);
void				init_mandelbrot(t_data *data);
void				init_burningship(t_data *data);
void				init_julia(t_data *data);
void				color(t_id *id, t_var *var, t_inp *inp, int i);
void				color_input(int key, t_inp *inp);

#endif
