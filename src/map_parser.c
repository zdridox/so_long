/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:56 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:51:10 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char	*strip_nl(char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			break ;
		}
		i++;
	}
	new_line = ft_strdup(line);
	free(line);
	return (new_line);
}

char	**get_map(char *file_name)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	map = malloc(1 * sizeof(char *));
	if (fd == -1 || !map)
		return (free(map), NULL);
	map[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		line = strip_nl(line);
		map = str_arr_resize(map, 2 + i);
		if (!map)
			return (NULL);
		map[i] = ft_strdup(line);
		map[(i++) + 1] = NULL;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

t_map	*parse_map(char *file_name)
{
	t_map	*map_struct;

	if (ft_strncmp(file_name + (ft_strlen(file_name) - 4), ".ber", 4) != 0)
		return (NULL);
	map_struct = malloc(sizeof(t_map));
	map_struct->map = get_map(file_name);
	if (map_struct->map == NULL)
		return (free(map_struct), NULL);
	map_struct->size_x = ft_strlen(map_struct->map[0]);
	map_struct->size_y = str_arr_length(map_struct->map);
	return (map_struct);
}

// int main() {
//     t_map *map = parse_map("maps/map.ber");
//     str_arr_print(map->map);
//     ft_printf("size: (x: %d, y: %d)", map->size_x, map->size_y);
//     str_arr_free(map->map);
//     free(map);
//     return (0);
// }
