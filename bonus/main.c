/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:57:08 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/19 12:58:11 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_check_path(const char *path)
{
	unsigned short	i;

	i = 0;
	while (path[i])
		++i;
	--i;
	if (path[i] == 'r' && path[i - 1] == 'e'
		&& path[i - 2] == 'b' && path[i - 3] == '.')
		return (1);
	return (0);
}

static void	ft_read_and_check_map(const char *path, t_game *game)
{
	int		fd;
	char	*tmp;
	char	*line;
	char	*str_map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	str_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (*line == '\0')
			break ;
		tmp = str_map;
		str_map = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
	game -> mlx_map = ft_split(str_map, '\n');
	free(line);
	free(str_map);
	close(fd);
	ft_check_map(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 && ft_check_path(av[1]))
	{
		ft_read_and_check_map(av[1], &game);
		ft_game_init(&game);
		ft_play_game(&game);
		mlx_loop(game.mlx);
	}
	else
	{
		write(2, "\tERROR\n   INVALID SYNTAX\n", 25);
		exit(1);
	}
	return (0);
}
