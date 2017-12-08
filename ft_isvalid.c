/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:32:04 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:14:09 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_validblock(char **mat)
{
	size_t	i;
	size_t	j;
	size_t	count;
	size_t	touch;

	i = 0;
	count = 0;
	touch = 0;
	while (++i < 5 && (j = 0) == 0)
		while (++j < 5)
			if (ft_istchr(mat[i][j]) == -2 || ft_istchr(mat[i][j]) == 0)
				return (0);
			else if (ft_istchr(mat[i][j]) == 1)
			{
				count++;
				(mat[i][j] == mat[i][j + 1]) ? (touch++) : (touch);
				(mat[i][j] == mat[i][j - 1]) ? (touch++) : (touch);
				(mat[i][j] == mat[i + 1][j]) ? (touch++) : (touch);
				(mat[i][j] == mat[i - 1][j]) ? (touch++) : (touch);
			}
	if (count == 4 && (touch == 6 || touch == 8))
		return (1);
	return (0);
}

static int	ft_validate(char *buf, size_t size)
{
	char	**mat;
	size_t	i;
	size_t	j;

	i = 0;
	j = 1;
	mat = ft_newmat(6, 6, 0);
	while (i++ < size)
	{
		if (i % 21 == 0)
		{
			if (ft_istchr(buf[i - 1]) != -2 || !ft_validblock(mat))
				return (ft_delmat(&mat));
			j = 1;
		}
		else if ((i % 21) % 5 != 0)
			mat[j][(i % 21) % 5] = buf[i - 1];
		else if ((i % 21) % 5 == 0)
			if (++j && ft_istchr(buf[i - 1]) != -2)
				return (ft_delmat(&mat));
	}
	if (!ft_validblock(mat))
		return (ft_delmat(&mat));
	ft_delmat(&mat);
	return (1);
}

char		*ft_isvalid(int fd)
{
	char	buf[BUF_SIZE];
	char	*buf2;
	int		res;
	size_t	size;

	size = read(fd, buf, BUF_SIZE);
	if ((size + 1) % 21 != 0)
		return (0);
	buf2 = (char *)malloc(sizeof(char) * (size + 1));
	if (buf2 == NULL)
		exit(EXIT_FAILURE);
	buf2 = ft_strcpy(buf2, buf);
	res = ft_validate(buf2, size);
	if (res == 0)
		return (NULL);
	return (buf2);
}
