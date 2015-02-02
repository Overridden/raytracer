/*
** main.c for raytracer in /home/guedj_m//project/igraph/raytracer-2017-nguye_1
**
** Made by maxime guedj
** Login   <guedj_m@epitech.net>
**
** Started on  Mon May 27 16:31:18 2013 maxime guedj
** Last update Sun Jun  9 16:41:56 2013 noel dovan
*/

#include <stdlib.h>
#include <string.h>
#include <mlx.h>
#include <stdio.h>
#include "raytracer.h"
#include "init.h"
#include "utils.h"
#include "object.h"

int		main(int ac, char **av)
{
  t_scene	*scene[4];

  if (ac != 2)
    return (1);
  if ((scene[0] = main_parser(av[1])) == NULL || ac < 2)
    return (0);
  if (!scene[0]->obj || !scene[0]->light)
    return (1);
  scene[0]->mlx = init_mlx();
  memset(scene[0]->mlx->pixel, 0, WINDOW_HEIGHT * WINDOW_WIDTH);
  if (texture_load(scene[0], scene[0]->mlx->mlx_ptr) == 1)
    return (1);
  if ((scene[1] = scene_dup(scene[0])) == NULL ||
      (scene[2] = scene_dup(scene[0])) == NULL ||
      (scene[3] = scene_dup(scene[0])) == NULL)
    return (1);
  if (init_threads(scene) == 1)
    return (1);
  mlx_key_hook(scene[0]->mlx->win_ptr, gere_key, scene);
  mlx_loop(scene[0]->mlx->mlx_ptr);
  return (0);
}
