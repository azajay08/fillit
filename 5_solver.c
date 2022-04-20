/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_solver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:25:24 by ajones            #+#    #+#             */
/*   Updated: 2022/03/08 18:43:55 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	put_tet(t_tet *tetris, char **grid, int x, int y)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	while (j < tetris->height && tetris->block[j] && count <= 4)
	{
		i = 0;
		while (i < tetris->width && tetris->block[j][i] != '\0')
		{
			if (tetris->block[j][i] != '.' && grid[x + j][y + i] == '.')
			{
				grid[x + j][y + i] = tetris->block[j][i];
				count++;
			}
			i++;
		}
		j++;
	}
	return (1);
}

int	place_check(t_tet *tetris, char **grid, int x, int y)
{
	int		i;
	int		j;
	char	c;

	c = tetris->chr;
	j = 0;
	while (j < tetris->height && tetris->block[j])
	{
		i = 0;
		while (i < tetris->width && tetris->block[j][i] != '\0')
		{
			if (tetris->block[j][i] == c && grid[x + j][y + i] != '.')
				return (0);
			i++;
		}
		j++;
	}
	return (put_tet(tetris, grid, x, y));
}

int	remove_tet(t_tet *tetris, char **grid)
{
	int	i;
	int	c;
	int	j;

	c = tetris->chr;
	j = 0;
	while (grid[j])
	{
		i = 0;
		while (grid[j][i] != '\0')
		{
			if (grid[j][i] == c)
				grid[j][i] = '.';
			i++;
		}
		j++;
	}
	return (1);
}

int	fillit_solver(t_tet *tetris, char **grid, int g_size, int nb)
{
	int	x;
	int	y;

	if (tetris == NULL)
		return (1);
	x = 0;
	while (x < (g_size - tetris->height + 1))
	{
		y = 0;
		while (y < (g_size - tetris->width + 1))
		{
			if (place_check(tetris, grid, x, y))
			{
				if (fillit_solver(tetris->next, grid, g_size, nb))
					return (1);
				else
					remove_tet(tetris, grid);
			}
			y++;
		}
		x++;
	}
	return (0);
}

/*
	This function^ calls itself recursively until it has finished
	or needs a bigger grid. It back tracks using the stack memory
*/
