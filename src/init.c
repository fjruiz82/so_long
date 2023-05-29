/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:23:18 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/05/27 13:26:56 by fruiz-ca         ###   ########.fr       */
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

void	game_init(t_game *game)
{
	size_window_init(game);
	game->mlx = mlx_init(game->map_w, game->map_h, "Cheese Quest", true);
	game->moves = 0;
	loading_image(game);
	map_draw(game);
}
