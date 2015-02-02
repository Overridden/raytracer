/*
** color.c for color in /home/dovan_n//svn/raytracer-2017-nguye_1/calc
**
** Made by noel dovan
** Login   <dovan_n@epitech.net>
**
** Started on  Mon Jun  3 17:12:04 2013 noel dovan
** Last update Wed Jun  5 13:55:10 2013 noel dovan
*/

#include "raytracer.h"
#include "utils.h"

void		get_rgb(unsigned int color, int *dest)
{
  unsigned char	*rgb;

  rgb = (unsigned char*)(&color);
  dest[0] = rgb[0];
  dest[1] = rgb[1];
  dest[2] = rgb[2];
}

void		add_color(int *dest, int *rgb, double coef)
{
  dest[0] += (rgb[0] * coef);
  dest[1] += (rgb[1] * coef);
  dest[2] += (rgb[2] * coef);
}

void		mult_color(int *dest, double coef)
{
  dest[0] *= coef;
  dest[1] *= coef;
  dest[2] *= coef;
}

void		div_color(int *dest, int i)
{
  if (i != 0)
    {
      dest[0] = dest[0] / i;
      dest[1] = dest[1] / i;
      dest[2] = dest[2] / i;
    }
}

unsigned int	c_color(int *rbg)
{
  unsigned int	color;

  color = rbg[2] * 256 * 256;
  color += rbg[1] * 256;
  color += rbg[0];
  return (color);
}
