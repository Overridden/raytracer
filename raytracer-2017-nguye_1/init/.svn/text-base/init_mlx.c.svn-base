/*
** init_mlx.c for raytracer in /home/jausse_c//projet/igraph/raytracer-2017-nguye_1/init
**
** Made by clement jausselme
** Login   <jausse_c@epitech.net>
**
** Started on  Mon May 27 15:02:48 2013 clement jausselme
** Last update Fri Jun  7 15:54:46 2013 noel dovan
*/

#include <mlx.h>
#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"
#include "init.h"

t_mlx		*init_mlx()
{
  t_mlx		*mlx;

  if (!(mlx = malloc(sizeof(*mlx))))
    return (NULL);
  mlx->width = WINDOW_WIDTH;
  mlx->height = WINDOW_HEIGHT;
  if (!(mlx->mlx_ptr = mlx_init()))
    return (NULL);
  if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
				      mlx->width, mlx->height, WINDOW_NAME)))
    return (NULL);
  if (!(mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height)))
    return (NULL);
  mlx->data = mlx_get_data_addr(mlx->img, &(mlx->bpp),
				&(mlx->line_len), &(mlx->endian));
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
  mlx_expose_hook(mlx->win_ptr, gere_expose, mlx);
  return (mlx);
}

