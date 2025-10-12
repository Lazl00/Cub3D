/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:02:14 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/11 21:21:43 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

float distance(float x, float y)
{
    return (sqrt(x * x + y * y));
}

float   fixed_distance(float x1, float y1, float x2, float y2, t_game *game)
{
    float   delta_x;
    float   delta_y;
    float   angle;
    float   fixed_dist;

    delta_x = x2 - x1;
    delta_y = y2 - y1;
    angle = atan2(delta_y, delta_x) - game->player.angle;
    fixed_dist = distance(delta_x, delta_y) * cos(angle);
    return (fixed_dist);
}

bool    touch(float px, float py, t_game *game)
{
    int x;
    int y;

    x = (int)(px / BLOCK);
    y = (int)(py / BLOCK);
    if (game->map.map[y][x] == '1')
        return (true);
    return (false);
}



void	draw_line(t_player *player, t_game *game, float ray_angle, int i)
{
	int		map_x;
	int		map_y;
	t_ray	ray;

	map_x = (int)(player->x / BLOCK);
	map_y = (int)(player->y / BLOCK);
	init_ray(&ray, ray_angle);
	init_dda(player, &ray, map_x, map_y);
	exec_dda(&ray, game, &map_x, &map_y);
	draw_textured_column(player, game, &ray, i);
}
