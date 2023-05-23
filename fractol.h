/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:46:07 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/23 10:06:28 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <MLX42.h>
# include "./ft_printf/ft_printf.h"
# include <memory.h>
# define WIDTH 500
# define HEIGHT 500
# define M_ITER 300

typedef struct data
{
	int			x;
	int			y;
	double		re;
	double		im;
	double		juliare;
	double		juliaim;
	int			iter;
	double		zoom;
	double		zoomx;
	double		zoomy;
	int			fractal;
	mlx_t		*mlx;
	mlx_image_t	*img;

}t_data;

int		paint_image(t_data *data);
int		check_input(int argc, char *argv[], t_data *data);
int		init_fractal(int argc, char *argv[], t_data *data);
int		mandelbrot(t_data *data);
int		julia(t_data *data);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	my_scrollhook(double xdelta, double ydelta, void *param);
void	ft_exit(int exit_code);
int		ft_exit_instr(int exit_code, t_data *data);
void	free_data(t_data *data);

int		ft_atoi(const char *str);

#endif