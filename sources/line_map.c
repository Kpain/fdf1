/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 23:52:00 by kpain             #+#    #+#             */
/*   Updated: 2016/05/12 05:40:49 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	count_line_in_file(char *file, t_coord *coord)
{
	char	*line;
	int		i;
	int		fd;
	int		x_len;
	char	**split;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		if (i++ == 0)
			x_len = tab_len(split);
		coord->x_point = tab_len(split);
		tab_free(split);
		check_len_map(x_len, coord);
		free(line);
	}
	check_ret_gnl(&fd, line);
	coord->y_point = i;
	close(fd);
}
