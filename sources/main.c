/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 16:12:19 by kpain             #+#    #+#             */
/*   Updated: 2016/05/12 05:22:24 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_env		env;
	t_coord		coord;
	t_xpm		xpm;
	t_img		img;
	
	check_arguments(&argc, (&(*argv)), &xpm.fd);
	stock_coord(argv[1], &coord, &xpm);
	env.coord = &coord;
	env.mlx = mlx_init();
	env.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	img.data = mlx_get_data_addr(env.img, &img.bpp, &img.sizeline, &img.endian);
	env.img = &img;
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "FDF");
	xpm.xpm = mlx_xpm_file_to_image(env.mlx, "pics/s.xpm", &xpm.w, &xpm.h);
	mlx_put_image_to_window(env.mlx, env.win, xpm.xpm, 0, 0);
	//mlx_hook(env.win, 2, 3, key_hook, (void*)&env);
	mlx_loop(env.mlx);
	return (0);
}
