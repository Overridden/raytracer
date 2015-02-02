/*
** get_next_line.c for GNL in /home/cerini_j//current_project/minishell1-2017-cerini_j
**
** Made by jeremy cerini
** Login   <cerini_j@epitech.net>
**
** Started on  Mon Dec 17 11:01:11 2012 jeremy cerini
** Last update Fri Jun  7 09:54:14 2013 maxime guedj
*/

#include <stdlib.h>
#include <unistd.h>
#include "raytracer.h"
#include "lib.h"

char		*init_buff(char *buff, int *i, int *size_read, const int fd)
{
  if (fd == -1)
    {
      buff = NULL;
      *i = 0;
      *size_read = 0;
      return (NULL);
    }
  if (fd == -2)
    {
      free(buff);
      buff = NULL;
      return (NULL);
    }
  if (buff == NULL)
    {
      *i = 0;
      buff = malloc(sizeof(*buff) * (BUFF + 1));
      if (buff == NULL)
	return (NULL);
      buff = my_clear(buff, BUFF + 1);
      *size_read = read(fd, buff, BUFF);
    }
  return (buff);
}

char		*init_other(int *pos, int *size_all, int size_read)
{
  char		*str;

  str = malloc(sizeof(*str) * (BUFF + 1));
  if (str == NULL || size_read == 0)
    return (NULL);
  my_clear(str, BUFF + 1);
  *pos = 0;
  *size_all = 1;
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	*buff;
  static int	i;
  static int	size_read;
  t_gnl		all;

  if ((buff = init_buff(buff, &i, &size_read, fd)) == NULL ||
      (all.str = init_other(&(all.pos), &(all.size_all),  size_read)) == NULL)
    return (NULL);
  while (all.str != NULL && buff[i] != '\n' && size_read != 0)
    {
      if (i >= size_read && (i = 0) == 0)
	{
	  all.str = my_realloc(all.str, ++(all.size_all) * (BUFF + 1));
	  buff = my_clear(buff, BUFF + 1);
	  if (all.str == NULL || (size_read = read(fd, buff, BUFF)) < 0)
	    return (NULL);
	  else if (size_read == 0)
	    return (all.str);
	}
      if (check_to_ret(all, buff, &i) == 1)
	return (all.str);
      all.str[++(all.pos)] = 0;
    }
  i++;
  return (all.str);
}
