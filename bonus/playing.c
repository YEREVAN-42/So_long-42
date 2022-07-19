/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 15:26:42 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 14:20:19 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_move(t_game *game)
{
	char	*str;

	str = ft_itoa(game -> move);
	mlx_string_put(game -> mlx, game ->mlx_win, 25, 20, 0x000000, "MOVES:   ");
	mlx_string_put(game -> mlx, game ->mlx_win, 100, 20, 0x000000, str);
	free(str);
}

static void	init_game_play(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
	{
		game -> y_player--;
		play_w(game);
	}
	else if (key == KEY_S || key == KEY_DOWN)
	{
		game -> y_player++;
		play_s(game);
	}
	else if (key == KEY_A || key == KEY_LEFT)
	{
		game -> x_player--;
		play_a(game);
	}
	else if (key == KEY_D || key == KEY_RIGHT)
	{
		game -> x_player++;
		play_d(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (game -> end_game == 0)
		init_game_play(keycode, game);
	return (0);
}

void	ft_play_game(t_game *game)
{
	mlx_key_hook(game -> mlx_win, keypress, game);
	mlx_hook(game -> mlx_win, 17, 1L << 17, exit_game, game);
	mlx_hook(game -> mlx_win, 9, 1L << 21, map_draw, game);
	mlx_loop_hook(game -> mlx, animation, game);
}
