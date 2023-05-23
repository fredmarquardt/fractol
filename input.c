/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarquar <fmarquar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:29:13 by fmarquar          #+#    #+#             */
/*   Updated: 2023/05/23 11:00:29 by fmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	instructions(void)
{
	ft_printf("Wrong Input!\n");
	ft_printf("Choose your fractal by Starting the Game with './Game X'");
	ft_printf(" - X is the Number of the Fractal \n");
	ft_printf("1 - Mandelbrot\n");
	ft_printf("2 - Julia\n");
	ft_printf("with Julia you can also start the Game with './Game X RE IM'");
	ft_printf("where the Starting point of the Fractal is RE/100 and IM/100");
	ft_printf("for IM and RE you can choose Int values between -100 and 100\n");
	return ;
}

int	ft_exit_instr(int exit_code, t_data *data)
{
	instructions();
	mlx_close_window(data->mlx);
	exit(exit_code);
	return (exit_code);
}

int	valid_input(char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (c[0] == '-' || c[0] == '+')
		j++;
	while (c[i + j] != '\0')
	{
		if (i >= 3)
			return (1);
		if (c[i + j] < '0' || c[i + j] > '9')
			return (1);
		i++;
	}
	if (ft_atoi(c) < -100 || ft_atoi(c) > 100)
		return (1);
	return (0);
}

int	check_input(int argc, char *argv[], t_data *data)
{
	if (argc < 2 || argc > 4)
		ft_exit_instr(EXIT_SUCCESS, data);
	else if (*argv[1] == '1' && (argc > 2 || argv[1][1] != '\0'))
		ft_exit_instr(EXIT_SUCCESS, data);
	else if (*argv[1] != '1' && *argv[1] != '2')
		ft_exit_instr(EXIT_SUCCESS, data);
	else if (*argv[1] == '2' && argc == 2)
		return (0);
	else if (*argv[1] == '2' && argv[1][1] != '\0')
		ft_exit_instr(EXIT_SUCCESS, data);
	else if (*argv[1] == '2' && valid_input(argv[2]))
		ft_exit_instr(EXIT_SUCCESS, data);
	else if (*argv[1] == '2' && valid_input(argv[3]))
		ft_exit_instr(EXIT_SUCCESS, data);
	return (0);
}

int	init_fractal(int argc, char *argv[], t_data *data)
{
	if (*argv[1] == '1')
		data->fractal = 1;
	if (*argv[1] == '2' && argc == 4)
	{
		data->fractal = 2;
		data->juliare = ft_atoi(argv[2]);
		data->juliaim = ft_atoi(argv[3]);
	}
	if (*argv[1] == '2' && argc == 2)
	{
		data->fractal = 2;
		data->juliare = -100;
		data->juliaim = 0;
	}
	return (0);
}
