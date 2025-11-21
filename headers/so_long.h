#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "str_arr_utils.h"

typedef struct s_map {
    char **map;
    int size_x;
    int size_y;
}   t_map;

typedef struct s_cords {
    int x;
    int y;
}   t_cords;

t_map *parse_map(char *file_name);
t_cords *get_player_cords(t_map *map);
void put_error(char *err_message);
