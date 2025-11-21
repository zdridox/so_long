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

t_map *flood_fill(t_map *map, int start_x, int start_y) {
    t_map *map_to_flood;

    map_to_flood = malloc(sizeof(t_map));
    map_to_flood->map = malloc((map->size_y + 1) * sizeof(char *));
    str_arr_copy(map_to_flood->map, map->map);
    map_to_flood->map[map->size_y] = NULL;
    map_to_flood->size_x = map->size_x;
    map_to_flood->size_y = map->size_y;
    flood_fill_worker(map_to_flood, start_x, start_y);
    return (map_to_flood);
}

int flood_fill_validator(t_map *map) {
    t_map *flooded;
    t_cords *player_cords;
    int i;
    int j;

    i = 0;
    player_cords = get_player_cords(map);
    flooded = flood_fill(map, player_cords->x, player_cords->y);
    free(player_cords);
    while (flooded->map[i])
    {
        j = 0;
        while (flooded->map[i][j])
        {
            if(flooded->map[i][j] != '1')
                return (1);
            j++;
        }
        i++;
    }
    str_arr_free(flooded->map);
    free(flooded);
    return (0);
}

int check_for_collectible(t_map *map) {
    int i;
    int j;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if(map->map[i][j] == 'C')
                return (0);
            j++;
        }
        
        i++;
    }
    
    return (1);
}