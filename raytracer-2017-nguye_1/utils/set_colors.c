/*
** set_colors.c for raytracer in /home/jausse_c//projet/igraph/raytracer-2017-nguye_1/utils
**
** Made by clement jausselme
** Login   <jausse_c@epitech.net>
**
** Started on  Tue May 28 16:26:04 2013 clement jausselme
** Last update Tue Jun  4 16:46:30 2013 maxime guedj
*/

#include <stdio.h>
#include "raytracer.h"
#include "utils.h"

int		set_color(unsigned int color, t_mlx *mlx, int x, int y)
{
  unsigned char	*clr;
  int		i;
  int		index;

  i = 0;
  index = (mlx->width * y + x) * 4;
  clr = (unsigned char *)&color;
  while (i < 4)
    mlx->data[index++] = clr[i++];
  return (0);
}
