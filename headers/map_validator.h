/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:59:54 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 13:59:55 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATOR_H
# define MAP_VALIDATOR_H

void	legal_chars_validator(t_combo *combo);
void	flood_fill_validator(t_combo *combo);
void	check_for_collectible(t_combo *combo);
#endif
