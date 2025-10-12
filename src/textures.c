/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 15:24:21 by lcournoy          #+#    #+#             */
/*   Updated: 2025/10/08 15:24:21 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

t_img   load_texture(void *mlx,  char *path)
{
    t_img img;

    img.img = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
    if (!img.img)
    {
        printf("Erreur : impossible de charger %s\n", path);
        exit(1);
    }
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    return img;
}

t_textures init_textures(void *mlx)
{
    t_textures tex;

    tex.north = load_texture(mlx, "./dead_ground.xpm");
    tex.south = load_texture(mlx, "./dead_ground.xpm");
    tex.east  = load_texture(mlx, "./dead_ground.xpm");
    tex.west  = load_texture(mlx, "./dead_ground.xpm");

    tex.ceiling_color = 0x520A0A;
    tex.floor_color   = 0x3b0707;

    return tex;
}

