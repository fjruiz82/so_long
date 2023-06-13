/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:24:12 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/13 14:33:41 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	argc_checker(argc);
	extension_checker(argv[1]);
	game->map = read_map(argv[1]);
	game->map_cpy = read_map(argv[1]);
	if (map_checker(game) && map_checker_2(game))
	{
		game_init(game);
		mlx_key_hook(game->mlx, (mlx_keyfunc)key_hook, game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
	else
		wrong_map(game);
	return (0);
}
