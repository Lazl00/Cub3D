/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 21:48:06 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/11 21:48:06 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    draw_player(t_game *game, t_player *player)
{
    int     px;
    int     py;
    int     line_length;
    int     i;

    px = (int)(player->x / 5);
    py = (int)(player->y / 5);
    draw_square(px - 5, py - 5, 10, 0xFF0000, game);
    line_length = 20;
    i = 0;
    while (i <= line_length)
    {
        put_pixel(px + (int)(cos(player->angle) * i), py + (int)(sin(player->angle) * i), 0xFF0000, game);
        i++;
    }
}

void    mini_map_handler(t_game *game, t_player *player)
{
    draw_map(game, 0, 0);
    draw_player(game, player);
}        