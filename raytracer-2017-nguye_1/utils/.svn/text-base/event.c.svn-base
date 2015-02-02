/*
** gere_expose.c for raytracer in /home/jausse_c//projet/igraph/raytracer-2017-nguye_1/utils
** 
** Made by clement jausselme
** Login   <jausse_c@epitech.net>
** 
** Started on  Tue May 28 13:44:13 2013 clement jausselme
** Last update Fri Jun  7 16:23:53 2013 noel dovan
*/

#include <mlx.h>
#include <stdlib.h>
#include "raytracer.h"
#include "utils.h"

int		gere_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
  return (0);
}

int		gere_key(int key, t_scene **scene)
{
  scene = scene;
  if (key == ESC)
    exit(0);
  return (0);
}
