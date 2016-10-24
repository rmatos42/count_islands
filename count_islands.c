/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:19:25 by rmatos            #+#    #+#             */
/*   Updated: 2016/10/23 18:43:46 by rmatos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_xdimen(char **map)
{
	printf("xdimen:%zu\n", ft_strlen(map[0]));
	return ft_strlen(map[0]);
}

int		get_ydimen(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
		i++;
	printf("ydimen:%i\n", i);
	return (i);
}

void	delete_island(char **map, int x, int y)
{
	if (map[x][y] == '#')
	{
		map[x][y] = '.';
		if (x > 0)
			delete_island(map, x - 1, y);
		if (x < get_xdimen(map) - 1)
			delete_island(map, x + 1, y);
		if (y > 0)
			delete_island(map, x, y - 1);
		if (y < get_ydimen(map) - 1)
			delete_island(map, x, y + 1);
	}
	
}

int		count_islands(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (j < get_ydimen(map))
	{
		while (i < get_xdimen(map))
		{
			if (map[i][j] == '#')
			{
				count++;
				delete_island(map, i, j);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}
