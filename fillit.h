/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:43:24 by mtissari          #+#    #+#             */
/*   Updated: 2022/02/17 18:07:22 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# define MAX_TETRIS 26
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_tet
{
	char			**block;
	char			chr;
	int				width;
	int				height;
	struct s_tet	*next;
}					t_tet;

int		main(const int argc, char **argv);
int		read_tetriminos(int fd, char **block, int x);
int		error_handling(int err);
void	free_buffer(char **block);
void	print_square(char **square);
t_tet	*verify_and_modify(char **array, int num);
int		verify_blocks(char *block, int nb, int last);
int		verify_last(char *block, int y, int i, int connections);
int		count_connections(char *block, int y, int nb);
int		validate_lines(char *block);
t_tet	*modify_blocks(char *block, int nb);
int		count_empty(char *block);
char	**move_left(char **string, int height);
t_tet	*make_t_tet(char **array, int nb);
int		count_width(char **str);
int		count_height(char **str);
void	*del_t_tet(t_tet **tetris);
t_tet	*tet_fill(t_tet *newtet, char **array, int nb);
char	**fill_grid(t_tet *tetris, int nb_of_blocks);
int		square_root(int nb);
char	**make_grid(int size);
int		fillit_solver(t_tet *tetris, char **grid, int g_size, int nb);
int		remove_tet(t_tet *tetris, char **grid);
int		place_check(t_tet *tetris, char **grid, int x, int y);
int		put_tet(t_tet *tetris, char **grid, int x, int y);

#endif
