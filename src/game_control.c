/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:25 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:19:46 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_player(t_data *data, int x, int y)
{
	t_cords	*player_pos;

	player_pos = get_player_cords(data->map);
	if ((player_pos->x + x > data->map->size_x || player_pos->x + x < 0)
		|| (player_pos->y + y > data->map->size_y || player_pos->y + y < 0))
		return (free(player_pos));
	if (data->map->map[player_pos->y + y][player_pos->x + x] != '1'
		&& data->map->map[player_pos->y + y][player_pos->x + x] != 'E')
	{
		if (data->map->map[player_pos->y + y][player_pos->x + x] == 'C')
		{
			data->collectibles++;
		}
		data->map->map[player_pos->y + y][player_pos->x + x] = 'P';
		data->map->map[player_pos->y][player_pos->x] = '0';
		render_map(data);
		ft_printf("\rmoves: %d collected: %d/%d", ++data->moves_count,
			data->collectibles, data->collectible_count);
	}
	if (data->map->map[player_pos->y + y][player_pos->x + x] == 'E'
		&& data->collectible_count == data->collectibles)
	{
		player_exit(data, player_pos);
	}
	free(player_pos);
}

void	player_exit(t_data *data, t_cords *player_pos)
{
	ft_printf("\rmoves: %d collected: %d/%d", ++data->moves_count,
		data->collectibles, data->collectible_count);
	ft_printf("\ngg");
	free(player_pos);
	close_game(data);
}
