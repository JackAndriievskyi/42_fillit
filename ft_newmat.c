/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newmat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 09:49:51 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:15:01 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_newmat(size_t rows, size_t cols, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	res = (char **)malloc(sizeof(char *) * rows);
	if (res == NULL)
		exit(EXIT_FAILURE);
	res[0] = (char *)malloc(sizeof(char) * rows * cols);
	if (res[0] == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (++i < rows)
		res[i] = res[i - 1] + cols;
	i = 0;
	while (i++ < rows && ((j = 0) == 0))
		while (j++ < cols)
			res[i - 1][j - 1] = c;
	return (res);
}
