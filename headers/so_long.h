#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "str_arr_utils.h"

typedef struct s_map {
    char **map;
    int size_x;
    int size_y;
}   t_map;

t_map *parse_map(char *file_name);