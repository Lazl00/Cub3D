/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:04:25 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/11 22:01:09 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    color_ceiling(int color, t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < HEIGHT / 2)
    {
        while (x < WIDTH)
        {
            put_pixel(x, y, color, game);
            x++;
        }
        x = 0;
        y++;
    }
}

void    color_floor(int color, t_game *game)
{
    int x;
    int y;

    x = 0;
    y = HEIGHT / 2;
    while (y < HEIGHT)
    {
        while (x < WIDTH)
        {
            put_pixel(x, y, color, game);
            x++;
        }
        x = 0;
        y++;
    }
}

void    put_pixel(int x, int y, int color, t_game *game)
{
    int	offset;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		offset = (game->line_len * y) + (x * (game->bits_per_pixel / 8));
		*((unsigned int *)(offset + game->data)) = color;
	}
    
}

void    draw_square(int x, int y, int square_size, int color, t_game *game)
{
    int     i;
    int     j;
    
    i = 0;
    j = 0;
    while (j < square_size)
    {
        while (i < square_size)
        {
            put_pixel(x + i, y + j, color, game);
            i++;
        }
        i = 0;
        j++;
    }
}
