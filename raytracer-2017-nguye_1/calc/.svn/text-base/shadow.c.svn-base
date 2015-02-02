/*
** shadow.c for raytracer in /home/guedj_m//project/igraph/test
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Tue Jun  4 10:50:17 2013 maxime guedj
** Last update Sun Jun  9 16:35:14 2013 noel dovan
*/

#include <stdio.h>
#include "raytracer.h"
#include "object.h"
#include "calc.h"
#include "utils.h"

static t_ptr_func	func[4] = {&obj_sphere, &obj_cylinder,
			   &obj_plane, &obj_cone};

int		check_limit(t_point *eye, t_point *vect, t_obj *obj)
{
  double	p[3];

  if (obj->k[0] == -1)
    return (0);
  p[0] = eye->x + vect->x * obj->k[0];
  p[1] = eye->y + vect->y * obj->k[0];
  p[2] = eye->z + vect->z * obj->k[0];
  if ((obj->limit && obj->limit->x != 0 &&
       (p[2] > obj->limit->x || p[2] < (obj->limit->x * (-1)))) ||
      (obj->limit && obj->limit->y != 0 &&
       (p[2] > obj->limit->y || p[2] < (obj->limit->y * (-1)))) ||
      (obj->limit && obj->limit->z != 0 &&
       (p[2] > obj->limit->z || p[2] < (obj->limit->z * (-1)))))
    {
      obj->k[0] = obj->k[1];
      obj->k[1] = -1;
      return (check_limit(eye, vect, obj));
    }
  else
    return (1);
}

int		check_shadow(t_scene *scene, t_obj *n_obj, t_point *vlight,
			     t_obj *tmp)
{
  t_point	*eye_pos;
  t_point	*vect;
  t_point	*n_tmp_pos;

  tmp = scene->obj;
  vect = dup_point(vlight);
  eye_pos = dup_point(n_obj->inter);
  n_tmp_pos = creat_point(0, 0, 0);
  while (tmp)
    {
      if (tmp != n_obj)
	{
	  reset_tmp(n_tmp_pos, tmp, n_obj);
	  double_rot(vect, n_obj, tmp);
	  set_new_eye_n(eye_pos, n_obj, tmp, n_tmp_pos);
	  (*func[tmp->type])(eye_pos, vect, tmp);
	  if (tmp->k[0] < 1 && tmp->k[0] > 0.00000001 &&
	      check_limit(eye_pos, vect, tmp))
	    return (return_n_free(1, n_tmp_pos, eye_pos, vect));
	  cpy_point(vlight, vect);
	  cpy_point(n_obj->inter, eye_pos);
	}
      tmp = tmp->next;
    }
  return (return_n_free(0, n_tmp_pos, eye_pos, vect));
}

void		reset_tmp(t_point *tmp, t_obj *o_tmp, t_obj *n_obj)
{
  cpy_point(o_tmp->pos, tmp);
  tmp->x -= n_obj->pos->x;
  tmp->y -= n_obj->pos->y;
  tmp->z -= n_obj->pos->z;
  m_i_rot_mult(tmp, n_obj);
}

void		double_rot(t_point *dest, t_obj *n_obj, t_obj *tmp)
{
  m_n_rot_mult(dest, n_obj);
  m_i_rot_mult(dest, tmp);
}

int		return_n_free(int ret, t_point *p1, t_point *p2, t_point *p3)
{
  free_point(p1);
  free_point(p2);
  free_point(p3);
  return (ret);
}
