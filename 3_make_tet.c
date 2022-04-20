/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_make_tet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:45:19 by ajones            #+#    #+#             */
/*   Updated: 2022/03/08 18:45:19 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet	*tet_fill(t_tet *newtet, char **array, int nb)
{
	int	x;

	x = 0;
	newtet->block = (char **)malloc(sizeof(newtet->block) * nb + 1);
	if (newtet->block == NULL)
	{
		free (newtet);
		return (NULL);
	}
	while (array[x])
	{
		newtet->block[x] = ft_strdup(array[x]);
		x++;
	}
	newtet->block[x] = NULL;
	newtet->width = count_width(array);
	newtet->height = count_height(array);
	newtet->next = NULL;
	return (newtet);
}

void	*del_t_tet(t_tet **tetris)
{
	t_tet	*temp;

	while ((*tetris))
	{
		temp = *tetris;
		ft_2d_free(temp->block);
		free (temp);
		*tetris = (*tetris)->next;
		temp->next = NULL;
	}
	tetris = NULL;
	return (tetris);
}

int	count_height(char **str)
{
	int	small;
	int	big;
	int	x;
	int	y;

	x = 0;
	big = 0;
	small = -1;
	while (str[x])
	{
		y = 0;
		while (str[x][y] != '\0')
		{
			if (str[x][y] != '.')
			{
				if (small < 0)
					small = x;
				else if (x > big)
					big = x;
			}
			y++;
		}
		x++;
	}
	return (big - small + 1);
}

int	count_width(char **str)
{
	int	small;
	int	big;
	int	x;
	int	y;

	x = 0;
	big = -1;
	small = 5;
	while (str[x])
	{
		y = 0;
		while (str[x][y] != '\0')
		{
			if (str[x][y] != '.')
			{
				if (y < small)
					small = y;
				if (y > big)
					big = y;
			}
			y++;
		}
		x++;
	}
	return (big - small + 1);
}

/*
	These 2 functions ^ find the height and width of the block
*/

t_tet	*make_t_tet(char **array, int nb)
{
	t_tet	*newtet;
	int		x;

	newtet = (t_tet *)malloc(sizeof(t_tet));
	if (newtet == NULL)
		return (NULL);
	x = 0;
	if (array[x])
		return (tet_fill(newtet, array, nb));
	else
		newtet->block = NULL;
	newtet->next = NULL;
	return (newtet);
}
