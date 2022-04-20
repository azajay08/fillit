/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_modify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:25:28 by mtissari          #+#    #+#             */
/*   Updated: 2022/03/08 18:28:37 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**move_left(char **string, int height)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (string[x] && string[x][y] == '.')
		x++;
	if (x == height)
	{
		x = 0;
		while (string[x])
		{
			while (string[x][y] != '\0')
			{
				string[x][y] = string[x][y + 1];
				y++;
			}
			string[x][y] = '.';
			string[x][y + 1] = '\0';
			x++;
			y = 0;
		}
		move_left(string, height);
	}
	return (string);
}

int	count_empty(char *block)
{
	int	count;
	int	i;
	int	find;

	i = 0;
	find = 0;
	count = 0;
	while (block[i] != '\0' && find == 0)
	{
		while (block[i] != '\n')
		{
			if (block[i] != '.')
				find++;
			i++;
		}
		if (find == 0)
			count++;
		i++;
	}
	return (count);
}

t_tet	*modify_blocks(char *block, int nb)
{
	int		i;
	int		x;
	char	**newstr;
	t_tet	*tetro;

	x = 0;
	i = count_empty(block) * 5;
	newstr = (char **)malloc(sizeof(newstr) * (5 - (i / 5)));
	if (!newstr)
		return (NULL);
	while (i <= 19)
	{
		if ((block[i] == '\n' && block[i - 1] != '\n') || block[i] == '\0')
		{
			newstr[x] = ft_strsub(block, (i - 4), 4);
			x++;
		}
		i++;
	}
	newstr[x] = NULL;
	tetro = make_t_tet(move_left(newstr, x), x);
	tetro->chr = 'A' + nb;
	ft_2d_free(newstr);
	return (tetro);
}

/*
	This function ^ modifies the array into a 2d array and sends
	it to make_t_tet to made into tetris blocks
*/