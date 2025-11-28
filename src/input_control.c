/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:39 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:00:40 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	input_hook(int keycode, t_combo *combo)
{
	if (keycode == 65307)
		close_game(combo);
	if (keycode == 119)
		move_player(combo, 0, -1);
	if (keycode == 97)
		move_player(combo, -1, 0);
	if (keycode == 115)
		move_player(combo, 0, 1);
	if (keycode == 100)
		move_player(combo, 1, 0);
	return (0);
}
