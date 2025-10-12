/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:09:38 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/11 22:08:37 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void check_collision(t_game *game, float new_x, float new_y)
{
    float   margin;
    float   offset_x;
    float   offset_y;
    float   dx;
    float   dy;

    margin = 10.0;
    dx = new_x - game->player.x;
    dy = new_y - game->player.y;
    offset_x = 0;
    offset_y = 0;
    if (dx > 0)
        offset_x = margin;
    else if (dx < 0)
        offset_x = -margin;
    if (dy > 0)
        offset_y = margin;
    else if (dy < 0)
        offset_y = -margin;
    if (!touch(new_x + offset_x, game->player.y, game))
        game->player.x = new_x;
    if (!touch(game->player.x, new_y + offset_y, game))
        game->player.y = new_y;
}

void    apply_movement(t_game *game, float dx, float dy, float speed)
{
    float   length;
    float   new_x;
    float   new_y;

    length = sqrtf(dx * dx + dy * dy);
    if (length == 0)
        return;
    dx = (dx / length) * speed;
    dy = (dy / length) * speed;
    new_x = game->player.x + dx;
    new_y = game->player.y + dy;
    check_collision(game, new_x, new_y);
}




float   get_speed(t_player  *player)
{
    float effective_speed;

    effective_speed = SPEED;
    if (player->sneak)
        effective_speed /= 3;
    if (player->sprint && !player->sneak)
        effective_speed *= 1.5;
    return (effective_speed);
}
