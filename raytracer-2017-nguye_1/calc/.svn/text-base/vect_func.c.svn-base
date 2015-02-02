/*
** get_dir_vector.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1/calc
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Tue May 28 12:08:25 2013 maxime guedj
** Last update Fri Jun  7 11:02:01 2013 maxime guedj
*/

#include <math.h>
#include "raytracer.h"
#include "utils.h"

t_point		*get_init_vect(double x, double y)
{
  double	n_x;
  double	n_y;
  double	n_z;
  double	pre_calc;

  pre_calc = cos(((- WINDOW_HEIGHT / 2) + y) /
  		 40 * M_PI / 180);

  n_z = - sin((((- WINDOW_HEIGHT / 2) + y) /
	       WINDOW_HEIGHT * (WINDOW_HEIGHT * 0.05)) *
  	    M_PI / 180);
  n_x = pre_calc * cos(((- WINDOW_WIDTH / 2) + x) /
		       WINDOW_WIDTH * (WINDOW_WIDTH * 0.05) *
  		       M_PI / 180);
  n_y = pre_calc * sin(((- WINDOW_WIDTH / 2) + x) /
		       WINDOW_WIDTH * (WINDOW_WIDTH * 0.05) *
		       M_PI / 180);
  return (creat_point(n_x, n_y, n_z));
}

void		m_i_rot_mult(t_point *vect, t_obj *obj)
{
  double	x;
  double	y;
  double	z;

  x = obj->i_rot[0][0] * vect->x;
  x += obj->i_rot[1][0] * vect->y;
  x += obj->i_rot[2][0] * vect->z;
  y = obj->i_rot[0][1] * vect->x;
  y += obj->i_rot[1][1] * vect->y;
  y += obj->i_rot[2][1] * vect->z;
  z = obj->i_rot[0][2] * vect->x;
  z += obj->i_rot[1][2] * vect->y;
  z += obj->i_rot[2][2] * vect->z;
  vect->x = x;
  vect->y = y;
  vect->z = z;
}

void		m_n_rot_mult(t_point *vect, t_obj *obj)
{
  double	x;
  double	y;
  double	z;

  x = obj->n_rot[0][0] * vect->x;
  x += obj->n_rot[1][0] * vect->y;
  x += obj->n_rot[2][0] * vect->z;
  y = obj->n_rot[0][1] * vect->x;
  y += obj->n_rot[1][1] * vect->y;
  y += obj->n_rot[2][1] * vect->z;
  z = obj->n_rot[0][2] * vect->x;
  z += obj->n_rot[1][2] * vect->y;
  z += obj->n_rot[2][2] * vect->z;
  vect->x = x;
  vect->y = y;
  vect->z = z;
}

t_point		*c_n_rot_mult(t_point *vect, t_obj *obj)
{
  double	x;
  double	y;
  double	z;

  x = obj->n_rot[0][0] * vect->x;
  x += obj->n_rot[1][0] * vect->y;
  x += obj->n_rot[2][0] * vect->z;
  y = obj->n_rot[0][1] * vect->x;
  y += obj->n_rot[1][1] * vect->y;
  y += obj->n_rot[2][1] * vect->z;
  z = obj->n_rot[0][2] * vect->x;
  z += obj->n_rot[1][2] * vect->y;
  z += obj->n_rot[2][2] * vect->z;
  return (creat_point(x, y, z));
}

t_point		*c_i_rot_mult(t_point *vect, t_obj *obj)
{
  double	x;
  double	y;
  double	z;

  x = obj->i_rot[0][0] * vect->x;
  x += obj->i_rot[1][0] * vect->y;
  x += obj->i_rot[2][0] * vect->z;
  y = obj->i_rot[0][1] * vect->x;
  y += obj->i_rot[1][1] * vect->y;
  y += obj->i_rot[2][1] * vect->z;
  z = obj->i_rot[0][2] * vect->x;
  z += obj->i_rot[1][2] * vect->y;
  z += obj->i_rot[2][2] * vect->z;
  return (creat_point(x, y, z));
}
