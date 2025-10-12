/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:29:17 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/02 16:29:17 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    move_up(t_player *player, float *dx, float *dy)
{
    *dx += cos(player->angle);
    *dy += sin(player->angle);
}

void    move_down(t_player *player, float *dx, float *dy)
{
    *dx -= cos(player->angle);
    *dy -= sin(player->angle);
}

void    move_left(t_player *player, float *dx, float *dy)
{
    *dx += sin(player->angle);
    *dy -= cos(player->angle);
}

void    move_right(t_player *player, float *dx, float *dy)
{
    *dx -= sin(player->angle);
    *dy += cos(player->angle);
}

void    move(t_player *player, t_game *game)
{
    float   speed;
    float   dx;
    float   dy;

    dx = 0;
    dy = 0;
    speed = get_speed(player);
    if (player->rotate_L)
        player->angle -= ANGLE_SPEED;
    if (player->rotate_R)
        player->angle += ANGLE_SPEED;
    if (player->angle > 2 * PI)
        player->angle -= 2 * PI;
    if (player->angle < 0)
        player->angle += 2 * PI;
    if (player->up)
        move_up(player, &dx, &dy);
    if (player->down)
        move_down(player, &dx, &dy);
    if (player->left)
        move_left(player, &dx, &dy);
    if (player->right)
        move_right(player, &dx, &dy);
    apply_movement(game, dx, dy, speed);
}

