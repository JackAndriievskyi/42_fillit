/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:54:36 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:14:49 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_figure	**ft_newbuf(size_t size)
{
	t_figure	**res;
	size_t		i;

	res = (t_figure **)malloc(sizeof(t_figure *) * size + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i++ < size)
	{
		res[i - 1] = (t_figure *)malloc(sizeof(t_figure));
		if (res[i - 1] == NULL)
		{
			while (--i > 0)
				free(res[i - 1]);
			free(res);
			return (NULL);
		}
	}
	res[size] = NULL;
	return (res);
}
