/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:51:15 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 13:16:40 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
//# include <stdio.h>

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;

	void	*img_grass;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;

	char	**mlx_map;

	int		map_weight;
	int		map_height;

	int		image_weight;
	int		image_height;

	int		n_player;
	int		n_collect;
	int		n_exit;

	int		x_player;
	int		y_player;

	int		move;
	int		end_game;
}			t_game;

void	free_map(char **map);
void	map_draw(t_game *game);
void	check_map(t_game *game);
void	game_init(t_game *game);
void	play_game(t_game *game);

void	play_a(t_game *game);
void	play_s(t_game *game);
void	play_d(t_game *game);
void	play_w(t_game *game);

int		exit_game(t_game *game);

#endif