#include "../headers/so_long.h"
#include "../headers/map_validator.h"

int size_validator(t_map *map)
{
    int i;

    i = 0;
    while (map->map[i])
    {
        if (ft_strlen(map->map[i]) != map->size_x)
            return (1);
        i++;
    }
    return (0);
}

int player_exit_validator(t_map *map)
{
    int seen_player;
    int seen_exit;
    int i;
    int j;

    i = 0;
    seen_player = 0;
    seen_exit = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
                seen_player++;
            if (map->map[i][j] == 'E')
                seen_exit++;
            j++;
        }
        i++;
    }
    return (!(seen_exit == 1 && seen_player == 1));
}

int top_bottom_validator(t_map *map)
{
    int i;

    i = 0;
    while (map->map[0][i])
    {
        if (map->map[0][i] != '1')
            return (1);
        i++;
    }
    i = 0;
    while (map->map[map->size_y - 1][i])
    {
        if (map->map[map->size_y - 1][i] != '1')
            return (1);
        i++;
    }
    return (0);
}

int walls_validator(t_map *map)
{
    int i;

    i = 0;
    while (map->map[i])
    {
        if (map->map[i][0] != '1' || map->map[i][map->size_x - 1] != '1')
            return (1);
        i++;
    }
    return (0);
}

int validate_map(t_map *map)
{
    int result;

    result = 0;
    if (!map || !map->map)
        return (1);
    result += size_validator(map);
    result += player_exit_validator(map);
    result += top_bottom_validator(map);
    result += walls_validator(map);
    result += legal_chars_validator(map);
    result += flood_fill_validator(map);
    result += check_for_collectible(map);
    return (result);
}

int main(int argc, char **argv)
{
    t_map *map = parse_map(argv[1]);
    ft_printf("result: %d\n", validate_map(map));
    t_cords *player_cords = get_player_cords(map);
    ft_printf("player cords: (x: %d, y: %d)\n\n", player_cords->x, player_cords->y);
    t_map *flooded = flood_fill(map, player_cords->x, player_cords->y);
    str_arr_print(map->map);
    ft_printf("\n");
    str_arr_print(flooded->map);
    if (map)
        str_arr_free(map->map);
    free(map);
    if (flooded)
        str_arr_free(flooded->map);
    free(flooded);
    free(player_cords);
    return 0;
}

// TODO
//  make each validator function call another one and on error just print it and exit() no need for main validator function then
