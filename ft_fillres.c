/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillres.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:04:34 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:13:38 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_delfig(char **res, t_figure *fig, int y, int x)
{
	size_t	i;

	i = 0;
	while (++i <= 4)
		res[y + fig->y[i - 1]][x + fig->x[i - 1]] = FLD_CHR;
}

static void	ft_putfig(char **res, t_figure *fig, int y, int x)
{
	size_t	i;

	i = 0;
	while (++i <= 4)
		res[y + fig->y[i - 1]][x + fig->x[i - 1]] = fig->c;
}

static int	ft_geton(char **res, t_figure *fig, int y, int x)
{
	size_t	i;

	i = 0;
	while (++i <= 4)
		if (res[y + fig->y[i - 1]][x + fig->x[i - 1]] != FLD_CHR)
			return (0);
	return (1);
}

static int	ft_max(int *n)
{
	size_t	i;
	int		res;

	i = 0;
	res = n[i];
	while (++i < 4)
		if (res < n[i])
			res = n[i];
	return (res);
}

int			ft_fillres(char **res, t_figure **fig, size_t size, size_t cnt)
{
	int		i;
	int		j;

	if (fig[cnt] == NULL)
		return (1);
	i = 0;
	while (i++ < (int)size - ft_max(fig[cnt]->y))
	{
		j = 0;
		while (j++ < (int)size - ft_max(fig[cnt]->x))
			if (ft_geton(res, fig[cnt], i - 1, j - 1))
			{
				ft_putfig(res, fig[cnt], i - 1, j - 1);
				if (ft_fillres(res, fig, size, cnt + 1))
					return (1);
				else
					ft_delfig(res, fig[cnt], i - 1, j - 1);
			}
	}
	return (0);
}
