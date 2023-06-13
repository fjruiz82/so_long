/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruiz-ca <fruiz-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:24:12 by fruiz-ca          #+#    #+#             */
/*   Updated: 2023/06/13 14:51:35 by fruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	char			**map_cpy;
	mlx_image_t		*img_backg;
	mlx_image_t		*img_wall;
	mlx_image_t		*img_player_w;
	mlx_image_t		*img_player_s;
	mlx_image_t		*img_player_d;
	mlx_image_t		*img_player_a;
	mlx_image_t		*img_collect;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_exit_2;
	int				map_w;
	int				map_h;
	int				n_collect;
	int				n_player;
	int				n_exit;
	int				x_player;
	int				y_player;
	int				moves;
	mlx_texture_t	*temp_load;
	char			direction;
	mlx_image_t		*msg_moves;
}					t_game;

void				img_draw(t_game *game, void *image, int x, int y);
int					map_draw(t_game *game);
void				game_init(t_game *game);
char				**read_map(char *path);
int					map_checker(t_game *game);
int					map_checker_2(t_game *game);
void				key_hook(mlx_key_data_t pushedkey, t_game *game);
int					exit_game(t_game *game);
void				free_map(char **map);
void				argc_checker(int argc);
int					extension_checker(char *argv);
void				wrong_map(t_game *game);
void				loading_image_rest(t_game *game);
void				loading_image_player(t_game *game);
int					exit_game_win(t_game *game);
void				moves_printer(t_game *game);

#endif
