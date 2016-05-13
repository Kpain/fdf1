/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:00:38 by kpain             #+#    #+#             */
/*   Updated: 2016/05/12 05:23:19 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../includes/command.h"
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct				s_coord
{
	int					x_point;
	int					y_point;
	int					**map;
	int					**xy;
}							t_coord;

typedef struct				s_xpm
{
	int					w;
	int					h;
	int					fd;
	void				*xpm;
}							t_xpm;


typedef struct				s_img
{
	unsigned long		img_color;
	char				*data;
	int					sizeline;
	int					endian;
	int					bpp;
}							t_img;

typedef struct				s_env
{
	void				*mlx;
	void				*win;
	void				*img_ptr;
	int					x;
	int					y;
	t_coord				*coord;
	t_img				*img;
}							t_env;

int					check_arguments(int *argc, char **argv, int *fd);
void				open_map(char **argv, int *fd);
void				check_ret_gnl(int *fd, char *line);
void				check_len_map(int x_len, t_coord *coord);
void				stock_coord(char *file, t_coord *coord, t_xpm *xpm);
void				init_coord(char *file, t_coord *coord);
void				count_line_in_file(char *file, t_coord *coord);
void				ft_pixel_put(t_img *img, t_env *env);
//void				print_pixel(t_coord *coord, t_img *img, t_bonus bonus);
#endif
