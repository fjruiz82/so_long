/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:21:55 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/12 11:52:08 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	exit_game_win(t_game *game)
{
	ft_printf("\n __   _____  _   _  __        _____ _   _   _ \n");
	ft_printf(" \\ \\ / / _ \\| | | | \\ \\      / /_ _| \\ | | | |\n");
	ft_printf("  \\ V / | | | | | |  \\ \\ /\\ / / | ||  \\| | | |\n");
	ft_printf("   | || |_| | |_| |   \\ V  V /  | || |\\  | |_|\n");
	ft_printf("   |_| \\___/ \\___/     \\_/\\_/  |___|_| \\_| (_)\n");
	ft_printf("                                              \n");
	ft_printf("\n    You got it in just %d tries, congrats!\n\n", game->moves);
	free_map(game->map);
	mlx_delete_image(game->mlx, game->img_backg);
	mlx_delete_image(game->mlx, game->img_wall);
	mlx_delete_image(game->mlx, game->img_player_a);
	mlx_delete_image(game->mlx, game->img_player_s);
	mlx_delete_image(game->mlx, game->img_player_w);
	mlx_delete_image(game->mlx, game->img_player_d);
	mlx_delete_image(game->mlx, game->img_collect);
	mlx_delete_image(game->mlx, game->img_exit);
	//mlx_terminate;
	mlx_close_window(game->mlx);
	return (0);
}

int	exit_game(t_game *game)
{
	free_map(game->map);
	mlx_delete_image(game->mlx, game->img_backg);
	mlx_delete_image(game->mlx, game->img_wall);
	mlx_delete_image(game->mlx, game->img_player_a);
	mlx_delete_image(game->mlx, game->img_player_s);
	mlx_delete_image(game->mlx, game->img_player_w);
	mlx_delete_image(game->mlx, game->img_player_d);
	mlx_delete_image(game->mlx, game->img_collect);
	mlx_delete_image(game->mlx, game->img_exit);
	//free(game->mlx); no sería necesario si uso mlx_terminate, verdad???
	//mlx_terminate;
	mlx_close_window(game->mlx);
	return (0);
}
