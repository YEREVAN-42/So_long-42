/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:39:57 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/11 16:57:57 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	is_rectangular(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[++i])
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
	return (1);
}

static int	is_wall(char **map)
{
	size_t	len;
	int		i;
	int		j;

	i = 0;
	while (map[i])
		++i;
	j = -1;
	while (map[0][++j] && map[i - 1][j])
		if (map[0][j] != '1' || map[i - 1][j] != '1')
			return (0);
	i = 0;
	len = ft_strlen(map[i]);
	while (map[++i])
		if (map[i][0] != '1' || map[i][len -1] != '1')
			return (0);
	return (1);
}

static int	is_validate(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'P' && map[i][j] != 'E')
				return (0);
	}
	return (1);
}

static int	is_in_right_sizes(t_game *game)
{
	int	i;
	int	j;

	game -> n_player = 0;
	game -> n_collect = 0;
	game -> n_exit = 0;
	i = 0;
	while (game -> mlx_map[++i])
	{
		j = 0;
		while (game -> mlx_map[i][++j])
		{
			if (game -> mlx_map[i][j] == 'P')
				game->n_player++;
			else if (game -> mlx_map[i][j] == 'E')
				game->n_exit++;
			else if (game -> mlx_map[i][j] == 'C')
				game->n_collect++;
		}
	}
	if (game -> n_player != 1 || game -> n_collect == 0 || game -> n_exit == 0)
		return (0);
	return (1);
}

void	check_map(t_game *game)
{
	if (is_rectangular(game -> mlx_map) && is_wall(game -> mlx_map)
		&& is_validate(game -> mlx_map) && is_in_right_sizes(game))
		return ;
	else
	{
		if (game -> mlx_map)
			free_map(game -> mlx_map);
		write(2, "\tERROR\n   INVALID MAP\n", 22);
		exit(1);
	}
}
