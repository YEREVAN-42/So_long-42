/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:03:18 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/18 16:06:55 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_update_image(char c, t_game *game)
{
	mlx_destroy_image(game -> mlx, game -> img_player);
	if (c == 'd')
		game -> img_player = mlx_xpm_file_to_image(game -> mlx,
				"extra_files/images/player_D.xpm", &game -> map_weight,
				&game -> map_height);
	else if (c == 'a')
		game -> img_player = mlx_xpm_file_to_image(game -> mlx,
				"extra_files/images/player_A.xpm", &game -> map_weight,
				&game -> map_height);
}

void	play_a(t_game *game)
{
	player_update_image('a', game);
	if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
										&& game -> n_collect == 0)
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		game -> mlx_map[game -> y_player][game -> x_player + 1] = '0';
		game -> end_game = 1;
		game -> move++;
		map_draw(game);
	}
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'K')
		trap_draw(game);
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
			|| game -> mlx_map[game -> y_player][game -> x_player] == '1')
		game -> x_player++;
	else
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		if (game -> mlx_map[game -> y_player][game -> x_player] == 'C')
			game -> n_collect--;
		game -> mlx_map[game -> y_player][game -> x_player] = 'P';
		game -> move++;
		game -> mlx_map[game -> y_player][game -> x_player + 1] = '0';
		map_draw(game);
	}
}

void	play_s(t_game *game)
{
	if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
										&& game -> n_collect == 0)
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		game -> mlx_map[game -> y_player - 1][game -> x_player] = '0';
		game -> end_game = 1;
		game -> move++;
		map_draw(game);
	}
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'K')
		trap_draw(game);
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
			|| game -> mlx_map[game -> y_player][game -> x_player] == '1')
		game -> y_player--;
	else
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		if (game -> mlx_map[game -> y_player][game -> x_player] == 'C')
			game -> n_collect--;
		game -> mlx_map[game -> y_player][game -> x_player] = 'P';
		game -> move++;
		game -> mlx_map[game -> y_player - 1][game -> x_player] = '0';
		map_draw(game);
	}
}

void	play_d(t_game *game)
{
	player_update_image('d', game);
	if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
										&& game -> n_collect == 0)
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		game -> mlx_map[game -> y_player][game -> x_player - 1] = '0';
		game -> end_game = 1;
		game -> move++;
		map_draw(game);
	}
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'K')
		trap_draw(game);
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
			|| game -> mlx_map[game -> y_player][game -> x_player] == '1')
		game -> x_player--;
	else
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		if (game -> mlx_map[game -> y_player][game -> x_player] == 'C')
			game -> n_collect--;
		game -> mlx_map[game -> y_player][game -> x_player] = 'P';
		game -> move++;
		game -> mlx_map[game -> y_player][game -> x_player - 1] = '0';
		map_draw(game);
	}
}

void	play_w(t_game *game)
{
	if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
										&& game -> n_collect == 0)
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		game -> mlx_map[game -> y_player + 1][game -> x_player] = '0';
		game -> end_game = 1;
		game -> move++;
		map_draw(game);
	}
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'K')
		trap_draw(game);
	else if (game -> mlx_map[game -> y_player][game -> x_player] == 'E'
			|| game -> mlx_map[game -> y_player][game -> x_player] == '1')
		game -> y_player++;
	else
	{
		mlx_clear_window(game -> mlx, game -> mlx_win);
		if (game -> mlx_map[game -> y_player][game -> x_player] == 'C')
			game -> n_collect--;
		game -> mlx_map[game -> y_player][game -> x_player] = 'P';
		game -> move++;
		game -> mlx_map[game -> y_player + 1][game -> x_player] = '0';
		map_draw(game);
	}
}
