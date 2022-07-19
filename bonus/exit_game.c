/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:33:23 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/18 14:45:30 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	unsigned short	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

int	exit_game(t_game *game)
{
	mlx_destroy_image(game -> mlx, game -> img_collect);
	mlx_destroy_image(game -> mlx, game -> img_wall);
	mlx_destroy_image(game -> mlx, game -> img_player);
	mlx_destroy_image(game -> mlx, game -> img_grass);
	mlx_destroy_image(game -> mlx, game -> img_exit);
	mlx_destroy_image(game -> mlx, game -> img_enemie);
	mlx_destroy_window(game -> mlx, game -> mlx_win);
	free_map(game -> mlx_map);
	free(game -> mlx);
	exit(0);
	return (0);
}
