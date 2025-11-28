/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:50 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:00:51 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/map_validator.h"

void	player_exit_validator(t_combo *combo)
{
	int	seen_player;
	int	seen_exit;
	int	i;
	int	j;

	i = 0;
	seen_player = 0;
	seen_exit = 0;
	while (combo->map->map[i])
	{
		j = 0;
		while (combo->map->map[i][j])
		{
			if (combo->map->map[i][j] == 'P')
				seen_player++;
			if (combo->map->map[i][j] == 'E')
				seen_exit++;
			j++;
		}
		i++;
	}
	if (seen_exit != 1 || seen_player != 1)
		return (throw_error("the number of players/exits is not valid", combo));
	legal_chars_validator(combo);
}

void	top_bottom_validator(t_combo *combo)
{
	int	i;

	i = 0;
	while (combo->map->map[0][i])
	{
		if (combo->map->map[0][i] != '1')
			return (throw_error("map top/bottom is not solid", combo));
		i++;
	}
	i = 0;
	while (combo->map->map[combo->map->size_y - 1][i])
	{
		if (combo->map->map[combo->map->size_y - 1][i] != '1')
			return (throw_error("map top/bottom is not solid", combo));
		i++;
	}
	player_exit_validator(combo);
}

void	walls_validator(t_combo *combo)
{
	int	i;

	i = 0;
	while (combo->map->map[i])
	{
		if (combo->map->map[i][0] != '1'
			|| combo->map->map[i][combo->map->size_x - 1] != '1')
			return (throw_error("walls of the map are not solid.", combo));
		i++;
	}
	top_bottom_validator(combo);
}

void	size_validator(t_combo *combo)
{
	int	i;

	i = 0;
	while (combo->map->map[i])
	{
		if ((int)ft_strlen(combo->map->map[i]) != combo->map->size_x)
			return (throw_error("size of the map is invalid.", combo));
		i++;
	}
	walls_validator(combo);
}

void	validate_map(t_combo *combo)
{
	size_validator(combo);
}
