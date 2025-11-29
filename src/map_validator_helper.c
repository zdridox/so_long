/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:53 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:00:08 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	flood_fill_worker(t_map *map, int x, int y)
{
	map->map[y][x] = '1';
	if (x > 0 && map->map[y][x - 1] != '1' && map->map[y][x - 1] != 'E')
		flood_fill_worker(map, x - 1, y);
	if (x < map->size_x - 1 && map->map[y][x + 1] != '1' && map->map[y][x
		+ 1] != 'E')
		flood_fill_worker(map, x + 1, y);
	if (y > 0 && map->map[y - 1][x] != '1' && map->map[y - 1][x] != 'E')
		flood_fill_worker(map, x, y - 1);
	if (y < map->size_y - 1 && map->map[y + 1][x] != '1' && map->map[y
		+ 1][x] != 'E')
		flood_fill_worker(map, x, y + 1);
}

t_map	*flood_fill(t_map *map, int start_x, int start_y)
{
	t_map	*map_to_flood;

	map_to_flood = malloc(sizeof(t_map));
	map_to_flood->map = malloc((map->size_y + 1) * sizeof(char *));
	str_arr_copy(map_to_flood->map, map->map);
	map_to_flood->map[map->size_y] = NULL;
	map_to_flood->size_x = map->size_x;
	map_to_flood->size_y = map->size_y;
	flood_fill_worker(map_to_flood, start_x, start_y);
	return (map_to_flood);
}

void	flood_fill_validator(t_data *data)
{
	t_map	*flooded;
	t_cords	*player_cords;
	int		i;
	int		j;

	i = 0;
	player_cords = get_player_cords(data->map);
	flooded = flood_fill(data->map, player_cords->x, player_cords->y);
	free(player_cords);
	while (flooded->map[i])
	{
		j = 0;
		while (flooded->map[i][j])
		{
			if (flooded->map[i][j] != '1' && flooded->map[i][j] != 'E')
				return (str_arr_free(flooded->map), free(flooded),
					throw_error("collectible not approachable.", data));
			j++;
		}
		i++;
	}
	str_arr_free(flooded->map);
	free(flooded);
}

void	check_for_collectible(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'C')
				return (flood_fill_validator(data));
			j++;
		}
		i++;
	}
	throw_error("map has no collectibles.", data);
}

void	legal_chars_validator(t_data *data)
{
	char	*legal_chars;
	int		i;
	int		j;

	i = 0;
	legal_chars = ft_strdup("01CEP");
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (ft_strchr(legal_chars, data->map->map[i][j]) == NULL)
				return (free(legal_chars),
					throw_error("map contains illegal characters.", data));
			j++;
		}
		i++;
	}
	free(legal_chars);
	check_for_collectible(data);
}
