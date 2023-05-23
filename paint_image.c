/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:59:34 by fmarquar          #+#    #+#             */
/*   Updated: 2023/04/10 13:21:13 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned long int	rgba(int r, int g, int b, int a)
{
	return (((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
		+ (a & 0xff));
}

unsigned long int	neon(int c_f)
{
	//c_f /= 5;
	//c_f %= c_f;
	if (c_f < 5)
		return (rgba(0, 0, 0, 255));
	if (c_f >= 5 && c_f < 0.2 * M_ITER)
		return (rgba(254, 0, 0, 255 * 5 * c_f / M_ITER));
	if (c_f >= 0.2 * M_ITER && c_f < 0.4 * M_ITER)
		return (rgba(253, 254, 2, 255 * 4 * c_f / M_ITER));
	if (c_f >= 0.4 * M_ITER && c_f < 0.6 * M_ITER)
		return (rgba(11, 255, 1, 255 * 3 * c_f / M_ITER));
	if (c_f >= 0.6 * M_ITER && c_f < 0.8 * M_ITER)
		return (rgba(1, 30, 254, 255 * 2 * c_f / M_ITER));
	if (c_f >= 0.8 * M_ITER && c_f < 1 * M_ITER)
		return (rgba(254, 0, 246, 255 * 1 * c_f / M_ITER));
	if (c_f == M_ITER)
		return (rgba(0, 0, 0, 0));
	return (0);
}

int	paint_image(t_data *data)
{
	int	c_f;

	data->x = 0;
	data->y = 0;
	while (data->y < HEIGHT)
	{
		while (data->x < WIDTH)
		{
			if (data->fractal == 1)
				c_f = mandelbrot(data);
			if (data->fractal == 2)
				c_f = julia(data);
			mlx_put_pixel(data->img, data->x, data->y, neon(c_f));
			data->x++;
		}
		data->x = 0;
		data->y++;
	}
	return (0);
}
