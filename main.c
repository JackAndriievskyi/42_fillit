/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:13:34 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:17:08 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*buf;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit <source_file>\n");
		return (1);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("\tCannot open() file \n");
		return (1);
	}
	if ((buf = ft_isvalid(fd)) == NULL)
		ft_putstr("error\n");
	else
		ft_fillit(buf);
	if (close(fd) == -1)
	{
		ft_putstr("\tCannot close() file \n");
		return (1);
	}
	while (1)
		;
	return (0);
}
