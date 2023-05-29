/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:24:12 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/05/29 11:06:30 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int32_t	main(int argc, char **argv)
{
	t_game *game;
	game = malloc(sizeof(t_game)); //cómo podría prescindir de esto?
	argc_checker(argc);
	extension_checker(argv[1]);
	game->map = read_map(argv[1]);
	if (map_checker(game))
	{
		game_init(game);
		mlx_key_hook(game->mlx, (mlx_keyfunc)key_hook, game);
		mlx_loop(game->mlx);
		mlx_terminate(game->mlx);
	}
	else
	{
		if (game->map)
			free_map(game->map);
		ft_printf("Error\nInvalid Map\n");
		exit(1);
	}
	//wrong_map(game->map);
	return (0);
}
