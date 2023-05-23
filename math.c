/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 16:37:38 by fmarquar          #+#    #+#             */
/*   Updated: 2023/04/14 13:18:56 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fractol.h"

//Realteil re auf X-Achse
//Imagninaerteil im auf Y-Achse
//(re + im*i)ˆ2 + (re + im*i)
// = reˆ2 + (2*re*im*i) + (im)ˆ2*iˆ2 + (re + im*i)
// re2 = reˆ2 - imˆ2 + re
// im2 = 2*re*im*i + im*i

t_data	*pixel_to_compl(t_data *data)
{
	data->re = (double) 4 * data->x / WIDTH;
	data->re = (data->re - 2.0) * data->zoom + data->zoomx;
	data->im = (double) 4 * data->y / HEIGHT;
	data->im = (data->im - 2.0) * data->zoom + data->zoomy;
	return (data);
}

int	mandelbrot(t_data *data)
{
	double	re_temp;
	double	reo;
	double	imo;

	data = pixel_to_compl(data);
	data->iter = 0;
	reo = data->re;
	imo = data->im;
	while (data->iter < M_ITER && powf(data->re, 2) + powf(data->im, 2) <= 4.0)
	{
		re_temp = (data->re * data->re) - (data->im * data->im) + reo;
		data->im = (2.0 * data->re * data->im) + imo;
		data->re = re_temp;
		data->iter++;
	}
	return (data->iter);
}

int	julia(t_data *data)
{
	double	re_temp;
	double	reo;
	double	imo;

	data = pixel_to_compl(data);
	data->iter = 0;
	reo = data->juliare / 100;
	imo = data->juliaim / 100;
	while (data->iter < M_ITER && powf(data->re, 2) + powf(data->im, 2) <= 4.0)
	{
		re_temp = (data->re * data->re) - (data->im * data->im) + reo;
		data->im = (2.0 * data->re * data->im) + imo;
		data->re = re_temp;
		data->iter++;
	}
	return (data->iter);
}
