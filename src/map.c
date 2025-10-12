/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:17:37 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/02 15:17:37 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    draw_map(t_game *game, int i, int j)
{
    char    **map;
    int     color;
    int     block;

    block = BLOCK / 5;
    color = 0x555555;
    map = game->map.map;
    while (map[j])
    {
        while (map[j][i])
        {
            if (map[j][i] == '1')
                draw_square(i * block, j * block, block, color, game);
            else
                draw_square(i * block, j * block, block, 0, game);
            i++;
        }
        i = 0;
        j++;
    }

}

void    get_map(t_game    *game)
{
    char    **map;

    map = malloc(sizeof(char *) * 10);
    map[0] = "1111111111111";
    map[1] = "1000100010001";
    map[2] = "1000000000001";
    map[3] = "1000000000001";
    map[4] = "100000E000001";
    map[5] = "1000000000001";
    map[6] = "1000000000001";
    map[7] = "1000010100001";
    map[8] = "1111111111111";
    map[9] = NULL;

    game->map.map_height = 9;
    game->map.map_width = 13;

    game->map.orientation_player = 'N';

    game->map.player_y = 4 * BLOCK + BLOCK / 2;
    game->map.player_x = 6 * BLOCK + BLOCK / 2;
    game->map.map = map;
}