/*
** texture.c for RT in /home/nguye_1//projects/igraph/raytracer-2017-nguye_1
**
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
**
** Started on  Tue Jun  4 14:42:01 2013 alexandre1 nguyen
** Last update Sun Jun  9 16:32:37 2013 noel dovan
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <mlx.h>
#include "raytracer.h"

t_obj	*put_texture_data(t_obj *obj, void *mlx_ptr)
{
  int	bpp;
  int	size_line;
  int	endian;
  int	texture_width;
  int	texture_height;
  char	*data;

  obj->texture.texture_ptr =
    mlx_xpm_file_to_image(mlx_ptr, obj->texture.texture_name,
			  &texture_width, &texture_height);
  obj->texture.width = texture_width;
  obj->texture.height = texture_height;
  if (!(data = mlx_get_data_addr(obj->texture.texture_ptr, &bpp, &size_line,
				 &endian)))
    return (NULL);
  obj->texture.sizeline_bpp[0] = size_line;
  obj->texture.sizeline_bpp[1] = bpp;
  obj->texture.data = data;
  return (obj);
}

int	texture_load(t_scene *scene, void *mlx_ptr)
{
  int	texture_width;
  int	texture_height;
  t_obj	*obj;

  obj = scene->obj;
  while (obj)
    {
      if (obj->texture.texture_name)
	{
	  if (!mlx_xpm_file_to_image(mlx_ptr, obj->texture.texture_name,
				     &texture_width, &texture_height))
	    {
	      printf("[failed] %s\n", obj->texture.texture_name);
	      return (1);
	    }
	  else
	    {
	      if (!(obj = put_texture_data(obj, mlx_ptr)))
		return (1);
	      printf("[loaded] %s\n", obj->texture.texture_name);
	    }
	}
      obj = obj->next;
    }
  return (0);
}

int	get_color_from_img(int x, int y, char *data, int sizeline_bpp[2])
{
  int	index;
  int	color;
  char	*clr;

  clr =(char *)&color;
  color = 0;
  index = sizeline_bpp[0] * ABS(y) + (sizeline_bpp[1] / 8) * ABS(x);
  clr[2] = data[index + 2];
  clr[1] = data[index + 1];
  clr[0] = data[index];
  return (color);
}
