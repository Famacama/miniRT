/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:37:12 by famacama          #+#    #+#             */
/*   Updated: 2020/12/10 15:31:48 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

#include "../lib/libft/libft.h"
#include <fcntl.h>
#include <math.h>
# include "../utils/get_next_line/get_next_line.h"
#include <stdio.h> //a effacer



typedef struct  s_resolution
{
    //resolution de lecrant
    unsigned int reso_x;
    unsigned int reso_y;
}               t_resolution;

typedef struct s_vector
{
    double x;
    double y;
    double z;
}               t_vector;


typedef struct t_lumiere_ambiante
{
    double rdlr; //ratio dans le range
    unsigned int r;
    unsigned int g;
    unsigned int b;
}               t_la;

typedef struct s_camera
{
    //t_vector c;
    double  x;
    double  y;
    double  z;
    double vo_x;
    double vo_y;
    double vo_z;
    double fov;
    
}               t_camera;

typedef struct  s_lumiere
{
    double  x;
    double  y;
    double  z;
    double  rdlr;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    //typedef struct s_lumiere *next;
}               t_lumiere;

typedef struct  s_sphere
{
    int  x;
    int  y;
    int  z;
    int  d;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    
}               t_sphere;

typedef struct  s_plane
{
    double  x;
    double  y;
    double  z;
    double vo_x;
    double vo_y;
    double vo_z;
    unsigned int r;
    unsigned int g;
    unsigned int b;
}               t_plane;

typedef struct  s_square
{
    double  x;
    double  y;
    double  z;
    double vo_x;
    double vo_y;
    double vo_z;
    double h;
    unsigned int r;
    unsigned int g;
    unsigned int b;
}               t_square;

typedef struct  s_cylindre
{
    double  x;
    double  y;
    double  z;
    double vo_x;
    double vo_y;
    double vo_z;
    double dmt;
    double h;
    unsigned int r;
    unsigned int g;
    unsigned int b;
}               t_cylindre;

typedef struct  s_triangle
{
    double  p1_x;
    double  p1_y;
    double  p1_z;
    double  p2_x;
    double  p2_y;
    double  p2_z;
    double  p3_x;
    double  p3_y;
    double  p3_z;
    unsigned int r;
    unsigned int g;
    unsigned int b;
    
}               t_triangle;

int             g_y;
t_resolution    g_reso;
t_la            g_la;
t_camera        g_camera;
t_lumiere       g_lumiere;
t_sphere        g_sphere;
t_plane         g_plane;
t_square        g_square;
t_cylindre      g_cylindre;
t_triangle      g_triangle;

int ft_parse(int argc, char **argv);

# endif