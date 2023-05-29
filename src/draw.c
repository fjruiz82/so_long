/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:21:45 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/05/27 13:33:49 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	loading_image(t_game *game)
{
	game->temp_load = mlx_load_png("./assets/Tile_31.png");
	game->img_wall = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/Tile_12.png");
	game->img_backg = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/3.png");
	game->img_player = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/cheese.png");
	game->img_collect = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/exit.png");
	game->img_exit = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	/*game->temp_load = mlx_load_png("./assets/exit_2.png");
	game->img_exit_2 = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);*/
}

void	drawing_player(t_game *game, int y, int x)
{
	game->x_player = x;
	game->y_player = y;
	mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->img_collect, x * 32, y * 32);
}
void	drawing_collectable(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->img_collect, x * 32, y * 32);
}

void	drawing_exit(t_game *game, int y, int x)
{
	mlx_image_to_window(game->mlx, game->img_backg, x * 32, y * 32);
	mlx_image_to_window(game->mlx, game->img_exit, x * 32, y * 32);
	/*static void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_colect == 0)
	{
		mlx_delete_image(game->mlx, game->img_exit);
		game->img_exit = mlx_load_png("./assets/exit.png");
	}
	img_draw(game, game->img_exit, x, y);
}*/
}

int	map_draw(t_game *game)
{
	int	y;
	int	x;

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
