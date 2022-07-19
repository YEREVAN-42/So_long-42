/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animtion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:20:29 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 15:11:12 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_trap(t_game *game, char *path)
{
	game -> img_enemie = mlx_xpm_file_to_image(game -> mlx, path,
			&game -> image_weight, &game -> image_height);
}

int	animation(t_game *game)
{
	if (game -> loop < 1800)
	{
		game -> loop++;
		return (0);
	}
	game -> loop = 0;
	mlx_destroy_image(game -> mlx, game -> img_enemie);
	if (game -> pos_enemie == 1)
		init_trap(game, "extra_files/images/trap1.xpm");
	else if (game -> pos_enemie == 2)
		init_trap(game, "extra_files/images/trap2.xpm");
	else if (game -> pos_enemie == 3)
		init_trap(game, "extra_files/images/trap3.xpm");
	else if (game -> pos_enemie == 4)
	{
		init_trap(game, "extra_files/images/trap4.xpm");
		game -> pos_enemie = 0;
	}
	map_draw(game);
	game -> pos_enemie++;
	return (0);
}
