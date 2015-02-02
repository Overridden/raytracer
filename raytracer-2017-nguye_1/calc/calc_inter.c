/*
** distance.c for distance in /home/dovan_n//svn/raytracer-2017-nguye_1/inter
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Tue May 28 16:39:59 2013 noel dovan
** Last update Sun Jun  9 15:50:02 2013 noel dovan
*/

#include <stdio.h>
#include "raytracer.h"
#include "utils.h"
#include "calc.h"
#include "object.h"

static t_ptr_func	func[4] = {&obj_sphere, &obj_cylinder,
			   &obj_plane, &obj_cone};

t_obj		*get_the_nearest(t_obj *obj)
{
  t_obj		*tmp;
  t_obj		*nearest;

  tmp = obj;
  nearest = NULL;
  while (tmp)
    {
      if (tmp->k[0] > 0 && (nearest == NULL || nearest->k[0] > tmp->k[0]))
	{
	  if (nearest != NULL)
	    free_point(nearest->inter);
	  nearest = tmp;
	}
      else
	free_point(tmp->inter);
      tmp = tmp->next;
    }
  return (nearest);
}

void		get_the_distance(t_scene *scene, t_point *init_vect)
{
  t_obj		*tmp;
  t_point	*eye_pos;
  t_point	*vect;

  tmp = scene->obj;
  vect = dup_point(init_vect);
  eye_pos = dup_point(scene->eye->pos);
  while (tmp)
    {
      m_i_rot_mult(vect, tmp);
      set_new_eye(eye_pos, tmp, tmp->pos);
      (*func[tmp->type])(eye_pos, vect, tmp);
      set_inter_point(eye_pos, tmp, vect);
      cpy_point(init_vect, vect);
      cpy_point(scene->eye->pos, eye_pos);
      tmp = tmp->next;
    }
  free_point(eye_pos);
  free_point(vect);
}

void		set_inter_point(t_point *eye, t_obj *obj, t_point *vect)
{
  obj->inter = creat_point(0, 0, 0);
  if (obj->inter == NULL)
    return ;
  obj->inter->x = eye->x + vect->x * obj->k[0];
  obj->inter->y = eye->y + vect->y * obj->k[0];
  obj->inter->z = eye->z + vect->z * obj->k[0];
  if (obj->limit == NULL || obj->k[0] == -1)
    return ;
  if ((obj->limit->x != 0 && (obj->inter->x > obj->limit->x ||
			      obj->inter->x < (obj->limit->x * -1))) ||
      (obj->limit->y != 0 && (obj->inter->y > obj->limit->y ||
			      obj->inter->y < (obj->limit->y * -1))) ||
      (obj->limit->z != 0 && (obj->inter->z > obj->limit->z ||
			      obj->inter->z < (obj->limit->z * -1))))
    {
      free_point(obj->inter);
      obj->k[0] = obj->k[1];
      obj->k[1] = -1;
      set_inter_point(eye, obj, vect);
    }
}

t_obj		*find_the_object(t_scene *scene, double x, double y)
{
  t_obj		*obj;
  t_point	*init_vect;

  init_vect = get_init_vect(x, y);
  m_i_rot_mult(init_vect, scene->eye);
  get_the_distance(scene, init_vect);
  obj = get_the_nearest(scene->obj);
  free_point(init_vect);
  return (obj);
}
