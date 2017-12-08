/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yandriie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:26:09 by yandriie          #+#    #+#             */
/*   Updated: 2017/11/24 15:11:41 by yandriie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include "./libft/libft.h"

# ifndef BUF_SIZE
#  define BUF_SIZE 546
# endif

# ifndef FIG_CHR
#  define FIG_CHR 35
# endif

# ifndef FLD_CHR
#  define FLD_CHR 46
# endif

# ifndef LMT_CHR
#  define LMT_CHR 10
# endif

typedef struct	s_figure
{
	int		x[4];
	int		y[4];
	char	c;
}				t_figure;

void			ft_delbuf(t_figure ***fig);
int				ft_fillres(char **res, t_figure **fig, size_t size, size_t cnt);
void			ft_printres(char **mat, size_t size);
t_figure		**ft_newbuf(size_t size);
void			ft_mapbuf(t_figure **fig, char *buf, size_t size);
void			ft_fillit(char *buf);
void			ft_putdata(t_figure *fig, int *x, int *y, char c);
char			**ft_newmat(size_t rows, size_t cols, char c);
int				ft_delmat(char ***mat);
int				ft_istchr(char c);
char			*ft_isvalid(int fd);

#endif
