/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:24:12 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/05/27 13:30:45 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 650
# define HEIGHT 650

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	mlx_image_t		*img_backg;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_player;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_exit;
	int				map_w;
	int				map_h;
	int				n_collect;
	int				n_player;
	int				n_exit;
	int				x_player;
	int				y_player;
	int				moves;
	mlx_texture_t	*temp_load;
}					t_game;

void				img_draw(t_game *game, void *image, int x, int y);
int					map_draw(t_game *game);
void				game_init(t_game *game);
char				**read_map(char *path);
int					map_checker(t_game *game);
void				key_hook(mlx_key_data_t pushedkey, t_game *game);

int					exit_game(t_game *game);
void				free_map(char **map);

void				argc_checker(int argc);
int					extension_checker(char *argv);
// void wrong_map(T_game *game);
void				loading_image(t_game *game);
int					exit_game_win(t_game *game);

#endif
