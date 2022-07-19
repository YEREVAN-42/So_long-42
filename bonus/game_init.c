/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:57:05 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 15:10:02 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	img_init(t_game *game)
{
	game -> img_grass = mlx_xpm_file_to_image(game -> mlx,
			"extra_files/images/grass.xpm", &game -> image_weight,
			&game -> image_height);
	game -> img_wall = mlx_xpm_file_to_image(game -> mlx,
			"extra_files/images/wall.xpm", &game -> image_weight,
			&game -> image_height);
	game -> img_player = mlx_xpm_file_to_image(game -> mlx,
			"extra_files/images/player_D.xpm", &game -> image_weight,
			&game -> image_height);
	game -> img_exit = mlx_xpm_file_to_image(game -> mlx,
			"extra_files/images/door.xpm", &game -> image_weight,
			&game -> image_height);
	game -> img_collect = mlx_xpm_file_to_image(game -> mlx,
			"extra_files/images/collectibles.xpm", &game -> image_weight,
			&game -> image_height);
	game -> img_enemie = mlx_xpm_file_to_image(game -> mlx,
			"extra_files/images/trap1.xpm", &game -> image_weight,
			&game -> image_height);
}

static void	size_window_init(t_game *game)
{
	int	i;

	i = 0;
	game -> image_height = 85;
	game -> image_weight = 114;
	game -> map_weight = ft_strlen(game -> mlx_map[0]) * game -> image_weight;
	while (game -> mlx_map[i])
		++i;
	game -> map_height = i * game -> image_height;
}

void	ft_game_init(t_game *game)
{
	game -> mlx = mlx_init();
	size_window_init(game);
	game -> mlx_win = mlx_new_window(game -> mlx, game -> map_weight,
			game -> map_height, "so_long");
	img_init(game);
	game -> move = 0;
	game -> end_game = 0;
	game -> pos_enemie = 2;
	game -> loop = 0;
	map_draw(game);
}
