#include "../include/milx.h"





float	diff_angle(float u[3], float v[3])
{
	float	ang;
	ang = (u[0] * v[0] + u[1] * v[1] + u[2] * v[2]);
	return (acos(ang) * (180 / M_PI));
}

t_vector norm_vector(t_vector p1)
{
	//√(x² + y² + z²)
	float som;

	som = sqrt(pow(p1.x,2) + pow(p1.y,2) + pow(p1.z,2));
	p1.x = p1.x / som;
	p1.y = p1.y / som;
	p1.z = p1.z / som;

	return (p1);
}

int main(void)
{
	t_vector v;

	v.x = 1;
	v.y = 2;
	v.z = 3;

	v = norm_vector(v);
	printf("x == %f\n", v.x);
	printf("y == %f\n", v.y);
	printf("z == %f\n", v.z);
	return (0);
}



/*
int main(void)
{
	t_mlx	mlx;
	int		count_w;
	int		count_h;
	int		count_z;
	int		radius;
	
	count_h = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "najima_window");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l, &mlx.img.endian);
	radius = 200;

	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			count_z = -1;
			while(++count_z < radius * 2)
			{
			//if (count_w > WIN_WIDTH / 3 && count_w < (2 * WIN_WIDTH / 3) && count_h > WIN_WIDTH / 3 && count_h < (2 * WIN_WIDTH / 3))
			//{
			//	mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			//}
			if (ft_square(count_w - (WIN_WIDTH / 2)) + ft_square(count_h - WIN_HEIGHT/2) + 
			ft_square(count_z - (30)) <= ft_square(radius)) 
			{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = ((ft_square(count_w - (WIN_WIDTH / 2)) + 
				ft_square(count_h - WIN_HEIGHT/2) + ft_square(count_z - (30))) % 2) ? 0xFFFFFF : 0xADD8E6;
			}
			//if (count_w == WIN_WIDTH / 2)
			//	mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
			//else
			//	mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
			}
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
*/