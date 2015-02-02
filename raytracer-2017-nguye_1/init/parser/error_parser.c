/*
** error_parser.c for  in /home/lastru_g//svn/raytracer-2017-nguye_1/parser
** 
** Made by gael lastrucci
** Login   <lastru_g@epitech.net>
** 
** Started on  Wed May 29 13:37:14 2013 gael lastrucci
** Last update Wed May 29 17:56:07 2013 gael lastrucci
*/

#include <unistd.h>

int		error_eyes(int i)
{
  char		str[] = "just right one eye!!!\n\0";
  char		str1[] = "it must be one eye\n\0";

  if (i == 0)
    write(2, str1, 20);
  else
    write(2, str, 23);
  return (0);
}
