/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:10:30 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 13:15:00 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static void	img_draw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game -> mlx, game -> mlx_win,
		img, x * game ->image_weight, y * game -> image_height);
}

static void	img_exit(t_game *game, int x, int y)
{
	if (game -> end_game == 1)
		exit_game(game);
	img_draw(game, game -> img_exit, x, y);
}

static void	img_player(t_game *game, void *img, int x, int y)
{
	game -> x_player = x;
	game -> y_player = y;
	img_draw(game, img, x, y);
}

void	map_draw(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game -> mlx_map[++y])
	{
		x = -1;
		while (game -> mlx_map[y][++x])
		{
			if (game -> mlx_map[y][x] == '1')
				img_draw(game, game -> img_wall, x, y);
			else if (game -> mlx_map[y][x] == '0')
				img_draw(game, game -> img_grass, x, y);
			else if (game -> mlx_map[y][x] == 'E')
				img_exit(game, x, y);
			else if (game -> mlx_map[y][x] == 'P')
				img_player(game, game -> img_player, x, y);
			else if (game -> mlx_map[y][x] == 'C')
				img_draw(game, game -> img_collect, x, y);
		}
	}
}
