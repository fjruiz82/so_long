/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:23:18 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/12 12:13:44 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	size_window_init(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 32;
	i = 0;
	while (game->map[i])
		i++;
	game->map_h = i * 32;
}

void	loading_image_rest(t_game *game)
{
	game->temp_load = mlx_load_png("./assets/wall.png");
	game->img_wall = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/ground.png");
	game->img_backg = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/cheese.png");
	game->img_collect = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/exit.png");
	game->img_exit = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/exit2.png");
	game->img_exit_2 = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
}

void	loading_image_player(t_game *game)
{
	game->temp_load = mlx_load_png("./assets/mouse_w.png");
	game->img_player_w = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/mouse_s.png");
	game->img_player_s = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/mouse_d.png");
	game->img_player_d = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
	game->temp_load = mlx_load_png("./assets/mouse_a.png");
	game->img_player_a = mlx_texture_to_image(game->mlx, game->temp_load);
	mlx_delete_texture(game->temp_load);
}

void	moves_printer(t_game *game)
{
	char	*counter;
	char	*txt;
	char	*to_print;

	txt = "Movements: ";
	counter = ft_itoa(game->moves);
	to_print = ft_strjoin(txt, counter);
	mlx_delete_image(game->mlx, game->msg_moves);
	game->msg_moves = mlx_put_string(game->mlx, to_print, 0, game->map_h);
	ft_printf("\nMovements: %d", game->moves);
}

void	game_init(t_game *game)
{
	size_window_init(game);
	game->mlx = mlx_init(game->map_w, game->map_h + 20, "Cheese Quest", true);
	game->moves = 0;
	game->msg_moves = mlx_put_string(game->mlx, "Movements:	0", 0, game->map_h);
	loading_image_rest(game);
	loading_image_player(game);
	map_draw(game);
}
