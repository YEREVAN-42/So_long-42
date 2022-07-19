/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khovakim <khovakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:40:05 by khovakim          #+#    #+#             */
/*   Updated: 2022/07/14 17:31:19 by khovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

static int	check_argv(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		++i;
	--i;
	if (str[i] == 'r' && str[i - 1] == 'e'
		&& str[i - 2] == 'b' && str[i - 3] == '.')
		return (1);
	return (0);
}

static void	read_and_check_map(char *path, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp_map;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(1);
	tmp_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (*line == '\0')
			break ;
		tmp = tmp_map;
		tmp_map = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	game -> mlx_map = ft_split(tmp_map, '\n');
	free(line);
	free(tmp_map);
	close(fd);
	check_map(game);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2 && check_argv(av[1]))
	{
		read_and_check_map(av[1], &game);
		game_init(&game);
		play_game(&game);
		mlx_loop(game.mlx);
	}
	else
	{
		write(2, "\tERROR\n   INVALID SYNTAX\n", 25);
		exit(1);
	}
	return (0);
}
