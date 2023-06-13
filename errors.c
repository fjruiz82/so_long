/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:21:33 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/12 14:28:54 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	argc_checker(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments!\n");
		exit(EXIT_FAILURE);
	}
}

int	extension_checker(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i
			- 3] == '.')
		return (0);
	ft_printf("Error\nWrong extension!\n");
	exit(EXIT_FAILURE);
}

void	wrong_map(t_game *game)
{
	if (game->map)
		free_map(game->map);
	ft_printf("Error\nInvalid Map!\n");
	exit(EXIT_FAILURE);
}
