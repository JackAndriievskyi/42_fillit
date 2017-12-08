/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:14:13 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:14:24 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_mapbuf(t_figure **fig, char *buf, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		x[4];
	int		y[4];

	i = 0;
	while (i < size)
	{
		j = 0;
		k = 0;
		while (k < 4)
		{
			if (ft_istchr(buf[i * 21 + j]) == 1)
			{
				x[k] = j % 5;
				y[k] = j / 5;
				k++;
			}
			j++;
		}
		ft_putdata(fig[i], x, y, 'A' + i);
		i++;
	}
}
