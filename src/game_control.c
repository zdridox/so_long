#include "../headers/so_long.h"

void move_player(t_map *map, t_data *data, int x, int y)
{
    t_cords *player_pos;

    player_pos = get_player_cords(map);
    if ((player_pos->x + x > map->size_x || player_pos->x + x < 0) || (player_pos->y + y > map->size_y || player_pos->y + y < 0))
        return;
    if (map->map[player_pos->y + y][player_pos->x + x] != '1')
    {
        if (map->map[player_pos->y + y][player_pos->x + x] == 'C')
            data->collectibles++;
        map->map[player_pos->y + y][player_pos->x + x] = 'P';
        map->map[player_pos->y][player_pos->x] = '0';
    }
}