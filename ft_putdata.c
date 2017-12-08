/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:23:06 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:15:30 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_getmin(int *xy)
{
	int		min;
	size_t	i;

	i = 0;
	min = xy[i];
	while (++i < 4)
		if (xy[i] < min)
			min = xy[i];
	return (min);
}

void		ft_putdata(t_figure *fig, int *x, int *y, char c)
{
	int		min;
	size_t	i;

	if (fig == NULL || x == NULL || y == NULL)
		exit(EXIT_FAILURE);
	min = ft_getmin(x);
	i = 0;
	while (i < 4)
	{
		fig->x[i] = x[i] - min;
		i++;
	}
	min = ft_getmin(y);
	i = 0;
	while (i < 4)
	{
		fig->y[i] = y[i] - min;
		i++;
	}
	fig->c = c;
}
