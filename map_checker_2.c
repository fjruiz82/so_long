/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:53:31 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/13 13:56:35 by fruiz-ca         ###   ########.fr       */
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
	if (x < 0 || y < 0 || x >= game->map_w || y >= game->map_h || game->map_cpy[y][x] == '1' || game->map_cpy[y][x] == 'X')
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
			if (game->map_cpy[y][x] == 'C' || game->map_cpy[y][x] == 'P' || game->map_cpy[y][x] == 'E')
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
	printf("%c\n %c\n",game->map_cpy[3][6],game->map_cpy[3][11]);
	if (!must_path(game))
		return (1);
	return (0);
}

/*
void	floodfill(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->map.size.x || y >= data->map.size.y
		|| data->map.mtx[y][x] == '1' || data->map.mtx[y][x] == 'W')
		return ;
	data->map.mtx[y][x] = 'W';
	floodfill(data, x, y - 1);
	floodfill(data, x + 1, y);
	floodfill(data, x - 1, y);
	floodfill(data, x, y + 1);
	return ;
}
int	browse_p(t_data *data)
{
	int	row;
	int	col;

	row = 0;
	while (row < data->map.size.y)
	{
		col = 0;
		while (col <= data->map.size.x)
		{
			if (data->map.mtx[row][col] == 'P')
			{
				data->img.pos.x = col;
				data->img.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}
int	checks(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.size.y)
	{
		x = 0;
		while (x < data->map.size.x)
		{
			if (data->map.mtx[y][x] == 'C'
				|| data->map.mtx[y][x] == 'P'
				|| data->map.mtx[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
int	check_floodfill(t_data *data)
{
	browse_p(data);
	floodfill(data, data->img.pos.x, data->img.pos.y);
	if (checks(data) == 1)
		return (1);
	return (0);
}
*/