/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:18:35 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/12 16:32:49 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	exit_game(t_game *game)
{
	mlx_destroy_image(game -> mlx, game -> img_collect);
	mlx_destroy_image(game -> mlx, game -> img_wall);
	mlx_destroy_image(game -> mlx, game -> img_player);
	mlx_destroy_image(game -> mlx, game -> img_grass);
	mlx_destroy_image(game -> mlx, game -> img_exit);
	mlx_destroy_window(game -> mlx, game -> mlx_win);
	free_map(game -> mlx_map);
	free(game -> mlx);
	exit(0);
	return (0);
}
