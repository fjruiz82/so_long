/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:31 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/13 15:52:21 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_cpy[y])
	{
		x = 0;
		while (game->map_cpy[y][x])
		{
			if (game->map_cpy[y][x] == 'P')
			{
				game->x_player = x;
				game->y_player = y;
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	map_size(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]);
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i;
}

void	flood_fill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || x >= game->map_w || y >= game->map_h
		|| game->map_cpy[y][x] == '1' || game->map_cpy[y][x] == 'X')
		return ;
	game->map_cpy[y][x] = 'X';
	flood_fill(game, x, y - 1);
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
}

int	must_path(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_cpy[y])
	{
		x = 0;
		while (game->map_cpy[y][x])
		{
			if (game->map_cpy[y][x] == 'C' || game->map_cpy[y][x] == 'P'
				|| game->map_cpy[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	map_checker_2(t_game *game)
{
	find_player(game);
	map_size(game);
	flood_fill(game, game->x_player, game->y_player);
	if (!must_path(game))
		return (1);
	return (0);
}
