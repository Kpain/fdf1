/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 03:54:55 by kpain             #+#    #+#             */
/*   Updated: 2016/05/12 04:17:27 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_img *img, t_env *env)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (img->img_color & 0xFF0000) >> 16;
	g = (img->img_color & 0xFF00) >> 8;
	b = (img->img_color & 0xFF);
	if (img->endian == 0)
	{
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 2] = r;
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 1] = g;
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 0] = b;
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 3] = 0x00;
	}
	else
	{
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 2] = b;
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 1] = g;
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 0] = r;
		img->data[env->y * img->sizeline + env->x * img->bpp / 8 + 3] = 0x00;
	}
}
/*
void	print_pixel(t_coord *coord, t_img *img, t_bonus bonus)
{
	draw_x(coord, img, bonus);
	draw_y(coord, img, bonus);
}*/
