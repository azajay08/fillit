/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtissari <mtissari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:44:10 by mtissari          #+#    #+#             */
/*   Updated: 2021/11/30 17:55:05 by mtissari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (s1[x] != '\0')
		x++;
	y = 0;
	while (y < n && s2[y] != '\0')
	{
		s1[x + y] = s2[y];
		y++;
	}
	s1[x + y] = '\0';
	return (s1);
}
