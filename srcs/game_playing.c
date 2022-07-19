/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_playing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 12:28:34 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/13 16:11:13 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "so_long.h"

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
	{
		init_game_play(keycode, game);
		write(1, "Move:  ", 7);
		ft_putnbr_fd(game -> move, 1);
		write(1, "\n", 1);
	}
	return (0);
}

void	play_game(t_game *game)
{
	mlx_key_hook(game -> mlx_win, keypress, game);
	mlx_hook(game -> mlx_win, 17, 1L << 17, exit_game, game);
}
