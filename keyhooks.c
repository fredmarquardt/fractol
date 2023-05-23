/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:46:05 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/23 13:37:02 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
			data->zoomy -= (0.4 * data->zoom);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		data->zoomx += (0.4 * data->zoom);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		data->zoomx -= (0.4 * data->zoom);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		data->zoomy += (0.4 * data->zoom);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_delete_image(data->mlx, data->img);
		mlx_terminate(data->mlx);
		mlx_close_window(data->mlx);
		free_data(data);
		ft_exit(EXIT_SUCCESS);
		return ;
	}
	paint_image(data);
	return ;
}

void	ft_exit(int exit_code)
{
	ft_printf("Hope you enjoyed the Fractal :)\n");
	exit(exit_code);
	return ;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (ydelta > 0)
		data->zoom /= 2;
	else if (ydelta < 0)
		data->zoom *= 2;
	if (xdelta < 0)
		data->zoom /= 2;
	else if (xdelta > 0)
		data->zoom *= 2;
	paint_image(data);
	return ;
}
