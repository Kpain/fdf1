/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 20:47:54 by kpain             #+#    #+#             */
/*   Updated: 2016/05/11 23:17:43 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			check_arguments(int *argc, char **argv, int *fd)
{
	if (*argc != 2)
	{
		ft_putstr("ERROR");
		exit(EXIT_FAILURE);
	}
	open_map(&(*argv), fd);
	return (EXIT_SUCCESS);
}

void		open_map(char **argv, int *fd)
{
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "/dev", 4) == 0)
	{
		ft_putendl("ERROR");
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp_ext(argv[1], ".fdf") == 1)
	{
		ft_putendl("ERROR");
		exit(EXIT_FAILURE);
	}
}

void		check_ret_gnl(int *fd, char *line)
{
	if (get_next_line(*fd, &line) < 0)
	{
		ft_putendl("ERROR");
		exit(EXIT_FAILURE);
	}
}

void		check_len_map(int x_len, t_coord *coord)
{
	if (x_len != coord->x_point)
	{
		ft_putendl("ERROR");
		exit(EXIT_FAILURE);
	}
}
