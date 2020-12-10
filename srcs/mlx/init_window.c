/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 11:08:15 by famacama          #+#    #+#             */
/*   Updated: 2020/12/09 20:58:30 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "../../lib/minilibx_mms/mlx.h"
#include "../../include/milx.h"
//#include "../../lib/minilibx_mms_20200219/mlx.h"
//#include "../../lib/minilibx_mms/mlx.h"
#include "../../lib/minilibx_opengl/mlx.h"

int carre(int a)
{
	a = a * a;
	return (a);
}
/*void *my_mlx_init()
{
	g_set.win_set = mlx_new_window();
	printf("ok\n");
	return(0);
}*/

int close_program(void *param)
{
	param = (void *)param;
	exit(EXIT_SUCCESS);
	return (1);
}
/*
void itohex(int num, char *c)
{
	if (num > 256)
		return;
	if (num > 15)
	{
		ft_dectohexa_plus(num / 16);
		num %= 16;
	}
	if (num > 9)
		ft_putchar_fd(num + 87, 0);
	else
	{
		c = (num + 48);
}

void test()
{
	char *str;
	int i;

	str[2] = "";
	i = 0;

	itohex(r, str[i])
}


*/

int find_sphere(int count_x, int count_y, int count_z)
{
	//(X-Xc)^2 + (Y-Yc)^2 + (Z-Zc)^2 = r^2
	if ((carre(count_x - (g_sphere.x)) + carre(count_y - (g_sphere.y)) + carre(count_z - g_sphere.z)) <= carre(g_sphere.d / 2))
		return (1);
	return (0);
}

int calculate_rgb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int main(int argc, char **argv)
{
	unsigned int count_x;
	unsigned int count_y;
	int count_z;

	unsigned int r;
	unsigned int g;
	unsigned int b;

	r = 1;
	g = 255;
	b = 100;
	ft_parse(argc, argv);
	g_mlx.mlx_ptr = mlx_init();
	g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_reso.reso_x, g_reso.reso_y, "firts window");
	g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_reso.reso_x, g_reso.reso_y);
	g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
	count_y = 0;
	while (count_y < g_reso.reso_y)
	{
		// sphere (X-Xc)^2 + (Y-Yc)^2 + (Z-Zc)^2 = r^2
		count_x = 0;
		while (count_x < g_reso.reso_x)
		{
			count_z = 0;
			while (count_z <= g_sphere.d)
			{
				if (find_sphere(count_x, count_y, count_z) == 1)
					g_mlx.img.data[count_y * g_reso.reso_x + count_x] = calculate_rgb(g_sphere.r, g_sphere.g, g_sphere.b);
				else
					g_mlx.img.data[count_y * g_reso.reso_x + count_x] = calculate_rgb(g_la.r, g_la.g, g_la.b);
				count_z++;
			}
			count_x++;
		}
		count_y++;
	}
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
	//mlx_hook(g_mlx.mlx_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_program, 0); // FINIR PROGRAMME PROPREMENT!
	mlx_loop(g_mlx.mlx_ptr);

	//g_mlx.win_ptr = mlx_new_window(g_mlx.mlx_ptr, g_reso.reso_x, g_reso.reso_y, "First window");
	//lx_loop(g_mlx.mlx_ptr);
	return (0);
}