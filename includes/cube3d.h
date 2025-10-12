/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:32:47 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/01 17:32:47 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 1600
# define HEIGHT 900

# define PI 3.14159265359

#define BLOCK 100

# define W 119   // Z  122
# define A 97    // Q  113   
# define S 115   // S  115   
# define D 100   // D  100   

# define LEFT  65361
# define RIGHT 65363

# define MAJ  65505
# define CTRL 65507

# define ANGLE_SPEED 0.03
# define SPEED 1

# define SPACE  0
# define WALL   1

# define NORTH   0
# define SOUTH   1
# define EAST    2
# define WEST    3

# define NORTH_ANGLE -(PI / 2)
# define WEST_ANGLE PI
# define EAST_ANGLE (PI * 2)
# define SOUTH_ANGLE (PI / 2)
typedef struct s_ray
{
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		face;
	float	perp_dist;
	float	wall_x;
	float	wall_height;
	int		start_y;
	int		end_y;
}	t_ray;

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     width;
    int     height;
}   t_img;

typedef struct s_textures
{
    int     floor_color;
    int     ceiling_color;

    t_img   north;
    t_img   south;
    t_img   west;
    t_img   east;

}   t_textures;

typedef struct s_map
{
    char    **map;

    char    orientation_player;
    int     player_x;
    int     player_y;
    int     map_height;
    int     map_width;

}   t_map;

typedef struct s_player
{
    float   x;
    float   y;

    float   angle;

    bool    up;
    bool    down;
    bool    left;
    bool    right;

    bool    rotate_L;
    bool    rotate_R;

    bool    sneak;
    bool    sprint;

} t_player;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *img;

    char    *data;
    int     bits_per_pixel;
    int     endian;
    int     line_len;

    t_player    player;
    t_textures  textures;
    t_map   map;
    
} t_game;

// textures.c
t_textures  init_textures(void   *mlx);

// drawing_utils.c
void    put_pixel(int x, int y, int color, t_game *game);
void    draw_square(int x, int y, int square_size, int color, t_game *game);
void    color_ceiling(int color, t_game *game);
void    color_floor(int color, t_game *game);

// main.c
void    init_game(t_game    *game);
void    refresh_image(t_game *game, int i, int j);
int draw_loop(t_game *game);

// map.c
void    draw_map(t_game *game, int i, int j);
void    get_map(t_game  *game);

// move.c
void    move_up(t_player *player, float *dx, float *dy);
void    move_down(t_player *player, float *dx, float *dy);
void    move_left(t_player *player, float *dx, float *dy);
void    move_right(t_player *player, float *dx, float *dy);
void    move(t_player *player, t_game *game);

// player.c
void    init_player(t_game  *game);
int     close_window(t_game *game);
int     key_pressed(int keycode, t_game *game);
int     key_released(int keycode, t_player *player);

// raycast.c
bool    touch(float px, float py, t_game *game);
void    draw_line(t_player *player, t_game *game, float start_x, int i);

// movement_utils.c
void    apply_movement(t_game *game, float dx, float dy, float speed);
float   get_speed(t_player  *player);
void check_collision(t_game *game, float new_x, float new_y);

// raycast_utils.c
void	draw_line(t_player *player, t_game *game, float ray_angle, int i);
void	init_ray(t_ray *ray, float angle);
void	init_dda(t_player *player, t_ray *ray, int map_x, int map_y);
void	exec_dda(t_ray *ray, t_game *game, int *map_x, int *map_y);
void	compute_projection(t_ray *ray);
int		get_texture_x(t_player *player, t_ray *ray, t_img *tex);
int		get_texture_y(t_ray *ray, t_img *tex, int y);
void	draw_textured_column(t_player *player, t_game *game, t_ray *ray, int x);

// mini_map.c
void    mini_map_handler(t_game *game, t_player *player);

/* error messages */

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"

#endif