/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:05:53 by mtissari          #+#    #+#             */
/*   Updated: 2022/03/02 19:05:53 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_buffer(char **block)
{
	int	count;

	count = 0;
	while (block[count])
	{
		free (block[count]);
		block[count] = NULL;
		count++;
	}
}

int	read_tetriminos(int fd, char **block, int x)
{
	char	buf[BUFF_SIZE];
	int		ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
	{
		ft_putstr("error\n");
		exit(fd);
		close (fd);
		return (-1);
	}
	if (!ret)
	{
		close (fd);
		return (0);
	}
	block[x] = ft_strdup(buf);
	block[x][ret] = '\0';
	return (1);
}

void	print_square(char **square)
{
	int	x;

	x = 0;
	while (square[x])
	{
		ft_putstr (square[x]);
		ft_putchar ('\n');
		x++;
	}
	ft_2d_free (square);
}

int	error_handling(int err)
{
	if (err == 1)
		ft_putstr("usage: ./fillit <input_file>\n");
	if (err == 2)
		ft_putstr("error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	static char	*block[MAX_TETRIS + 1];
	int			x;
	int			fd;
	t_tet		*tetris;

	x = 0;
	if (argc == 2)
		fd = open (argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
		return (error_handling(1));
	while (read_tetriminos(fd, block, x))
		x++;
	tetris = verify_and_modify(block, x);
	free_buffer(block);
	if (!tetris)
		return (error_handling(2));
	print_square(fill_grid(tetris, x));
	return (0);
}
