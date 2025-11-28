/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:59:29 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 13:59:30 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_ARR_UTILS_H
# define STR_ARR_UTILS_H

void	str_arr_print(char **arr);
void	str_arr_free(char **arr);
void	str_arr_copy(char **dest, char **src);
char	**str_arr_resize(char **arr, int new_size);
int		str_arr_length(char **arr);
#endif