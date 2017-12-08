/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:04:47 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 16:07:06 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static size_t	sqr_rval(int n)
{
	int		r;

	r = 1;
	while (r * r < n)
		r++;
	return ((size_t)r);
}

static char		**ft_fillopt(t_figure **fig, size_t size)
{
	char	**res;

	res = ft_newmat(size, size, FLD_CHR);
	if (!ft_fillres(res, fig, size, 0))
		ft_delmat(&res);
	return (res);
}

void			ft_fillit(char *buf)
{
	t_figure	**fig;
	size_t		nb_size;
	size_t		res_size;
	char		**res;

	nb_size = (ft_strlen(buf) + 1) / 21;
	fig = ft_newbuf(nb_size);
	if (fig == NULL)
		exit(EXIT_FAILURE);
	ft_mapbuf(fig, buf, nb_size);
	free(buf);
	res_size = sqr_rval(nb_size * 4);
	while ((res = ft_fillopt(fig, res_size)) == NULL)
		res_size++;
	ft_delbuf(&fig);
	ft_printres(res, res_size);
	ft_delmat(&res);
}
