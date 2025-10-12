/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:13:52 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/02 13:13:52 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

float   get_spawn_angle(t_game *game)
{
    if (game->map.orientation_player == 'N')
        return (NORTH_ANGLE);
    if (game->map.orientation_player == 'W')
        return (WEST_ANGLE);
    if (game->map.orientation_player == 'E')
        return (EAST_ANGLE);
    else
        return (SOUTH_ANGLE);
}

void    init_player(t_game *game)
{
    game->player.x = game->map.player_x;
    game->player.y = game->map.player_y;
    game->player.angle = get_spawn_angle(game); // placeholder

    game->player.up = false;
    game->player.down = false;
    game->player.left = false;
    game->player.right = false;

    game->player.rotate_L = false;
    game->player.rotate_R = false;

    game->player.sneak = false;
    game->player.sprint = false;
}


int	close_window(t_game *game)
{
    if (game->map.map)
        free(game->map.map);
    if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(0);
	return (0);
}

int     key_pressed(int keycode, t_game *game)
{
    t_player    *player;

    player = &game->player;
    if (keycode == 65307)
		close_window(game);
    if (keycode == W)
        player->up = true;
    if (keycode == A)
        player->left = true;
    if (keycode == S)
        player->down = true;
    if (keycode == D)
        player->right = true;
    if (keycode == LEFT)
        player->rotate_L = true;
    if (keycode == RIGHT)
        player->rotate_R = true;
    if (keycode == MAJ)
        player->sneak = true;
    if (keycode == CTRL)
        player->sprint = true;
    return (0);
}

int     key_released(int keycode, t_player *player)
{
    if (keycode == W)
        player->up = false;
    if (keycode == A)
        player->left = false;
    if (keycode == S)
        player->down = false;
    if (keycode == D)
        player->right = false;
    if (keycode == LEFT)
        player->rotate_L = false;
    if (keycode == RIGHT)
        player->rotate_R = false;
    if (keycode == MAJ)
        player->sneak = false;
    if (keycode == CTRL)
        player->sprint = false;
    return (0);
}
