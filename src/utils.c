/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcournoy <lcournoy@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-07 15:55:20 by lcournoy          #+#    #+#             */
/*   Updated: 2025-10-07 15:55:20 by lcournoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int     ft_strlen(const char *msg)
{
    int i;

    i = 0;
    while (msg[i])
        i++;
    return (i);
}

void    exit_msg(const char *msg)
{
    write(2, "Error: ", 7);
    write(2, msg, ft_strlen(msg));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}