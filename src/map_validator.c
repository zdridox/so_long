/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:50 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:00:08 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/map_validator.h"

void	player_exit_validator(t_data *data)
{
	int	seen_player;
	int	seen_exit;
	int	i;
	int	j;

	i = 0;
	seen_player = 0;
	seen_exit = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'P')
				seen_player++;
			if (data->map->map[i][j] == 'E')
				seen_exit++;
			j++;
		}
		i++;
	}
	if (seen_exit != 1 || seen_player != 1)
		return (throw_error("the number of players/exits is not valid", data));
	legal_chars_validator(data);
}

void	top_bottom_validator(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[0][i])
	{
		if (data->map->map[0][i] != '1')
			return (throw_error("map top/bottom is not solid", data));
		i++;
	}
	i = 0;
	while (data->map->map[data->map->size_y - 1][i])
	{
		if (data->map->map[data->map->size_y - 1][i] != '1')
			return (throw_error("map top/bottom is not solid", data));
		i++;
	}
	player_exit_validator(data);
}

void	walls_validator(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		if (data->map->map[i][0] != '1'
			|| data->map->map[i][data->map->size_x - 1] != '1')
			return (throw_error("walls of the map are not solid.", data));
		i++;
	}
	top_bottom_validator(data);
}

void	size_validator(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		if ((int)ft_strlen(data->map->map[i]) != data->map->size_x)
			return (throw_error("size of the map is invalid.", data));
		i++;
	}
	walls_validator(data);
}

void	validate_map(t_data *data)
{
	size_validator(data);
}
