/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:39:44 by famacama          #+#    #+#             */
/*   Updated: 2020/12/09 20:47:25 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

void go_to_next_value(char **line)
{
	while ((((*line)[g_y] > '9') || ((*line)[g_y] < '0') || 
	((*line)[g_y] == ' ')) && (*line)[g_y])		
		g_y++;
}

int find_next_value(char **line)
{
	int n;

	n = 0;
	
	go_to_next_value(line);
	while (((*line)[g_y] <= '9') && ((*line)[g_y] >= '0') && ((*line)[g_y]))
	{
		n *= 10;
		n += (*line)[g_y] - 48;
		g_y++;
	}
	return (n);
}

double str_to_float(char **str)
{
    int 	w;
	double 	d;
	int		neg;

	w = 0;
	go_to_next_value(str);
	neg = ((*str)[g_y - 1] == '-' && ((*str)[g_y])) ? -1 : 1;
	while (ft_isdigit((*str)[g_y]))
	{
		w = w * 10 + ((*str)[g_y]) - '0';
		g_y++;
	}
	if ((*str)[g_y] == '.')
		g_y++;;
	d = 0.0;
	while (ft_isdigit((*str)[g_y]))
	{
		d = d * 10 + ((*str)[g_y]) - '0';
		g_y++;
	}
	while (d >= 1)
		d = d / 10;
	d += w;
	return (neg * d);
}




void lumiere_ambiante(char **line)
{
	//printf("a ok\n");
	g_la.rdlr = str_to_float(line);
	g_la.r = find_next_value(line);
	g_la.g = find_next_value(line);
	g_la.b = find_next_value(line);
	//printf("b ok\n");
}

void resolution(char **line)
{
	g_reso.reso_x = find_next_value(line);
	g_reso.reso_y = find_next_value(line);
}

void camera(char **line)
{
	g_camera.x = str_to_float(line);
	g_camera.y = str_to_float(line);
	g_camera.z = str_to_float(line);
	g_camera.vo_x = str_to_float(line);
	g_camera.vo_y = str_to_float(line);
	g_camera.vo_z = str_to_float(line);
	g_camera.fov = str_to_float(line);
}

void lumiere(char **line)
{
	g_lumiere.x = str_to_float(line);
	g_lumiere.y = str_to_float(line);
	g_lumiere.z = str_to_float(line);
	g_lumiere.rdlr = str_to_float(line);
	g_lumiere.r = find_next_value(line);
	g_lumiere.g = find_next_value(line);
	g_lumiere.b = find_next_value(line);
}

void sphere(char **line)
{
	g_sphere.x = str_to_float(line);
	g_sphere.y = str_to_float(line);
	g_sphere.z = str_to_float(line);
	g_sphere.d = str_to_float(line);
	g_sphere.r = find_next_value(line);
	g_sphere.g = find_next_value(line);
	g_sphere.b = find_next_value(line);	

	/*printf("g_sphere.x %d\n", g_sphere.x);
	printf("g_sphere.y %d\n", g_sphere.y);
	printf("g_sphere.z %d\n", g_sphere.z);
	printf("g_sphere.d %d\n", g_sphere.d);
	printf("g_sphere.r %d\n", g_sphere.r);
	printf("g_sphere.g %d\n", g_sphere.g);
	printf("g_sphere.b %d\n", g_sphere.b);
	printf("g_reso.reso_y %d\n", g_reso.reso_y);
	printf("g_reso.reso_x %d\n", g_reso.reso_x);*/
}

void plane(char **line)
{
	g_plane.x = str_to_float(line);
	g_plane.y = str_to_float(line);
	g_plane.z = str_to_float(line);
	g_plane.vo_x = str_to_float(line);
	g_plane.vo_y = str_to_float(line);
	g_plane.vo_z = str_to_float(line);
	g_plane.r = find_next_value(line);
	g_plane.g = find_next_value(line);
	g_plane.b = find_next_value(line);
}

void square(char **line)
{
	g_square.x = str_to_float(line);
	g_square.y = str_to_float(line);
	g_square.z = str_to_float(line);
	g_square.vo_x = str_to_float(line);
	g_square.vo_y = str_to_float(line);
	g_square.vo_z = str_to_float(line);
	g_square.h = str_to_float(line);
	g_square.r = find_next_value(line);
	g_square.g = find_next_value(line);
	g_square.b = find_next_value(line);
}

void cylindre(char **line)
{
	g_cylindre.x = str_to_float(line);
	g_cylindre.y = str_to_float(line);
	g_cylindre.z = str_to_float(line);
	g_cylindre.vo_x = str_to_float(line);
	g_cylindre.vo_y = str_to_float(line);
	g_cylindre.vo_z = str_to_float(line);
	g_cylindre.dmt = str_to_float(line);
	g_cylindre.h = str_to_float(line);
	g_cylindre.r = find_next_value(line);
	g_cylindre.g = find_next_value(line);
	g_cylindre.b = find_next_value(line);
}

void triangle(char **line)
{
	g_triangle.p1_x = str_to_float(line);
	g_triangle.p1_y = str_to_float(line);
	g_triangle.p1_z = str_to_float(line);
	g_triangle.p2_x = str_to_float(line);
	g_triangle.p2_y = str_to_float(line);
	g_triangle.p2_z = str_to_float(line);
	g_triangle.p3_x = str_to_float(line);
	g_triangle.p3_y = str_to_float(line);
	g_triangle.p3_z = str_to_float(line);
	g_triangle.r = find_next_value(line);
	g_triangle.g = find_next_value(line);
	g_triangle.b = find_next_value(line);

	/*printf("g_triangle.p1_x %f\n", g_triangle.p1_x);
	printf("g_triangle.p1_y %f\n", g_triangle.p1_y);
	printf("g_triangle.p1_z %f\n", g_triangle.p1_z);
	printf("g_triangle.p2_x %f\n", g_triangle.p2_x);
	printf("g_triangle.p2_y %f\n", g_triangle.p2_y);
	printf("g_triangle.p2_z %f\n", g_triangle.p2_z);
	printf("g_triangle.p3_x %f\n", g_triangle.p3_x);
	printf("g_triangle.p3_y %f\n", g_triangle.p3_y);
	printf("g_triangle.p3_z %f\n", g_triangle.p3_z);
	printf("g_triangle.r %d\n", g_triangle.r);
	printf("g_triangle.g %d\n", g_triangle.g);
	printf("g_triangle.b %d\n", g_triangle.b);*/
}

void ft_check_scene(int fd)
{
	int ret;
	int o;
	char *line;

	o = 1;
	line = NULL;

	while ((ret = get_next_line(fd, &line)) || (o == 1))
	{
		g_y = 0;
		if (line[g_y] == 'R')
			resolution(&line);
		else if (line[g_y] == 'A')
			lumiere_ambiante(&line);
		else if (line[g_y] == 'c')
			(line[g_y + 1] == 'y') ? cylindre(&line) : camera(&line);
		else if (line[g_y] == 'l')
			lumiere(&line);
		else if (line[g_y] == 's')
			(line[g_y + 1] == 'q') ? square(&line) : sphere(&line);
		else if (line[g_y] == 'p' && line[g_y + 1] == 'l')
			plane(&line);
		else if (line[g_y] == 't' && line[g_y + 1] == 'r')
			triangle(&line);
		free(line);
		if (ret == 0)
			o = 0;
	}
	//printf("ret %d\n", ret);
}

int ft_parse(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr_fd("not enough files", 0);
		else if(argc > 2)
			ft_putstr_fd("too many aruments", 0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error, cannot open file\n", 0);
		return (0);
	}
	ft_check_scene(fd);
	return (0);
}