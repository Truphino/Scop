/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perl_noise_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trecomps <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 18:16:32 by trecomps          #+#    #+#             */
/*   Updated: 2018/03/12 10:57:22 by trecomps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"
#include "noise.h"

void			init_grad(t_noise *env)
{
	env->grad_3d[0] = new_vector(1, 1, 0);
	env->grad_3d[1] = new_vector(-1, 1, 0);
	env->grad_3d[2] = new_vector(1, -1, 0);
	env->grad_3d[3] = new_vector(-1, -1, 0);
	env->grad_3d[4] = new_vector(1, 0, 1);
	env->grad_3d[5] = new_vector(-1, 0, 1);
	env->grad_3d[6] = new_vector(1, 0, -1);
	env->grad_3d[7] = new_vector(-1, 0, -1);
	env->grad_3d[8] = new_vector(0, 1, 1);
	env->grad_3d[9] = new_vector(0, -1, 1);
	env->grad_3d[10] = new_vector(0, 1, -1);
	env->grad_3d[11] = new_vector(0, -1, -1);
	env->grad_3d[12] = new_vector(1, 1, 0);
	env->grad_3d[13] = new_vector(-1, 1, 0);
	env->grad_3d[14] = new_vector(0, -1, 1);
	env->grad_3d[15] = new_vector(0, -1, -1);
}

double			lin_double_inter(double a, double b, double t)
{
	return ((1. - t) * a + (t * b));
}

t_vector		quintic_poly(t_vector f_part)
{
	t_vector	ret;

	ret.x = f_part.x * f_part.x * f_part.x *
		(f_part.x * ((f_part.x * 6.) - 15.) + 10.);
	ret.y = f_part.y * f_part.y * f_part.y *
		(f_part.y * ((f_part.y * 6.) - 15.) + 10.);
	ret.z = f_part.z * f_part.z * f_part.z *
		(f_part.z * ((f_part.z * 6.) - 15.) + 10.);
	return (ret);
}

void			cpy_hash(unsigned char half[256], unsigned char hash[512])
{
	int			i;

	i = 0;
	while (i < 256)
	{
		hash[i] = half[i];
		hash[i + 256] = half[i];
		i++;
	}
}

void			init_hash_table(unsigned char hash[512])
{
	static unsigned char		half[256] = {
		151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225,
		140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148,
		247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32,
		57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168, 68,
		175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83, 111,
		229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40, 244,
		102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187, 208,
		89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109,
		198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147,
		118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182,
		189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70,
		221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108,
		110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251,
		34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145,
		235, 249, 14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 157, 184,
		84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, 93,
		222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180
	};

	cpy_hash(half, hash);
}
