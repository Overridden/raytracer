/*
** multithread.c for multithread in /home/dovan_n//svn/raytracer-2017-nguye_1
** 
** Made by noel dovan
** Login   <dovan_n@epitech.net>
** 
** Started on  Fri Jun  7 11:24:17 2013 noel dovan
** Last update Fri Jun  7 15:51:23 2013 noel dovan
*/

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "raytracer.h"
#include "calc.h"
#include "utils.h"
#include "lib.h"

static pthread_mutex_t	my_mutex;

int		init_threads(t_scene *scene[4])
{
  pthread_t	thread[4];

  if (pthread_mutex_init(&my_mutex, NULL) != 0 ||
      pthread_create(&thread[0], NULL, &color_img, (void *)scene[0]) != 0 ||
      pthread_create(&thread[1], NULL, &color_img, (void *)scene[1]) != 0 ||
      pthread_create(&thread[2], NULL, &color_img, (void *)scene[2]) != 0 ||
      pthread_create(&thread[3], NULL, &color_img, (void *)scene[3]) != 0 ||
      pthread_join(thread[0], NULL) != 0 ||
      pthread_join(thread[1], NULL) != 0 ||
      pthread_join(thread[2], NULL) != 0 ||
      pthread_join(thread[3], NULL) != 0 ||
      pthread_mutex_destroy(&my_mutex) != 0)
    return (1);
  return (0);
}

void		*color_img(void *arg)
{
  t_scene	*scene;
  int		x;
  int		y;

  scene = (t_scene *)arg;
  y = -1;
  while (++y < WINDOW_HEIGHT)
    {
      x = -1;
      while (++x < WINDOW_WIDTH)
	if (get_pixel_and_set_color(scene, x, y) == 1)
	  return (NULL);
    }
  if (my_putstr("100%\r") == -1)
    return (NULL);
  pthread_exit(NULL);
  return (scene);
}

int		get_pixel_and_set_color(t_scene *scene, int x, int y)
{
  int		color;

  if (pthread_mutex_lock(&my_mutex) != 0)
    return (1);
  if (scene->mlx->pixel[y][x] == 0)
    {
      if (y % (WINDOW_HEIGHT / 5) == 0)
	{
	  if (my_putnbr(y / (WINDOW_HEIGHT / 100)) == -1 ||
	      my_putstr("%\r") == -1)
	    return (1);
	}
      scene->mlx->pixel[y][x] = 1;
      if (pthread_mutex_unlock(&my_mutex) != 0)
	return (1);
      color = get_clean_pixel(scene, (double)x, (double)y);
      set_color(color, scene->mlx, x, y);
    }
  else
    if (pthread_mutex_unlock(&my_mutex) != 0)
      return (1);
  return (0);
}
