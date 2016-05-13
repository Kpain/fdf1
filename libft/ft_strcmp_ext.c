/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpain <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 20:58:28 by kpain             #+#    #+#             */
/*   Updated: 2016/05/11 21:01:23 by kpain            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		ft_strcmp_ext(char *str, char *ext)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(str) - ft_strlen(ext);
	while (str[i] == ext[j] && str[i] != '\0')
	{
		i++;
		j++;
	}
	if (str[i] == '\0')
		return (0);
	else
		return (1);
}
