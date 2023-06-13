/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:21:45 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/13 13:24:56 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	drawing_player(t_game *game, int y, int x)
{
	game->x_player = x;
	game->y_player = y;
	if (game->direction == 'd' || game->moves == 0)
	{
		mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->img_player_d, x * 32, y * 32);
	}
	else if (game->direction == 's')
	{
		mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->img_player_s, x * 32, y * 32);
	}
	else if (game->direction == 'w')
	{
		mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->img_player_w, x * 32, y * 32);
	}
	else if (game->direction == 'a')
	{
		mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->img_player_a, x * 32, y * 32);
	}
}

void	drawing_collectable(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->img_collect, x * 32, y * 32);
}

void	drawing_exit(t_game *game, int y, int x)
{
	if (game->n_collect == 0)
	{
		mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->img_exit_2, x * 32, y * 32);
	}
	else
	{
		mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
		mlx_image_to_window(game->mlx, game->img_exit, x * 32, y * 32);
	}
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

	moves_printer(game);
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img_wall, x * 32, y * 32);
			else if (game->map[y][x] == '0')
				mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
			else if (game->map[y][x] == 'P')
				drawing_player(game, y, x);
			else if (game->map[y][x] == 'C')
				drawing_collectable(game, y, x);
			else if (game->map[y][x] == 'E')
				drawing_exit(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
