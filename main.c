/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:38:29 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/23 13:37:33 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <MLX42.h>
#include <memory.h>
#include "fractol.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

t_data	*init_data(void)
{
	mlx_image_t		*img;
	mlx_t			*mlx;
	t_data			*data;

	data = malloc(sizeof(t_data));
	data->x = 0;
	data->y = 0;
	data->re = 0.0;
	data->im = 0.0;
	data->juliaim = 0.0;
	data->juliare = 0.0;
	data->iter = 0;
	data->zoom = 1;
	data->zoomy = 0;
	data->zoomx = 0;
	data->fractal = 1;
	mlx = mlx_init(WIDTH, HEIGHT, "Freds tolle Fraktale", true);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data->mlx = mlx;
	data->img = img;
	return (data);
}

int32_t	main(int argc, char *argv[])
{
	t_data	*data;

	data = init_data();
	check_input (argc, argv, data);
	init_fractal (argc, argv, data);
	paint_image (data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0)
		error();
	mlx_key_hook(data->mlx, &my_keyhook, data);
	mlx_scroll_hook(data->mlx, &my_scrollhook, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img);
	mlx_terminate(data->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
/*
int	main(int argc, char **argv)
{
	main2(argc, argv);
	system("leaks Game");
}
 */