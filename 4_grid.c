/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_grid.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:45:30 by ajones            #+#    #+#             */
/*   Updated: 2022/03/08 18:45:30 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**make_grid(int size)
{
	int		x;
	int		y;
	char	**grid;

	grid = (char **)malloc(sizeof(grid) * (size + 1));
	if (!grid)
		return (NULL);
	x = 0;
	while (x < size)
	{
		grid[x] = (char *)malloc(sizeof(grid) * size + 1);
		if (!grid[x])
		{
			ft_2d_free(grid);
			return (NULL);
		}
		y = 0;
		while (y < size)
			grid[x][y++] = '.';
		grid[x][y] = '\0';
		x++;
	}
	grid[x] = NULL;
	return (grid);
}

/*
	this function^ makes a grid filled with '.' to the size we get 
	from the function square_root
*/

int	square_root(int nb)
{
	int	size;

	size = 2;
	nb = nb * 4;
	while (size * size < nb)
		size++;
	return (size);
}

char	**fill_grid(t_tet *tetris, int nb_of_blocks)
{
	char	**grid;
	int		g_size;
	t_tet	*start;

	start = tetris;
	g_size = square_root(nb_of_blocks);
	grid = make_grid(g_size);
	while (!fillit_solver(start, grid, g_size, nb_of_blocks))
	{
		g_size++;
		ft_2d_free(grid);
		grid = make_grid(g_size);
	}
	del_t_tet (&start);
	return (grid);
}

/*
	This function^ calls the solver and increases the grid size if
	needed
*/
