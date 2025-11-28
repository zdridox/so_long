/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:25 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:00:26 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_player(t_combo *combo, int x, int y)
{
	t_cords	*player_pos;

	player_pos = get_player_cords(combo->map);
	if ((player_pos->x + x > combo->map->size_x || player_pos->x + x < 0)
		|| (player_pos->y + y > combo->map->size_y || player_pos->y + y < 0))
		return (free(player_pos));
	if (combo->map->map[player_pos->y + y][player_pos->x + x] != '1'
		&& combo->map->map[player_pos->y + y][player_pos->x + x] != 'E')
	{
		if (combo->map->map[player_pos->y + y][player_pos->x + x] == 'C')
		{
			combo->data->collectibles++;
		}
		combo->map->map[player_pos->y + y][player_pos->x + x] = 'P';
		combo->map->map[player_pos->y][player_pos->x] = '0';
		render_map(combo->map, combo->data);
		ft_printf("\rmoves: %d collected: %d/%d", ++combo->data->moves_count,
			combo->data->collectibles, combo->data->collectible_count);
	}
	if (combo->map->map[player_pos->y + y][player_pos->x + x] == 'E'
		&& combo->data->collectible_count == combo->data->collectibles)
	{
		player_exit(combo, player_pos);
	}
	free(player_pos);
}

void	player_exit(t_combo *combo, t_cords *player_pos)
{
	ft_printf("\rmoves: %d collected: %d/%d", ++combo->data->moves_count,
		combo->data->collectibles, combo->data->collectible_count);
	ft_printf("\ngg");
	free(player_pos);
	close_game(combo);
}
