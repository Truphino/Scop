/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/14 15:32:02 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

void	identity_matrix(t_matrix m)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = i == j ? 1 : 0;
			j++;
		}
		i++;
	}
}

void	zero_matrix(t_matrix m)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	matrix_multiply(t_matrix res, t_matrix m1, t_matrix m2)
{
	int			row;
	int			col;
	int			inner;

	zero_matrix(res);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			inner = 0;
			while (inner < 4)
			{
				res[row][col] += m1[row][inner] * m2[inner][col];
				inner++;
			}
			col++;
		}
		row++;
	}
}

void	print_matrix(t_matrix matrix)
{
	int	i;

	i = -1;
	while (++i < 4)
		printf("%f\t%f\t%f\t%f\n",
				matrix[i][0],
				matrix[i][1],
				matrix[i][2],
				matrix[i][3]
				);
}
