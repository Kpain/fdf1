/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 23:52:00 by kpain             #+#    #+#             */
/*   Updated: 2016/05/12 05:41:02 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_coord(char *file, t_coord *coord)
{
	coord->map = NULL;
	count_line_in_file(file, coord);
}

void	stock_coord(char *file, t_coord *coord, t_xpm *xpm)
{
	char	*line;
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	init_coord(file, coord);
	xpm->fd = open(file, O_RDONLY);
	coord->map = (int **)malloc(sizeof(int *) * coord->y_point);
	while (get_next_line(xpm->fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		coord->map[i] = (int *)malloc(sizeof(int) * coord->x_point);
		while (j < coord->x_point)
		{
			coord->map[i][j] = ft_atoi(split[j]);
			j++;
		}
		tab_free(split);
		free(line);
		j = 0;
		i++;
	}
	close(xpm->fd);
}
