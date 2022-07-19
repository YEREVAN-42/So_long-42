/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:14:29 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 14:19:58 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft.h"

# include <mlx.h>
# include <fcntl.h>

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
	char			**mlx_map;

	void			*mlx;
	void			*mlx_win;

	void			*img_wall;
	void			*img_exit;
	void			*img_grass;
	void			*img_player;
	void			*img_enemie;
	void			*img_collect;

	int				image_height;
	int				image_weight;

	int				map_height;
	int				map_weight;

	int				x_player;
	int				y_player;

	unsigned short	move;
	unsigned short	loop;
	unsigned short	end_game;
	unsigned short	pos_enemie;

	unsigned short	n_collect;
	unsigned short	n_player;
	unsigned short	n_exit;
}				t_game;

void			play_a(t_game *game);
void			play_s(t_game *game);
void			play_d(t_game *game);
void			play_w(t_game *game);

void			free_map(char **map);
void			trap_draw(t_game *game);
void			ft_check_map(t_game *game);
void			ft_game_init(t_game *game);
void			ft_play_game(t_game *game);
void			display_move(t_game *game);

int				map_draw(t_game *game);
int				exit_game(t_game *game);
int				animation(t_game *game);

#endif