/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:12:57 by engo              #+#    #+#             */
/*   Updated: 2022/11/18 14:55:36 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pathfinding(t_all *all, t_path *p, char **map)
{
	ft_putstr_fd("Non valid path\n", 2);
	mlx_destroy_display(all->data.mlx_ptr);
	free_all(all, p, map);
	exit (1);
}

void	free_free(t_all *g, int i)
{
	free_map(g->map);
	mlx_destroy_display(g->data.mlx_ptr);
	free(g->data.mlx_ptr);
	if (i)
		ft_putstr_fd("Error map.\n", 2);
	exit (1);
}

void	free_all(t_all *all, t_path *p, char **map)
{
	free(all->data.mlx_ptr);
	free_map(map);
	free_map(all->map);
	free(p);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map != NULL)
	{
		while (map[i] != NULL)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}
