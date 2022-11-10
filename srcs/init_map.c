/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:37:00 by engo              #+#    #+#             */
/*   Updated: 2022/11/10 16:05:17 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../minilibx-linux/mlx.h"

void	put_img_on_window_2(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '0')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[3].img, x_pos, y_pos);
	else if (c == 'E')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[4].img, x_pos, y_pos);
}

void	put_img_on_window(t_all *all, int x_pos, int y_pos, char c)
{
	if (c == '1')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[0].img, x_pos, y_pos);
	else if (c == 'P')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[1].img, x_pos, y_pos);
	else if (c == 'C')
		mlx_put_image_to_window(all->data.mlx_ptr, all->data.mlx_win,
			all->image[2].img, x_pos, y_pos);
	else
		put_img_on_window_2(all, x_pos, y_pos, c);
}

void	init_img(t_all *all)
{
	all->image[0].img = mlx_xpm_file_to_image(all->data.mlx_ptr, WALL,
			&all->image[0].height, &all->image[0].width);
	all->image[1].img = mlx_xpm_file_to_image(all->data.mlx_ptr, PLAYER,
			&all->image[1].height, &all->image[1].width);
	all->image[2].img = mlx_xpm_file_to_image(all->data.mlx_ptr, COLLECT,
			&all->image[2].height, &all->image[2].width);
	all->image[3].img = mlx_xpm_file_to_image(all->data.mlx_ptr, FLOOR,
			&all->image[3].height, &all->image[3].width);
	all->image[4].img = mlx_xpm_file_to_image(all->data.mlx_ptr, EXIT,
			&all->image[4].height, &all->image[4].width);
}

void	open_map(t_all *g, char **av)
{
	static int tamere = 0;
	int	fd;

	if (!tamere) {
		fd = open(av[1], O_RDONLY);
		g->map = get_next_line(fd);
		tamere = 1;
		close(fd);
	}
}

void	init_size_map(t_all *g)
{
	int	i;

	i = 0;
	g->x = ft_strlen(g->map[i]);
	while (g->map[i])
	{	
		if (ft_strlen(g->map[0]) != ft_strlen(g->map[i]))
			exit (1);
		i++;
	}
	g->y = i;
	collect_all(g);
}
