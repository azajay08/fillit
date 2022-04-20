/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_temp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 18:44:56 by ajones            #+#    #+#             */
/*   Updated: 2022/03/10 18:20:04 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	validate_lines(char *block)
{
	int	j;

	j = 0;
	while (block[j] != '\0')
	{
		if (block[j] == '\n')
		{
			if (j != 4 && j != 9 && j != 14 && j != 19 && j != 20)
				return (0);
		}
		if (j == 4 || j == 9 || j == 14 || j == 19 || j == 20)
		{
			if (block[j] != '\n')
				return (0);
		}
		j++;
	}
	return (1);
}

/*
	This function^ checks that the newlines are in the right place,
	And that there are no extra ones
*/

int	verify_last(char *block, int y, int i, int connect)
{
	if ((y == 19 || y == 20) && i == 4 && validate_lines(block) && connect >= 6)
		return (1);
	else
		return (0);
}

int	count_connections(char *block, int y, int nb)
{
	int	connections;

	connections = 0;
	if (block[y + 1] == '#')
		connections++;
	if (block[y - 1] == ('A' + nb))
		connections++;
	if (block[y - 5] == ('A' + nb))
		connections++;
	if (block[y + 5] == '#')
		connections++;
	if (block[y + 1] != '#' && block[y + 5] != '#'
		&& block[y - 1] != ('A' + nb) && block[y - 5] != ('A' + nb))
		return (-10);
	return (connections);
}

int	verify_blocks(char *block, int nb, int last)
{
	int	y;
	int	count;
	int	connections;

	connections = 0;
	count = 0;
	y = 0;
	while (block[y] != '\0' && (block[y] == '#' || block[y] == '.'
			|| block[y] == '\n'))
	{
		if (block[y] == '#')
		{
			block[y] = 'A' + nb;
			count++;
			connections = connections + count_connections(block, y, nb);
		}
		y++;
	}
	if (nb == last)
		return (verify_last(block, y, count, connections));
	else if (y != 21 || count != 4 || !validate_lines(block) || connections < 6)
		return (0);
	return (1);
}

/*
	This function^ verifies the blocks and changes '#' into characters
*/

t_tet	*verify_and_modify(char **array, int num)
{
	int		x;
	t_tet	*tetris;
	t_tet	*start;

	x = 0;
	start = NULL;
	while (array[x])
	{
		if (!verify_blocks(array[x], x, num - 1) || num > 26)
			return ((t_tet *)del_t_tet(&start));
		if (x == 0)
		{
			tetris = modify_blocks(array[x], x);
			start = tetris;
		}
		else
		{
			tetris->next = modify_blocks(array[x], x);
			tetris = tetris->next;
		}
		if (tetris == NULL)
			return ((t_tet *)del_t_tet(&start));
		x++;
	}
	return (start);
}

/*
	This^ is the function that's called from main.
	After the verification is done, we make a list of t_tet's
	and return the start of the list
*/
