#include "../headers/so_long.h"

int legal_chars_validator(t_map *map) {
    char *legal_chars;
    int i;
    int j;

    i = 0;
    legal_chars = ft_strdup("01CEP");
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if(ft_strchr(legal_chars, map->map[i][j]) == NULL)
                return (1);   
            j++;
        }
        i++;
    }
    return (free(legal_chars), 0);
}

// find players start location either save it in a struct or pass it somehow to flood fill worker

void flood_fill_worker(t_map *map, int x, int y) {
    map->map[y][x] = '1';
    if(x > 0 && map->map[y][x-1] != '1')
        flood_fill_worker(map, x - 1, y);
    if(x < map->size_x - 1 && map->map[y][x+1] != '1')
        flood_fill_worker(map, x + 1, y);
    if(y > 0 && map->map[y-1][x] != '1')
        flood_fill_worker(map, x, y - 1);
    if(y < map->size_y - 1 && map->map[y+1][x] != '1')
        flood_fill_worker(map, x, y + 1);
}

t_map *flood_fill(t_map *map) {
    t_map *map_to_flood;

    map_to_flood = malloc(sizeof(t_map));
    map_to_flood->map = str_arr_resize(map->map, map->size_y + 1);
    map_to_flood->size_x = map->size_x;
    map_to_flood->size_y = map->size_y;
    flood_fill_worker(map_to_flood, 1, 3); // map.ber player start pos
    str_arr_print(map_to_flood->map);
    return (map_to_flood);
}

