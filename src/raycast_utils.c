/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:54:18 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/08 16:54:18 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    init_ray(t_ray *ray, float angle)
{
	ray->ray_dir_x = cos(angle);
	ray->ray_dir_y = sin(angle);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->face = -1;
}

void    init_dda(t_player *player, t_ray *ray, int map_x, int map_y)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - map_x * BLOCK) / BLOCK * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((map_x + 1) * BLOCK - player->x) / BLOCK * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - map_y * BLOCK) / BLOCK * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((map_y + 1) * BLOCK - player->y) / BLOCK * ray->delta_dist_y;
	}
}

void    exec_dda(t_ray *ray, t_game *game, int *map_x, int *map_y)
{
    int hit;
    
    hit = 0;
    while (!hit)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            *map_x += ray->step_x;
            ray->side = 0;
            ray->face = (ray->step_x > 0) ? WEST : EAST;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            *map_y += ray->step_y;
            ray->side = 1;
            ray->face = (ray->step_y > 0) ? NORTH : SOUTH;
        }
        if (*map_x < 0)
            *map_x = 0;
        else if (*map_x >= game->map.map_width)
            *map_x = game->map.map_width - 1;
        if (*map_y < 0)
            *map_y = 0;
        else if (*map_y >= game->map.map_height)
            *map_y = game->map.map_height - 1;
        if (game->map.map[*map_y][*map_x] == '1')
            hit = 1;
    }
}

t_img   *get_faced_texture(t_game *game, t_ray *ray)
{
    t_img   *tex;

    if (ray->face == NORTH)
        tex = &game->textures.north;
    if (ray->face == SOUTH)
        tex = &game->textures.south;
    if (ray->face == EAST)
        tex = &game->textures.east;
    if (ray->face == WEST)
        tex = &game->textures.west;
    return (tex);
}

void draw_textured_column(t_player *player, t_game *game, t_ray *ray, int x)
{
    t_img   *tex;
    int     y;
    int     tex_x;
    int     tex_y;
    char    *pixel;

    tex = get_faced_texture(game, ray);
    compute_projection(ray);
    tex_x = get_texture_x(player, ray, tex);
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= tex->width)
        tex_x = tex->width - 1;
    y = ray->start_y;
    while (y < ray->end_y)
    {
        tex_y = get_texture_y(ray, tex, y);
        if (tex_y < 0)
            tex_y = 0;
        if (tex_y >= tex->height)
            tex_y = tex->height - 1;
        pixel = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
        put_pixel(x, y, *(unsigned int *)pixel, game);
        y++;
    }
}

void	compute_projection(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_dist = (ray->side_dist_x - ray->delta_dist_x) * BLOCK;
	else
		ray->perp_dist = (ray->side_dist_y - ray->delta_dist_y) * BLOCK;
	ray->wall_height = (BLOCK / ray->perp_dist) * (WIDTH / 2);
	ray->start_y = (HEIGHT - ray->wall_height) / 2;
	ray->end_y = ray->start_y + ray->wall_height;
	if (ray->start_y < 0)
		ray->start_y = 0;
	if (ray->end_y > HEIGHT)
		ray->end_y = HEIGHT;
}

int	get_texture_x(t_player *player, t_ray *ray, t_img *tex)
{
	float	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = player->y / BLOCK + ((ray->side_dist_x - ray->delta_dist_x) * ray->ray_dir_y);
	else
		wall_x = player->x / BLOCK + ((ray->side_dist_y - ray->delta_dist_y) * ray->ray_dir_x);
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (float)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

int	get_texture_y(t_ray *ray, t_img *tex, int y)
{
	int	d;

	d = y * 256 - HEIGHT * 128 + ray->wall_height * 128;
	return (((d * tex->height) / ray->wall_height) / 256);
}
