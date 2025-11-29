/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:39 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/29 01:00:08 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	input_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_game(data);
	if (keycode == 119)
		move_player(data, 0, -1);
	if (keycode == 97)
		move_player(data, -1, 0);
	if (keycode == 115)
		move_player(data, 0, 1);
	if (keycode == 100)
		move_player(data, 1, 0);
	return (0);
}
