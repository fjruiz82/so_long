/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:22:34 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/13 15:51:18 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	pushing_w(t_game *game)
{
	game->direction = 'w';
	game->y_player--;
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collect == 0)
	{
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
		exit_game_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player++;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect--;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player + 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	pushing_s(t_game *game)
{
	game->direction = 's';
	game->y_player++;
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collect == 0)
	{
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
		exit_game_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->y_player--;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect--;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player - 1][game->x_player] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	pushing_d(t_game *game)
{
	game->direction = 'd';
	game->x_player += 1;
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collect == 0)
	{
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		map_draw(game);
		exit_game_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player--;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect--;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player - 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	pushing_a(t_game *game)
{
	game->direction = 'a';
	game->x_player -= 1;
	if (game->map[game->y_player][game->x_player] == 'E'
		&& game->n_collect == 0)
	{
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
		exit_game_win(game);
	}
	else if (game->map[game->y_player][game->x_player] == '1'
			|| game->map[game->y_player][game->x_player] == 'E')
		game->x_player++;
	else
	{
		if (game->map[game->y_player][game->x_player] == 'C')
			game->n_collect--;
		game->map[game->y_player][game->x_player] = 'P';
		game->map[game->y_player][game->x_player + 1] = '0';
		game->moves++;
		map_draw(game);
	}
}

void	key_hook(mlx_key_data_t pushedkey, t_game *game)
{
	if ((pushedkey.key == MLX_KEY_W || pushedkey.key == MLX_KEY_UP)
		&& pushedkey.action == MLX_PRESS)
		pushing_w(game);
	else if ((pushedkey.key == MLX_KEY_S || pushedkey.key == MLX_KEY_DOWN)
		&& pushedkey.action == MLX_PRESS)
		pushing_s(game);
	else if ((pushedkey.key == MLX_KEY_D || pushedkey.key == MLX_KEY_RIGHT)
		&& pushedkey.action == MLX_PRESS)
		pushing_d(game);
	else if ((pushedkey.key == MLX_KEY_A || pushedkey.key == MLX_KEY_LEFT)
		&& pushedkey.action == MLX_PRESS)
		pushing_a(game);
	else if (pushedkey.key == MLX_KEY_ESCAPE && pushedkey.action == MLX_PRESS)
		exit_game(game);
}
