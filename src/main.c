/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:32:50 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/01 17:32:50 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    init_game(t_game    *game)
{
    get_map(game);
    init_player(game);
    game->mlx = mlx_init();
    game->textures = init_textures(game->mlx);
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Golem");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bits_per_pixel, &game->line_len, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void    refresh_image(t_game *game, int i, int j)
{
    while (j < HEIGHT)
    {
        while (i < WIDTH)
        {
            put_pixel(i, j, 0x000000, game);
            i++;
        }
        i = 0;
        j++;
    }
}

int draw_loop(t_game *game)
{
    t_player    *player;

    player = &game->player;
    refresh_image(game, 0, 0);
    move(player, game);
    color_ceiling(game->textures.ceiling_color, game);
    color_floor(game->textures.floor_color, game);
    
    float   fraction = PI / 3 / WIDTH;
    float   start_x = player->angle - PI / 6;
    int     i = 0;
    while (i < WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    mini_map_handler(game, player);
    return (0);
}

int main()
{
    t_game  game;

    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_pressed, &game);
    mlx_hook(game.win, 3, 1L<<1, key_released, &game.player);
    mlx_hook(game.win, 17, 0, close_window, &game);

    mlx_loop_hook(game.mlx, draw_loop, &game);
    mlx_loop(game.mlx);
    return (0);
}